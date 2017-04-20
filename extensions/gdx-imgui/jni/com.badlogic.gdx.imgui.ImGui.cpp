#include <com.badlogic.gdx.imgui.ImGui.h>

//@line:8

		#include <imgui.h>
	 JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getTexDataAsRGBA32(JNIEnv* env, jclass clazz) {


//@line:18

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
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyMap(JNIEnv* env, jclass clazz, jint key, jint value) {


//@line:41

	 	ImGuiIO& io = ImGui::GetIO();
		io.KeyMap[key] = value;
	

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDeltaTime(JNIEnv* env, jclass clazz) {


//@line:46

		ImGuiIO& io = ImGui::GetIO();
		return io.DeltaTime;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDisplaySize(JNIEnv* env, jclass clazz, jfloat width, jfloat height) {


//@line:51

		ImGuiIO& io = ImGui::GetIO();
	 	io.DisplaySize = ImVec2(width, height);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDeltaTime(JNIEnv* env, jclass clazz, jfloat value) {


//@line:56

		ImGuiIO& io = ImGui::GetIO();
	 	io.DeltaTime = value > 0.0 ? value : (float)(1.0f/60.0f);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMousePos(JNIEnv* env, jclass clazz, jfloat x, jfloat y) {


//@line:61

	 	ImGuiIO& io = ImGui::GetIO();
	 	io.MousePos = ImVec2(x, y);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMouseDown(JNIEnv* env, jclass clazz, jint index, jboolean buttonPressed) {


//@line:66

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[index] = buttonPressed;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyDown(JNIEnv* env, jclass clazz, jint keycode, jboolean set) {


//@line:71

		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[keycode] = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyCtrl(JNIEnv* env, jclass clazz, jboolean set) {


//@line:76

		ImGuiIO& io = ImGui::GetIO();
		io.KeyCtrl = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyShift(JNIEnv* env, jclass clazz, jboolean set) {


//@line:81

		ImGuiIO& io = ImGui::GetIO();
		io.KeyShift = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyAlt(JNIEnv* env, jclass clazz, jboolean set) {


//@line:86

		ImGuiIO& io = ImGui::GetIO();
		io.KeyAlt = set;
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_isKeysDown(JNIEnv* env, jclass clazz, jint keycode) {


//@line:91

		ImGuiIO& io = ImGui::GetIO();
		return io.KeysDown[keycode];
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_addInputCharacter(JNIEnv* env, jclass clazz, jchar character) {


//@line:96

	 	ImGuiIO& io = ImGui::GetIO();
	 	io.AddInputCharacter(character);
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_isMouseHoveringAnyWindow(JNIEnv* env, jclass clazz) {


//@line:101

		return ImGui::IsMouseHoveringAnyWindow();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMouseWheel(JNIEnv* env, jclass clazz, jfloat value) {


//@line:105

		ImGuiIO& io = ImGui::GetIO();
	 	io.MouseWheel = value;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_newFrame(JNIEnv* env, jclass clazz) {


//@line:110

	 	ImGui::NewFrame();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_render(JNIEnv* env, jclass clazz) {


//@line:114

	 	ImGui::Render();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_shutdown(JNIEnv* env, jclass clazz) {


//@line:118

	 	ImGui::Shutdown();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showUserGuide(JNIEnv* env, jclass clazz) {


//@line:122

	 	ImGui::ShowUserGuide();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showTestWindow(JNIEnv* env, jclass clazz) {


//@line:126

	 	ImGui::ShowTestWindow();
	

}

JNIEXPORT jint JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDrawListCount(JNIEnv* env, jclass clazz) {


//@line:130

	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->CmdListsCount;
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDrawList(JNIEnv* env, jclass clazz, jint index) {


//@line:135

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
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_getVertBuffer(JNIEnv* env, jclass clazz, jfloatArray obj_out, jint cmdListIndex) {
	float* out = (float*)env->GetPrimitiveArrayCritical(obj_out, 0);


//@line:169

		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawVert* vtx_buffer = cmd_list->VtxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, vtx_buffer, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
	
	env->ReleasePrimitiveArrayCritical(obj_out, out, 0);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_getIndBuffer(JNIEnv* env, jclass clazz, jshortArray obj_out, jint cmdListIndex) {
	short* out = (short*)env->GetPrimitiveArrayCritical(obj_out, 0);


//@line:178

		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawIdx* idx_buffer = cmd_list->IdxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, idx_buffer, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
	
	env->ReleasePrimitiveArrayCritical(obj_out, out, 0);

}

JNIEXPORT jint JNICALL Java_com_badlogic_gdx_imgui_ImGui_getTotalVtxCount(JNIEnv* env, jclass clazz) {


//@line:187

	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->TotalVtxCount;
	

}

