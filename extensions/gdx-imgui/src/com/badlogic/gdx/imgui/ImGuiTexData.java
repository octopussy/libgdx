package com.badlogic.gdx.imgui;

/**
 * @author mcpussy
 * @date 20/04/2017
 */
public class ImGuiTexData {
	public final byte[] data;
	public final int width;
	public final int height;
	public final int bytePerPixel;

	public ImGuiTexData(byte[] data, int width, int height, int bytePerPixel) {
		this.data = data;
		this.width = width;
		this.height = height;
		this.bytePerPixel = bytePerPixel;
	}
}
