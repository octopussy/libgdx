package com.borschlab.demos;

import com.badlogic.gdx.imgui.ImGui;
import com.borschlab.ImDemoApp;

/**
 * @author mcpussy
 * @date 21/04/2017
 */
public class Demo01 extends ImDemoApp {

	@Override
	public void renderGui() {
		ImGui.showUserGuide();
		ImGui.showTestWindow();
	}
}
