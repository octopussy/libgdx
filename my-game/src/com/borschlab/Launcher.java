package com.borschlab;

import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.backends.lwjgl.LwjglApplicationConfiguration;
import com.badlogic.gdx.utils.SharedLibraryLoader;
import com.borschlab.demos.Demo01;
import com.borschlab.demos.WindowDemo;

/**
 * @author mcpussy
 * @date 20/04/2017
 */
public class Launcher {

	public static void main(String[] args) {
		//new SharedLibraryLoader("extensions/gdx-freetype/libs/gdx-freetype-natives.jar").load("gdx-freetype");
		new SharedLibraryLoader("gdx/libs/gdx-natives.jar").load("gdx");
		new SharedLibraryLoader("extensions/gdx-imgui/libs/gdx-imgui-natives.jar").load("gdx-imgui");
		// new SharedLibraryLoader("backends/gdx-backend-lwjgl3/libs/lwjgl-natives-macos.jar").load("gdx-lwjgl");

		LwjglApplicationConfiguration cfg = new LwjglApplicationConfiguration();
		cfg.width = 1024;
		cfg.height = 768;
		cfg.title = "Dear Gdx ImGui";

		LwjglApplication app = new LwjglApplication(new WindowDemo(), cfg);
	}
}
