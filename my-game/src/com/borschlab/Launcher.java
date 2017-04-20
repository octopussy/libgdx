package com.borschlab;

import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.graphics.*;
import com.badlogic.gdx.graphics.g2d.Batch;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.glutils.ShaderProgram;
import com.badlogic.gdx.imgui.ImGui;
import com.badlogic.gdx.imgui.ImGuiDrawCmd;
import com.badlogic.gdx.imgui.ImGuiDrawList;
import com.badlogic.gdx.imgui.ImGuiTexData;
import com.badlogic.gdx.math.Matrix4;
import com.badlogic.gdx.utils.BufferUtils;
import com.badlogic.gdx.utils.SharedLibraryLoader;

/**
 * @author mcpussy
 * @date 20/04/2017
 */
public class Launcher implements ApplicationListener {

	private Batch batch;
	private Texture fontTexture;
	private Mesh mesh;

	private ShaderProgram shader;
	private float[] vertices;
	private short[] indices;

	public static void main(String[] args) {
		//new SharedLibraryLoader("extensions/gdx-freetype/libs/gdx-freetype-natives.jar").load("gdx-freetype");
		new SharedLibraryLoader("gdx/libs/gdx-natives.jar").load("gdx");
		new SharedLibraryLoader("extensions/gdx-imgui/libs/gdx-imgui-natives.jar").load("gdx-imgui");
		// new SharedLibraryLoader("backends/gdx-backend-lwjgl3/libs/lwjgl-natives-macos.jar").load("gdx-lwjgl");

		System.out.println(ImGui.getDeltaTime());

		//Lwjgl3ApplicationConfiguration conf = new Lwjgl3ApplicationConfiguration();
		//conf.setWindowedMode(600, 500);
		LwjglApplication app = new LwjglApplication(new Launcher(), "123", 800, 600);
	}

	@Override
	public void create() {

		shader = SpriteBatch.createDefaultShader();

		batch = new SpriteBatch();
		ImGuiTexData data = ImGui.getTexDataAsRGBA32();

		//	fontTexture = new Texture(Gdx.files.internal("my-game/res/img.png"));
		Pixmap pm = new Pixmap(data.width, data.height, Pixmap.Format.RGBA8888);

		BufferUtils.copy(data.data, 0, pm.getPixels(), data.data.length);
		fontTexture = new Texture(pm);

		// 32767 is max vertex index, so 32767 / 4 vertices per sprite = 8191 sprites max.
		int size = 8191;

		Mesh.VertexDataType vertexDataType = Mesh.VertexDataType.VertexArray;

		vertices = new float[4000];
		indices = new short[4000];
		mesh = new Mesh(vertexDataType, false, size * 4, size * 6,
			new VertexAttribute(VertexAttributes.Usage.Position, 2, ShaderProgram.POSITION_ATTRIBUTE),
			new VertexAttribute(VertexAttributes.Usage.TextureCoordinates, 2, ShaderProgram.TEXCOORD_ATTRIBUTE + "0"),
			new VertexAttribute(VertexAttributes.Usage.ColorPacked, 4, ShaderProgram.COLOR_ATTRIBUTE));
	}

	@Override
	public void resize(int width, int height) {

	}


	/*	// Application main loop
			  while (true)
		{
			// 1) get low-level inputs (e.g. on Win32, GetKeyboardState(), or poll your events, etc.)
			// TODO: fill all fields of IO structure and call NewFrame
			ImGuiIO& io = ImGui::GetIO();
			io.DeltaTime = 1.0f/60.0f;
			io.MousePos = mouse_pos;
			io.MouseDown[0] = mouse_button_0;
			io.MouseDown[1] = mouse_button_1;
			io.KeysDown[i] = ...

			// 2) call NewFrame(), after this point you can use ImGui::* functions anytime
			ImGui::NewFrame();

			// 3) most of your application code here
			MyGameUpdate(); // may use any ImGui functions, e.g. ImGui::Begin("My window"); ImGui::Text("Hello, world!"); ImGui::End();
			MyGameRender(); // may use any ImGui functions

			// 4) render & swap video buffers
			ImGui::Render();
			SwapBuffers();
		}*/
	@Override
	public void render() {
		float w = Gdx.graphics.getWidth();
		float h = Gdx.graphics.getHeight();

		ImGui.setDisplaySize(w, h);
		ImGui.setDeltaTime(Gdx.graphics.getDeltaTime());

		ImGui.newFrame();

		ImGui.showUserGuide();

		ImGui.render();

		Gdx.gl20.glClearColor(0.2f, 0.2f, 0.2f, 1);
		Gdx.gl20.glClear(GL20.GL_COLOR_BUFFER_BIT);
		Gdx.gl20.glEnable(GL20.GL_TEXTURE_2D);
		Gdx.gl20.glEnable(GL20.GL_BLEND);

		drawImGui();

		/*batch.begin();
		batch.draw(fontTexture, 10, 10);
		batch.end();*/
	}

	private void drawImGui() {
		// prepare
		// Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
	/*	ImGuiIO& io = ImGui::GetIO();
		int fb_width = (int)(io.DisplaySize.x * io.DisplayFramebufferScale.x);
		int fb_height = (int)(io.DisplaySize.y * io.DisplayFramebufferScale.y);
		if (fb_width == 0 || fb_height == 0)
			return;
		draw_data->ScaleClipRects(io.DisplayFramebufferScale);*/

		// We are using the OpenGL fixed pipeline to make the example code simpler to read!
		// Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, vertex/texcoord/color pointers.
		Gdx.gl20.glEnable(GL20.GL_BLEND);
		Gdx.gl20.glBlendFunc(GL20.GL_SRC_ALPHA, GL20.GL_ONE_MINUS_SRC_ALPHA);
		Gdx.gl20.glDisable(GL20.GL_CULL_FACE);
		Gdx.gl20.glDisable(GL20.GL_DEPTH_TEST);
		//Gdx.gl20.glEnable(GL20.GL_SCISSOR_TEST);
		Gdx.gl20.glEnable(GL20.GL_TEXTURE_2D);
		Gdx.gl20.glViewport(0, 0, Gdx.graphics.getWidth(), Gdx.graphics.getHeight());

		shader.begin();

		for (int cmd_list = 0; cmd_list < ImGui.getDrawListCount(); ++cmd_list) {

			ImGuiDrawList drawList = ImGui.getDrawList(cmd_list);

			int vtxDataSize = drawList.vtxCount * drawList.vtxElementSize;
			int idxDataSize = drawList.idxCount * drawList.idxElmentSize;
			if (vertices.length < vtxDataSize) {
				vertices = new float[vtxDataSize];
			}

			if (indices.length < idxDataSize) {
				indices = new short[idxDataSize];
			}

			ImGui.getVertBuffer(vertices, cmd_list);
			ImGui.getIndBuffer(indices, cmd_list);

			mesh.setVertices(vertices);
			mesh.setIndices(indices);


			Matrix4 projectionMatrix = new Matrix4();
			projectionMatrix.setToOrtho(0, Gdx.graphics.getWidth(), Gdx.graphics.getHeight(), 0, -1, 1);
			shader.setUniformMatrix("u_projTrans", projectionMatrix);
			shader.setUniformi("u_texture", 0);
			fontTexture.bind();

			int offset = 0;
			for (int cmd_i = 0; cmd_i < drawList.cmdBuffer.length; ++cmd_i) {
				ImGuiDrawCmd cmd = drawList.cmdBuffer[cmd_i];

				mesh.render(shader, GL20.GL_TRIANGLES, offset, cmd.elemCount);
				offset += cmd.elemCount;

				/* const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
				if (pcmd->UserCallback)
				{
					pcmd->UserCallback(cmd_list, pcmd);
				}
				else
				{
					glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
					glScissor((int)pcmd->ClipRect.x, (int)(fb_height - pcmd->ClipRect.w), (int)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));
					glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, idx_buffer);
				}
				idx_buffer += pcmd->ElemCount;*/

			}
		}

		shader.end();

		// Restore modified state
		/*Gdx.gl20.glDisableClientState(GL_COLOR_ARRAY);
		Gdx.gl20.glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		Gdx.gl20.glDisableClientState(GL_VERTEX_ARRAY);
		Gdx.gl20.glBindTexture(GL_TEXTURE_2D, (GLuint)last_texture);
		Gdx.gl20.glMatrixMode(GL_MODELVIEW);
		Gdx.gl20.glPopMatrix();
		Gdx.gl20.glMatrixMode(GL_PROJECTION);
		Gdx.gl20.glPopMatrix();
		Gdx.gl20.glPopAttrib();
		Gdx.gl20.glViewport(last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2], (GLsizei)last_viewport[3]);
		Gdx.gl20.glScissor(last_scissor_box[0], last_scissor_box[1], (GLsizei)last_scissor_box[2], (GLsizei)last_scissor_box[3]);*/
	}

	@Override
	public void pause() {

	}

	@Override
	public void resume() {

	}

	@Override
	public void dispose() {

	}
}
