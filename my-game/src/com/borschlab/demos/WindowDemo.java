package com.borschlab.demos;

import com.badlogic.gdx.imgui.ImGui;
import com.badlogic.gdx.imgui.ImGuiSetCond;
import com.badlogic.gdx.imgui.ImGuiWindowFlags;
import com.badlogic.gdx.imgui.ValueRef;
import com.borschlab.ImDemoApp;

/**
 * @author octopussy
 */
public class WindowDemo extends ImDemoApp {

	private ValueRef<Boolean> isClosableWindowOpen = new ValueRef<>(true);

	@Override
	public void renderGui() {

		ImGui.setNextWindowPos(10, 10, ImGuiSetCond.Always);
		ImGui.setNextWindowSize(100, 100, ImGuiSetCond.Once);
		ImGui.begin("Main", ImGuiWindowFlags.NoCollapse | ImGuiWindowFlags.ShowBorders);
		ImGui.end();

		if (isClosableWindowOpen.get()) {
			ImGui.setNextWindowPos(110, 10, ImGuiSetCond.Once);
			ImGui.setNextWindowSize(400, 400, ImGuiSetCond.Once);
			ImGui.begin("Closable", isClosableWindowOpen);
			ImGui.end();
		} else {
			ImGui.setWindowSize("Main", 200, 200);
		}
	}
}
