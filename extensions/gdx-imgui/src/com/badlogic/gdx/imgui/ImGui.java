package com.badlogic.gdx.imgui;

/**
 * @author mcpussy
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

	public static native void setKeyMap(int key, int value); /*
	 	ImGuiIO& io = ImGui::GetIO();
		io.KeyMap[key] = value;
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

	public static native void setMousePos(float x, float y); /*
	 	ImGuiIO& io = ImGui::GetIO();
	 	io.MousePos = ImVec2(x, y);
	*/

	public static native void setMouseDown(int index, boolean buttonPressed); /*
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[index] = buttonPressed;
	*/

	public static native void setKeyDown(int keycode, boolean set); /*
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[keycode] = set;
	*/

	public static native void setKeyCtrl(boolean set); /*
		ImGuiIO& io = ImGui::GetIO();
		io.KeyCtrl = set;
	*/

	public static native void setKeyShift(boolean set); /*
		ImGuiIO& io = ImGui::GetIO();
		io.KeyShift = set;
	*/

	public static native void setKeyAlt(boolean set); /*
		ImGuiIO& io = ImGui::GetIO();
		io.KeyAlt = set;
	*/

	public static native boolean isKeysDown(int keycode); /*
		ImGuiIO& io = ImGui::GetIO();
		return io.KeysDown[keycode];
	*/

	public static native void addInputCharacter(char character); /*
	 	ImGuiIO& io = ImGui::GetIO();
	 	io.AddInputCharacter(character);
	*/

	public static native boolean isMouseHoveringAnyWindow(); /*
		return ImGui::IsMouseHoveringAnyWindow();
	*/

	public static native boolean wantCaptureMouse(); /*
	 	return ImGui::GetIO().WantCaptureMouse;
	*/

	public static native boolean wantCaptureKeyboard();/*
	 	return ImGui::GetIO().WantCaptureKeyboard;
	*/

	public static native boolean wantTextInput();/*
	 	return ImGui::GetIO().WantTextInput;
	*/

	public static native void setMouseWheel(float value); /*
		ImGuiIO& io = ImGui::GetIO();
	 	io.MouseWheel = value;
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

	public static native void showTestWindow(); /*
	 	ImGui::ShowTestWindow();
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

		jmethodID cmdCtor = env->GetMethodID(cmdCls, "<init>", "(IFFFF)V");
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
			jobject o = env->NewObject(cmdCls, cmdCtor, cmd->ElemCount, cmd->ClipRect.x,
				cmd->ClipRect.y, cmd->ClipRect.z, cmd->ClipRect.w);

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

	public static native void getIdxBuffer(short[] out, int cmdListIndex); /*
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
