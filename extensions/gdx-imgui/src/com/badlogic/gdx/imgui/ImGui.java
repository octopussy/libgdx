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

	public static native void setKeyMap(int key, int value); /* ImGui::GetIO().KeyMap[key] = value; */

	public static native float getDeltaTime(); /* ImGui::GetIO().DeltaTime; */

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


	///////////////////////////////////////////////////////////////////////////////
	// "Native" windows
	public static native void showUserGuide(); /*
	 	ImGui::ShowUserGuide();
	*/

	public static native void showTestWindow(); /*
	 	ImGui::ShowTestWindow();
	*/

	public static native void showMetricsWindow(); /*
	 	ImGui::ShowTestWindow();
	*/


	///////////////////////////////////////////////////////////////////////////////
	// Window
	// Passing 'openRef' displays a Close button on the upper-right corner of the window, the pointed value will be set to false when the button is pressed.
	// Return false when window is collapsed, so you can early out in your code. You always need to call ImGui::End() even if false is returned.

	public static boolean begin(String name) {
		return begin(name, null, 0);
	}

	public static boolean begin(String name, int flags) {
		return begin(name, null, flags);
	}

	public static boolean begin(String name, ValueRef<Boolean> openRef) {
		return begin(name, openRef, 0);
	}

	public static boolean begin(String name, ValueRef<Boolean> openRef, int flags) {
		boolean collapsed = false;
		if (openRef != null) {
			BeginWindowJniResult result = beginJni(name, openRef.get(), flags);
			openRef.set(result.isOpen);
			return result.isCollapsed;
		} else {
			return beginJni(name, flags);
		}
	}

	public static native void end(); /*
		ImGui::End();
	*/

	// window position/size
	// set next window position. call before Begin()
	public static void setNextWindowPos(float x, float y) {
		setNextWindowPos(x, y, 0);
	}

	// set next window position. call before Begin()
	// ImGuiSetCond condFlags
	public static native void setNextWindowPos(float x, float y, int condFlags); /*
		ImGui::SetNextWindowPos(ImVec2(x, y), condFlags);
	*/

	// set next window position to be centered on screen. call before Begin()
	public static void setNextWindowPosCenter() {
		setNextWindowPosCenter(0);
	}

	// set next window position to be centered on screen. call before Begin()
	// ImGuiSetCond condFlags
	public static native void setNextWindowPosCenter(int condFlags);/*
		ImGui::SetNextWindowPosCenter(condFlags);
	*/

	// set next window size. set axis to 0.0f to force an auto-fit on this axis. call before Begin()
	public static void setNextWindowSize(float width, float height) {
		setNextWindowSize(width, height, 0);
	}

	// set next window size. set axis to 0.0f to force an auto-fit on this axis. call before Begin()
	// ImGuiSetCond condFlags
	public static native void setNextWindowSize(float width, float height, int condFlags); /*
		ImGui::SetNextWindowSize(ImVec2(width, height), condFlags);
	*/

	// set next window size limits. use -1,-1 on either X/Y axis to preserve the current size. Use callback to apply non-trivial programmatic constraints.
	// TODO: implement callbacks
	public static native void setNextWindowSizeConstraints(float minWidth, float minHeight, float maxWidth, float maxHeight); /*
		ImGuiSizeConstraintCallback custom_callback = NULL;
		void* custom_callback_data = NULL;
		ImGui::SetNextWindowSizeConstraints(ImVec2(minWidth, minHeight), ImVec2(maxWidth, maxHeight), custom_callback, custom_callback_data);
	*/

	// set next window content size (enforce the range of scrollbars). set axis to 0.0f to leave it automatic. call before Begin()
	public static native void setNextWindowContentSize(float width, float height); /*
		ImGui::SetNextWindowContentSize(ImVec2(width, height));
	*/

	// set next window content width (enforce the range of horizontal scrollbar). call before Begin()
	public static native void setNextWindowContentWidth(float width); /*
		ImGui::SetNextWindowContentWidth(width);
	*/

	// set next window collapsed state. call before Begin()
	public static void setNextWindowCollapsed(boolean collapsed) {
		setNextWindowCollapsed(collapsed, 0);
	}

	// set next window collapsed state. call before Begin()
	public static native void setNextWindowCollapsed(boolean collapsed, int condFlags); /*
	 	ImGui::SetNextWindowCollapsed(collapsed, condFlags);
	*/

	// set next window to be focused / front-most. call before Begin()
	public static native void setNextWindowFocus(); /* ImGui::SetNextWindowFocus(); */

	// (not recommended) set current window position - call within Begin()/End(). prefer using SetNextWindowPos(), as this may incur tearing and side-effects.
	// set next window position. call before Begin()
	public static void setWindowPos(float x, float y) {
		setWindowPos(x, y, 0);
	}

	// (not recommended) set current window position - call within Begin()/End(). prefer using SetNextWindowPos(), as this may incur tearing and side-effects.
	// ImGuiSetCond condFlags
	public static native void setWindowPos(float x, float y, int condFlags); /* ImGui::SetWindowPos(ImVec2(x, y), condFlags); */

	// (not recommended) set current window size - call within Begin()/End(). set to ImVec2(0,0) to force an auto-fit. prefer using SetNextWindowSize(), as this may incur tearing and minor side-effects.
	public static void setWindowSize(float width, float height) {
		setWindowSize(width, height, 0);
	}

	// (not recommended) set current window size - call within Begin()/End(). set to ImVec2(0,0) to force an auto-fit. prefer using SetNextWindowSize(), as this may incur tearing and minor side-effects.
	// ImGuiSetCond condFlags
	public static native void setWindowSize(float width, float height, int condFlags); /*
		ImGui::SetWindowSize(ImVec2(width, height), condFlags);
	*/

	// (not recommended) set current window collapsed state. prefer using SetNextWindowCollapsed().
	public static void setWindowCollapsed(boolean collapsed) {
		setWindowCollapsed(collapsed, 0);
	}

	// (not recommended) set current window collapsed state. prefer using SetNextWindowCollapsed().
	public static native void setWindowCollapsed(boolean collapsed, int condFlags); /* ImGui::SetWindowCollapsed(collapsed, condFlags); */

	// (not recommended) set current window to be focused / front-most. prefer using SetNextWindowFocus().
	public static native void setWindowFocus(); /* ImGui::SetWindowFocus(); */

	// set named window position.
	public static void setWindowPos(String name, float x, float y) {
		setWindowPos(name, x, y, 0);
	}

	// set named window position.
	// ImGuiSetCond cond
	public static native void setWindowPos(String name, float x, float y, int condFlags); /*
		ImGui::SetWindowPos(name, ImVec2(x, y), condFlags);
	*/

	// set named window size. set axis to 0.0f to force an auto-fit on this axis.
	public static void setWindowSize(String name, float width, float height) {
		setWindowSize(name, width, height, 0);
	}

	// set named window size. set axis to 0.0f to force an auto-fit on this axis.
	// ImGuiSetCond cond
	public static native void setWindowSize(String name, float width, float height, int condFlags); /*
		ImGui::SetWindowSize(name, ImVec2(width, height), condFlags);
	*/

	// set named window collapsed state
	// ImGuiSetCond cond
	public static void setWindowCollapsed(String name, boolean collapsed) {
		setWindowCollapsed(name, collapsed, 0);
	}

	// set named window collapsed state
	// ImGuiSetCond cond
	public static native void setWindowCollapsed(String name, boolean collapsed, int condFlags); /*
	 	ImGui::SetWindowCollapsed(name, collapsed, condFlags);
	*/

	// set named window focused
	public static native void setWindowFocus(String name); /*
		ImGui::SetWindowFocus(name);
	*/

	// Window child
	// begin a scrolling region. size==0.0f: use remaining window size, size<0.0f: use remaining window size minus abs(size). size>0.0f: fixed size. each axis can use a different mode, e.g. ImVec2(0,400).
	//bool BeginChild(const char* str_id, const ImVec2& size = ImVec2(0,0), bool border = false, ImGuiWindowFlags extra_flags = 0);    // begin a scrolling region. size==0.0f: use remaining window size, size<0.0f: use remaining window size minus abs(size). size>0.0f: fixed size. each axis can use a different mode, e.g. ImVec2(0,400).
	//bool BeginChild(ImGuiID id, const ImVec2& size = ImVec2(0,0), bool border = false, ImGuiWindowFlags extra_flags = 0);            // "
	//void EndChild();


	private static native boolean beginJni(String name, int flags); /*
		return ImGui::Begin(name, NULL, flags);
	*/

	// TODO: optimize without BeginWindowJniResult
	private static native BeginWindowJniResult beginJni(String name, boolean initialOpenValue, int flags); /*
		bool open = initialOpenValue;
		bool collapsed = ImGui::Begin(name, &open);

		jclass resultCls = env->FindClass("com/badlogic/gdx/imgui/ImGui$BeginWindowJniResult");
	 	assert(resultCls != NULL);

		jmethodID ctor = env->GetMethodID(resultCls, "<init>", "(ZZ)V");
		assert(ctor != NULL);

		return env->NewObject(resultCls, ctor, collapsed, open);
	*/

	private static class BeginWindowJniResult {
		public final boolean isCollapsed;
		public final boolean isOpen;

		public BeginWindowJniResult(boolean isCollapsed, boolean isOpen) {
			this.isCollapsed = isCollapsed;
			this.isOpen = isOpen;
		}
	}
}
