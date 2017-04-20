package com.badlogic.gdx.imgui;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.InputAdapter;
import com.badlogic.gdx.graphics.*;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.glutils.ShaderProgram;
import com.badlogic.gdx.math.Matrix4;
import com.badlogic.gdx.utils.BufferUtils;
import com.badlogic.gdx.utils.Disposable;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.IntBuffer;

/**
 * @author mcpussy
 */
public class ImStage extends InputAdapter implements Disposable {

	private ShaderProgram shader;

	private Texture fontTexture;

	private Mesh mesh;

	private float[] vertices;
	private short[] indices;

	private int width;
	private int height;

	public ImStage() {
		shader = SpriteBatch.createDefaultShader();

		mapKeys();
		prepareFontTexture();

		int size = 8000;
		vertices = new float[4000];
		indices = new short[4000];

		mesh = new Mesh(Mesh.VertexDataType.VertexArray, false, size * 4, size * 6,
			new VertexAttribute(VertexAttributes.Usage.Position, 2, ShaderProgram.POSITION_ATTRIBUTE),
			new VertexAttribute(VertexAttributes.Usage.TextureCoordinates, 2, ShaderProgram.TEXCOORD_ATTRIBUTE + "0"),
			new VertexAttribute(VertexAttributes.Usage.ColorPacked, 4, ShaderProgram.COLOR_ATTRIBUTE));
	}

	private void prepareFontTexture() {
		ImGuiTexData data = ImGui.getTexDataAsRGBA32();
		Pixmap pm = new Pixmap(data.width, data.height, Pixmap.Format.RGBA8888);
		BufferUtils.copy(data.data, 0, pm.getPixels(), data.data.length);
		fontTexture = new Texture(pm);
	}

	@Override
	public void dispose() {
		ImGui.shutdown();

		if (shader != null) shader.dispose();
		if (fontTexture != null) fontTexture.dispose();
		if (mesh != null) mesh.dispose();

		shader = null;
		fontTexture = null;
		mesh = null;
	}

	public void resize(int width, int height) {
		this.width = width;
		this.height = height;
	}

	public void act(float delta, Runnable drawUiCallback) {
		ImGui.setDisplaySize(width, height);
		ImGui.setDeltaTime(delta);
		//ImGui.setMousePos(Gdx.input.getX(), Gdx.input.getY());

		ImGui.setMouseDown(0, Gdx.input.isButtonPressed(0));
		ImGui.setMouseDown(1, Gdx.input.isButtonPressed(1));
		//ImGui.setMouseWheel(Gdx.input.w);

		ImGui.newFrame();

		drawUiCallback.run();
	}

	public void draw() {
		ImGui.render();

		Gdx.gl20.glClearColor(0.2f, 0.2f, 0.2f, 1);
		Gdx.gl20.glClear(GL20.GL_COLOR_BUFFER_BIT);
		Gdx.gl20.glEnable(GL20.GL_TEXTURE_2D);
		Gdx.gl20.glEnable(GL20.GL_BLEND);

		drawImBuffers();
	}

	private void drawImBuffers() {
		// prepare
		// Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
	/*	ImGuiIO& io = ImGui::GetIO();
		int fb_width = (int)(io.DisplaySize.x * io.DisplayFramebufferScale.x);
		int fb_height = (int)(io.DisplaySize.y * io.DisplayFramebufferScale.y);
		if (fb_width == 0 || fb_height == 0)
			return;
		draw_data->ScaleClipRects(io.DisplayFramebufferScale);*/

		int fb_width = Gdx.graphics.getWidth();
		int fb_height = Gdx.graphics.getHeight();

		IntBuffer last_scissor_box = ByteBuffer.allocateDirect(16 * Integer.SIZE / 8).order(ByteOrder.nativeOrder()).asIntBuffer();
		Gdx.gl20.glGetIntegerv(GL20.GL_SCISSOR_BOX, last_scissor_box);

		Gdx.gl20.glEnable(GL20.GL_BLEND);
		Gdx.gl20.glBlendFunc(GL20.GL_SRC_ALPHA, GL20.GL_ONE_MINUS_SRC_ALPHA);
		Gdx.gl20.glDisable(GL20.GL_CULL_FACE);
		Gdx.gl20.glDisable(GL20.GL_DEPTH_TEST);
		Gdx.gl20.glEnable(GL20.GL_SCISSOR_TEST);
		Gdx.gl20.glEnable(GL20.GL_TEXTURE_2D);
		Gdx.gl20.glViewport(0, 0, fb_width, fb_height);

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
			projectionMatrix.setToOrtho(0, fb_width, fb_height, 0, -1, 1);
			shader.setUniformMatrix("u_projTrans", projectionMatrix);
			shader.setUniformi("u_texture", 0);
			fontTexture.bind();

			int offset = 0;
			for (int cmd_i = 0; cmd_i < drawList.cmdBuffer.length; ++cmd_i) {
				ImGuiDrawCmd cmd = drawList.cmdBuffer[cmd_i];

				if (/*pcmd->UserCallback*/false) {
					//pcmd->UserCallback(cmd_list, pcmd);
				} else {
					//Gdx.gl20.glBindTexture(GL20.GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
					Gdx.gl20.glScissor(
						(int) cmd.clipRectX,
						(int) (fb_height - cmd.clipRectH),
						(int) (cmd.clipRectW - cmd.clipRectX),
						(int) (cmd.clipRectH - cmd.clipRectY));

					mesh.render(shader, GL20.GL_TRIANGLES, offset, cmd.elemCount);
				}

				offset += cmd.elemCount;
			}
		}

		shader.end();

		Gdx.gl20.glDisable(GL20.GL_SCISSOR_TEST);
		Gdx.gl20.glScissor(
			last_scissor_box.get(0),
			last_scissor_box.get(1),
			last_scissor_box.get(2),
			last_scissor_box.get(3));
	}

	@Override
	public boolean scrolled(int amount) {
		if (ImGui.isMouseHoveringAnyWindow()) {
			ImGui.setMouseWheel(-amount);
			return true;
		}
		return false;
	}

	@Override
	public boolean keyTyped(char character) {
		ImGui.addInputCharacter(character);
		return false;
	}

	@Override
	public boolean keyDown(int keycode) {
		ImGui.setKeyDown(keycode, true);
		updateKeyModifiers();
		return false;
	}

	@Override
	public boolean keyUp(int keycode) {
		ImGui.setKeyDown(keycode, false);
		updateKeyModifiers();
		return false;
	}

	@Override
	public boolean mouseMoved(int screenX, int screenY) {
		ImGui.setMousePos(screenX, screenY);
		return ImGui.isMouseHoveringAnyWindow();
	}

	@Override
	public boolean touchDown(int screenX, int screenY, int pointer, int button) {
		return ImGui.isMouseHoveringAnyWindow();
	}

	@Override
	public boolean touchDragged(int screenX, int screenY, int pointer) {
		ImGui.setMousePos(screenX, screenY);
		return ImGui.isMouseHoveringAnyWindow();
	}

	private void updateKeyModifiers() {
		ImGui.setKeyCtrl(ImGui.isKeysDown(Input.Keys.CONTROL_LEFT) || ImGui.isKeysDown(Input.Keys.CONTROL_RIGHT));
		ImGui.setKeyShift(ImGui.isKeysDown(Input.Keys.SHIFT_LEFT) || ImGui.isKeysDown(Input.Keys.SHIFT_RIGHT));
		ImGui.setKeyAlt(ImGui.isKeysDown(Input.Keys.ALT_LEFT) || ImGui.isKeysDown(Input.Keys.ALT_RIGHT));
		//ImGui.setKeySuper(ImGui.isKeysDown(GLFW_KEY_LEFT_SUPER) || ImGui.isKeysDown(Input.Keys.§));
	}

	private void mapKeys() {
		for (ImGuiKey k: ImGuiKey.values()) {
			ImGui.setKeyMap(k.imKey, k.gdxKey);
		}
	}
}
