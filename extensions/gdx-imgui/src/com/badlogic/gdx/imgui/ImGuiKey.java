package com.badlogic.gdx.imgui;

import com.badlogic.gdx.Input;

/**
 * @author mcpussy
 */

public enum ImGuiKey {
	Tab(0, Input.Keys.TAB),
	LeftArrow(1, Input.Keys.DPAD_LEFT),
	RightArrow(2, Input.Keys.DPAD_RIGHT),
	UpArrow(3, Input.Keys.DPAD_UP),
	DownArrow(4, Input.Keys.DPAD_DOWN),
	PageUp(5,Input.Keys.PAGE_UP),
	PageDown(6, Input.Keys.PAGE_DOWN),
	Home(7, Input.Keys.HOME),
	End(8, Input.Keys.END),
	Delete(9, Input.Keys.FORWARD_DEL),
	Backspace(10, Input.Keys.BACKSPACE),
	Enter(11, Input.Keys.ENTER),
	Escape(12, Input.Keys.ESCAPE),
	A(13, Input.Keys.A),
	C(14, Input.Keys.C),
	V(15, Input.Keys.V),
	X(16, Input.Keys.X),
	Y(17, Input.Keys.Y),
	Z(18, Input.Keys.Z);

	public final int imKey;
	public final int gdxKey;

	ImGuiKey(int imKey, int gdxKey) {
		this.imKey = imKey;
		this.gdxKey = gdxKey;
	}
}
