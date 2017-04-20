package com.badlogic.gdx.imgui;

import java.nio.FloatBuffer;

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
	 	ImGui::Render();
	*/

	public static native void shutdown(); /*
	 	ImGui::Shutdown();
	*/

	public static native void showUserGuide(); /*
	 	ImGui::ShowUserGuide();
	*/

	public static native int getDrawListCount(); /*
	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->CmdListsCount;
	*/

	public static native ImGuiDrawList getDrawList(int index); /*
	 	ImDrawData* data = ImGui::GetDrawData();
	 	ImDrawList* list = data->CmdLists[index];

		jclass cmdCls = env->FindClass("com/badlogic/gdx/imgui/ImGuiDrawCmd");
	 	jclass listCls = env->FindClass("com/badlogic/gdx/imgui/ImGuiDrawList");

	 	assert(cmdCls != NULL);
		assert(listCls != NULL);

		jmethodID cmdCtor = env->GetMethodID(cmdCls, "<init>", "(I)V");
		jmethodID listCtor = env->GetMethodID(listCls, "<init>", "([Lcom/badlogic/gdx/imgui/ImGuiDrawCmd;IIII)V");

		assert(cmdCtor != NULL);
		assert(listCtor != NULL);

		jobjectArray array = env->NewObjectArray(list->CmdBuffer.Size, cmdCls, NULL);
		jint vtxCount = list->VtxBuffer.Size;
		jint vtxElementSize = sizeof(ImDrawVert);
		jint idxCount = list->IdxBuffer.Size;
		jint idxElementSize = sizeof(ImDrawIdx);

		for (int i = 0; i < list->CmdBuffer.Size; ++i) {
			const ImDrawCmd* cmd = &list->CmdBuffer[i];
			jobject o = env->NewObject(cmdCls, cmdCtor, cmd->ElemCount);

			env->SetObjectArrayElement(array, i, o);
		}

		jobject result = env->NewObject(listCls, listCtor, array, vtxCount, vtxElementSize, idxCount, idxElementSize);
	 	return result;
	*/

	public static native void getVertBuffer(float[] out, int cmdListIndex); /*
		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawVert* vtx_buffer = cmd_list->VtxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, vtx_buffer, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
	*/

	public static native void getIndBuffer(short[] out, int cmdListIndex); /*
		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawIdx* idx_buffer = cmd_list->IdxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, idx_buffer, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
	*/

	public static native int getTotalVtxCount(); /*
	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->TotalVtxCount;
	*/
}
