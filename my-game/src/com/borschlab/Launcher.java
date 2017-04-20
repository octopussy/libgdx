package com.borschlab;

import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputAdapter;
import com.badlogic.gdx.InputMultiplexer;
import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.imgui.ImGui;
import com.badlogic.gdx.imgui.ImStage;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.utils.SharedLibraryLoader;

/**
 * @author mcpussy
 * @date 20/04/2017
 */
public class Launcher implements ApplicationListener {

	private InputAdapter stage = new InputAdapter() {
		@Override
		public boolean touchDown(int screenX, int screenY, int pointer, int button) {
			Gdx.app.log("back input", "touchDown");
			return super.touchDown(screenX, screenY, pointer, button);
		}
	};
	private ImStage imStage;

	private Texture fontTexture;

	public static void main(String[] args) {
		//new SharedLibraryLoader("extensions/gdx-freetype/libs/gdx-freetype-natives.jar").load("gdx-freetype");
		new SharedLibraryLoader("gdx/libs/gdx-natives.jar").load("gdx");
		new SharedLibraryLoader("extensions/gdx-imgui/libs/gdx-imgui-natives.jar").load("gdx-imgui");
		// new SharedLibraryLoader("backends/gdx-backend-lwjgl3/libs/lwjgl-natives-macos.jar").load("gdx-lwjgl");

		//Lwjgl3ApplicationConfiguration conf = new Lwjgl3ApplicationConfiguration();
		//conf.setWindowedMode(600, 500);
		LwjglApplication app = new LwjglApplication(new Launcher(), "123", 800, 600);
	}

	@Override
	public void create() {
		//stage = new Stage();
		imStage = new ImStage();

		Gdx.input.setInputProcessor(new InputMultiplexer(imStage, stage));
	}

	@Override
	public void resize(int width, int height) {
		imStage.resize(width, height);
	}

	@Override
	public void render() {
		float deltaTime = Gdx.graphics.getDeltaTime();

		//stage.act(deltaTime);

		imStage.act(deltaTime, new Runnable() {
			@Override
			public void run() {
				ImGui.showUserGuide();
				ImGui.showTestWindow();
			}
		});

		imStage.draw();
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
