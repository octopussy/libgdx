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
 ImGui::GetIO().KeyMap[key] = value; 

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDeltaTime(JNIEnv* env, jclass clazz) {


//@line:43
 ImGui::GetIO().DeltaTime; 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDisplaySize(JNIEnv* env, jclass clazz, jfloat width, jfloat height) {


//@line:45

		ImGuiIO& io = ImGui::GetIO();
	 	io.DisplaySize = ImVec2(width, height);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDeltaTime(JNIEnv* env, jclass clazz, jfloat value) {


//@line:50

		ImGuiIO& io = ImGui::GetIO();
	 	io.DeltaTime = value > 0.0 ? value : (float)(1.0f/60.0f);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMousePos(JNIEnv* env, jclass clazz, jfloat x, jfloat y) {


//@line:55

	 	ImGuiIO& io = ImGui::GetIO();
	 	io.MousePos = ImVec2(x, y);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMouseDown(JNIEnv* env, jclass clazz, jint index, jboolean buttonPressed) {


//@line:60

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[index] = buttonPressed;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyDown(JNIEnv* env, jclass clazz, jint keycode, jboolean set) {


//@line:65

		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[keycode] = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyCtrl(JNIEnv* env, jclass clazz, jboolean set) {


//@line:70

		ImGuiIO& io = ImGui::GetIO();
		io.KeyCtrl = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyShift(JNIEnv* env, jclass clazz, jboolean set) {


//@line:75

		ImGuiIO& io = ImGui::GetIO();
		io.KeyShift = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyAlt(JNIEnv* env, jclass clazz, jboolean set) {


//@line:80

		ImGuiIO& io = ImGui::GetIO();
		io.KeyAlt = set;
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_isKeysDown(JNIEnv* env, jclass clazz, jint keycode) {


//@line:85

		ImGuiIO& io = ImGui::GetIO();
		return io.KeysDown[keycode];
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_addInputCharacter(JNIEnv* env, jclass clazz, jchar character) {


//@line:90

	 	ImGuiIO& io = ImGui::GetIO();
	 	io.AddInputCharacter(character);
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_isMouseHoveringAnyWindow(JNIEnv* env, jclass clazz) {


//@line:95

		return ImGui::IsMouseHoveringAnyWindow();
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_wantCaptureMouse(JNIEnv* env, jclass clazz) {


//@line:99

	 	return ImGui::GetIO().WantCaptureMouse;
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_wantCaptureKeyboard(JNIEnv* env, jclass clazz) {


//@line:103

	 	return ImGui::GetIO().WantCaptureKeyboard;
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_wantTextInput(JNIEnv* env, jclass clazz) {


//@line:107

	 	return ImGui::GetIO().WantTextInput;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMouseWheel(JNIEnv* env, jclass clazz, jfloat value) {


//@line:111

		ImGuiIO& io = ImGui::GetIO();
	 	io.MouseWheel = value;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_newFrame(JNIEnv* env, jclass clazz) {


//@line:116

	 	ImGui::NewFrame();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_render(JNIEnv* env, jclass clazz) {


//@line:120

	 	ImGui::Render();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_shutdown(JNIEnv* env, jclass clazz) {


//@line:124

	 	ImGui::Shutdown();
	

}

JNIEXPORT jint JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDrawListCount(JNIEnv* env, jclass clazz) {


//@line:128

	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->CmdListsCount;
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDrawList(JNIEnv* env, jclass clazz, jint index) {


//@line:133

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


//@line:167

		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawVert* vtx_buffer = cmd_list->VtxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, vtx_buffer, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
	
	env->ReleasePrimitiveArrayCritical(obj_out, out, 0);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_getIdxBuffer(JNIEnv* env, jclass clazz, jshortArray obj_out, jint cmdListIndex) {
	short* out = (short*)env->GetPrimitiveArrayCritical(obj_out, 0);


//@line:176

		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawIdx* idx_buffer = cmd_list->IdxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, idx_buffer, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
	
	env->ReleasePrimitiveArrayCritical(obj_out, out, 0);

}

JNIEXPORT jint JNICALL Java_com_badlogic_gdx_imgui_ImGui_getTotalVtxCount(JNIEnv* env, jclass clazz) {


//@line:185

	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->TotalVtxCount;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showUserGuide(JNIEnv* env, jclass clazz) {


//@line:193

	 	ImGui::ShowUserGuide();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showTestWindow(JNIEnv* env, jclass clazz) {


//@line:197

	 	ImGui::ShowTestWindow();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showMetricsWindow(JNIEnv* env, jclass clazz) {


//@line:201

	 	ImGui::ShowTestWindow();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_end(JNIEnv* env, jclass clazz) {


//@line:234

		ImGui::End();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowPos(JNIEnv* env, jclass clazz, jfloat x, jfloat y, jint condFlags) {


//@line:246

		ImGui::SetNextWindowPos(ImVec2(x, y), condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowPosCenter(JNIEnv* env, jclass clazz, jint condFlags) {


//@line:257

		ImGui::SetNextWindowPosCenter(condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowSize(JNIEnv* env, jclass clazz, jfloat width, jfloat height, jint condFlags) {


//@line:268

		ImGui::SetNextWindowSize(ImVec2(width, height), condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowSizeConstraints(JNIEnv* env, jclass clazz, jfloat minWidth, jfloat minHeight, jfloat maxWidth, jfloat maxHeight) {


//@line:274

		ImGuiSizeConstraintCallback custom_callback = NULL;
		void* custom_callback_data = NULL;
		ImGui::SetNextWindowSizeConstraints(ImVec2(minWidth, minHeight), ImVec2(maxWidth, maxHeight), custom_callback, custom_callback_data);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowContentSize(JNIEnv* env, jclass clazz, jfloat width, jfloat height) {


//@line:281

		ImGui::SetNextWindowContentSize(ImVec2(width, height));
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowContentWidth(JNIEnv* env, jclass clazz, jfloat width) {


//@line:286

		ImGui::SetNextWindowContentWidth(width);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowCollapsed(JNIEnv* env, jclass clazz, jboolean collapsed, jint condFlags) {


//@line:296

	 	ImGui::SetNextWindowCollapsed(collapsed, condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowFocus(JNIEnv* env, jclass clazz) {


//@line:301
 ImGui::SetNextWindowFocus(); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowPos__FFI(JNIEnv* env, jclass clazz, jfloat x, jfloat y, jint condFlags) {


//@line:311
 ImGui::SetWindowPos(ImVec2(x, y), condFlags); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowSize__FFI(JNIEnv* env, jclass clazz, jfloat width, jfloat height, jint condFlags) {


//@line:320

		ImGui::SetWindowSize(ImVec2(width, height), condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowCollapsed__ZI(JNIEnv* env, jclass clazz, jboolean collapsed, jint condFlags) {


//@line:330
 ImGui::SetWindowCollapsed(collapsed, condFlags); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowFocus__(JNIEnv* env, jclass clazz) {


//@line:333
 ImGui::SetWindowFocus(); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowPos__Ljava_lang_String_2FFI(JNIEnv* env, jclass clazz, jstring obj_name, jfloat x, jfloat y, jint condFlags) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:342

		ImGui::SetWindowPos(name, ImVec2(x, y), condFlags);
	
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowSize__Ljava_lang_String_2FFI(JNIEnv* env, jclass clazz, jstring obj_name, jfloat width, jfloat height, jint condFlags) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:353

		ImGui::SetWindowSize(name, ImVec2(width, height), condFlags);
	
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowCollapsed__Ljava_lang_String_2ZI(JNIEnv* env, jclass clazz, jstring obj_name, jboolean collapsed, jint condFlags) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:365

	 	ImGui::SetWindowCollapsed(name, collapsed, condFlags);
	
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowFocus__Ljava_lang_String_2(JNIEnv* env, jclass clazz, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:370

		ImGui::SetWindowFocus(name);
	
	env->ReleaseStringUTFChars(obj_name, name);

}

static inline jboolean wrapped_Java_com_badlogic_gdx_imgui_ImGui_beginJni__Ljava_lang_String_2I
(JNIEnv* env, jclass clazz, jstring obj_name, jint flags, char* name) {

//@line:381

		return ImGui::Begin(name, NULL, flags);
	
}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_beginJni__Ljava_lang_String_2I(JNIEnv* env, jclass clazz, jstring obj_name, jint flags) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_com_badlogic_gdx_imgui_ImGui_beginJni__Ljava_lang_String_2I(env, clazz, obj_name, flags, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jobject wrapped_Java_com_badlogic_gdx_imgui_ImGui_beginJni__Ljava_lang_String_2ZI
(JNIEnv* env, jclass clazz, jstring obj_name, jboolean initialOpenValue, jint flags, char* name) {

//@line:386

		bool open = initialOpenValue;
		bool collapsed = ImGui::Begin(name, &open);

		jclass resultCls = env->FindClass("com/badlogic/gdx/imgui/ImGui$BeginWindowJniResult");
	 	assert(resultCls != NULL);

		jmethodID ctor = env->GetMethodID(resultCls, "<init>", "(ZZ)V");
		assert(ctor != NULL);

		return env->NewObject(resultCls, ctor, collapsed, open);
	
}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_beginJni__Ljava_lang_String_2ZI(JNIEnv* env, jclass clazz, jstring obj_name, jboolean initialOpenValue, jint flags) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jobject JNI_returnValue = wrapped_Java_com_badlogic_gdx_imgui_ImGui_beginJni__Ljava_lang_String_2ZI(env, clazz, obj_name, initialOpenValue, flags, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

