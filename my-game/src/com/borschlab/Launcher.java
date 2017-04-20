package com.borschlab;

import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.imgui.Imgui;
import com.badlogic.gdx.utils.SharedLibraryLoader;

/**
 * @author mcpussy
 * @date 20/04/2017
 */
public class Launcher implements ApplicationListener {

	public static void main(String[] args) {
		//new SharedLibraryLoader("extensions/gdx-freetype/libs/gdx-freetype-natives.jar").load("gdx-freetype");
		new SharedLibraryLoader("gdx/libs/gdx-natives.jar").load("gdx");
		new SharedLibraryLoader("extensions/gdx-imgui/libs/gdx-imgui-natives.jar").load("gdx-imgui");
		// new SharedLibraryLoader("backends/gdx-backend-lwjgl3/libs/lwjgl-natives-macos.jar").load("gdx-lwjgl");

		System.out.println(Imgui.getLong() + " " + Imgui.getString(123));

		//Lwjgl3ApplicationConfiguration conf = new Lwjgl3ApplicationConfiguration();
		//conf.setWindowedMode(600, 500);
		LwjglApplication app = new LwjglApplication(new Launcher(), "123", 600, 500);
	}

	@Override
	public void create() {

	}

	@Override
	public void resize(int width, int height) {

	}

	@Override
	public void render() {

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
