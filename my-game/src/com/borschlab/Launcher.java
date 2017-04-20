package com.borschlab;

import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.graphics.*;
import com.badlogic.gdx.graphics.g2d.Batch;
import com.badlogic.gdx.graphics.g2d.Gdx2DPixmap;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.imgui.ImGui;
import com.badlogic.gdx.imgui.ImGuiTexData;
import com.badlogic.gdx.utils.BufferUtils;
import com.badlogic.gdx.utils.SharedLibraryLoader;

/**
 * @author mcpussy
 * @date 20/04/2017
 */
public class Launcher implements ApplicationListener {

	private Batch batch;
	private Texture fontTexture;

	public static void main(String[] args) {
		//new SharedLibraryLoader("extensions/gdx-freetype/libs/gdx-freetype-natives.jar").load("gdx-freetype");
		new SharedLibraryLoader("gdx/libs/gdx-natives.jar").load("gdx");
		new SharedLibraryLoader("extensions/gdx-imgui/libs/gdx-imgui-natives.jar").load("gdx-imgui");
		// new SharedLibraryLoader("backends/gdx-backend-lwjgl3/libs/lwjgl-natives-macos.jar").load("gdx-lwjgl");

		System.out.println(ImGui.getDeltaTime());

		//Lwjgl3ApplicationConfiguration conf = new Lwjgl3ApplicationConfiguration();
		//conf.setWindowedMode(600, 500);
		LwjglApplication app = new LwjglApplication(new Launcher(), "123", 600, 500);
	}

	@Override
	public void create() {
		batch = new SpriteBatch();
		ImGuiTexData data = ImGui.getTexDataAsRGBA32();

		//	fontTexture = new Texture(Gdx.files.internal("my-game/res/img.png"));
		Pixmap pm = new Pixmap(data.width, data.height, Pixmap.Format.RGBA8888);

		BufferUtils.copy(data.data, 0, pm.getPixels(), data.data.length);
		fontTexture = new Texture(pm);
	}

	@Override
	public void resize(int width, int height) {

	}

	@Override
	public void render() {
		float w = Gdx.graphics.getWidth();
		float h = Gdx.graphics.getHeight();
		ImGui.setDisplaySize(w, h);
		ImGui.setDeltaTime(Gdx.graphics.getDeltaTime());

		ImGui.newFrame();
		ImGui.render();

		Gdx.gl20.glClearColor(0.2f, 0.2f, 0.2f, 1);
		Gdx.gl20.glClear(GL20.GL_COLOR_BUFFER_BIT);
		Gdx.gl20.glEnable(GL20.GL_TEXTURE_2D);
		Gdx.gl20.glEnable(GL20.GL_BLEND);

		batch.begin();
		batch.draw(fontTexture, 10, 10);
		batch.end();
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
