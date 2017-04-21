package com.badlogic.gdx.imgui;

/**
 * @author octopussy
 */
public class ImGuiSetCond {
	// Set the variable
	public static final int Always        =1<<0;

	// Set the variable once per runtime session (only the first call with succeed)
	public static final int Once          =1<<1;

	// Set the variable if the window has no saved data (if doesn't exist in the .ini file)
	public static final int FirstUseEver  =1<<2;

	// Set the variable if the window is appearing after being hidden/inactive (or the first time)
	public static final int Appearing     =1<<3;
}
