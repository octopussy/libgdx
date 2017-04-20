package com.badlogic.gdx.imgui;

/**
 * @author mcpussy
 * @date 20/04/2017
 */
public class ImGui {

	/*JNI
		#include <imgui.h>
	 */

/*	public static native void getTexDataAsAlpha8(unsigned char**out_pixels, int*out_width, int*out_height, int*out_bytes_per_pixel=NULL); *//*
		ImGuiIO& io = ImGui::GetIO();
		return io.DeltaTime;
	*/


	public static native ImGuiTexData getTexDataAsRGBA32(); /*
		ImGuiIO& io = ImGui::GetIO();
		unsigned char* pixels;
		int width, height, bpp;
		io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height, &bpp);

		int size = width * height * bpp;

		jbyteArray result = env->NewByteArray(size);

		env->SetByteArrayRegion(result, 0, size, (jbyte*)pixels);

		jclass cls = env->FindClass("com/badlogic/gdx/imgui/ImGuiTexData");
		jmethodID constructor = env->GetMethodID(cls, "<init>", "([BIII)V");
		jobject object = env->NewObject(cls, constructor, result, width, height, bpp);
		return object;
	*/

	/*public static native void setTexID(void*id) *//*
	 	TexID = id;
	 	}
	*/

	public static native float getDeltaTime(); /*
		ImGuiIO& io = ImGui::GetIO();
		return io.DeltaTime;
	*/

	public static native void setDisplaySize(float width, float height); /*
		ImGuiIO& io = ImGui::GetIO();
	 	io.DisplaySize = ImVec2(width, height);
	*/

	public static native void setDeltaTime(float value); /*
		ImGuiIO& io = ImGui::GetIO();
	 	io.DeltaTime = value > 0.0 ? value : (float)(1.0f/60.0f);
	*/

	public static native void newFrame(); /*
	 	ImGui::NewFrame();
	*/

	public static native void render(); /*
	 	ImGui::NewFrame();
	*/

	public static native void shutdown(); /*
	 	ImGui::Shutdown();
	*/

	public static native void showUserGuide(); /*
	 	ImGui::ShowUserGuide();
	*/
}
