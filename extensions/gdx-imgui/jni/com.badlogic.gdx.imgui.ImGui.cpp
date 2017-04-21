#include <com.badlogic.gdx.imgui.ImGui.h>

//@line:12

		#include <imgui.h>
		#include <utils.h>
	 JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getTexDataAsRGBA32(JNIEnv* env, jclass clazz) {


//@line:23

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


//@line:48
 ImGui::GetIO().KeyMap[key] = value; 

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDeltaTime(JNIEnv* env, jclass clazz) {


//@line:50
 ImGui::GetIO().DeltaTime; 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDisplaySize(JNIEnv* env, jclass clazz, jfloat width, jfloat height) {


//@line:52

		ImGuiIO& io = ImGui::GetIO();
	 	io.DisplaySize = ImVec2(width, height);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDeltaTime(JNIEnv* env, jclass clazz, jfloat value) {


//@line:57

		ImGuiIO& io = ImGui::GetIO();
	 	io.DeltaTime = value > 0.0 ? value : (float)(1.0f/60.0f);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMousePos(JNIEnv* env, jclass clazz, jfloat x, jfloat y) {


//@line:62

	 	ImGuiIO& io = ImGui::GetIO();
	 	io.MousePos = ImVec2(x, y);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMouseDown(JNIEnv* env, jclass clazz, jint index, jboolean buttonPressed) {


//@line:67

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[index] = buttonPressed;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyDown(JNIEnv* env, jclass clazz, jint keycode, jboolean set) {


//@line:72

		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[keycode] = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyCtrl(JNIEnv* env, jclass clazz, jboolean set) {


//@line:77

		ImGuiIO& io = ImGui::GetIO();
		io.KeyCtrl = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyShift(JNIEnv* env, jclass clazz, jboolean set) {


//@line:82

		ImGuiIO& io = ImGui::GetIO();
		io.KeyShift = set;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyAlt(JNIEnv* env, jclass clazz, jboolean set) {


//@line:87

		ImGuiIO& io = ImGui::GetIO();
		io.KeyAlt = set;
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_isKeysDown(JNIEnv* env, jclass clazz, jint keycode) {


//@line:92

		ImGuiIO& io = ImGui::GetIO();
		return io.KeysDown[keycode];
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_addInputCharacter(JNIEnv* env, jclass clazz, jchar character) {


//@line:97

	 	ImGuiIO& io = ImGui::GetIO();
	 	io.AddInputCharacter(character);
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_isMouseHoveringAnyWindow(JNIEnv* env, jclass clazz) {


//@line:102

		return ImGui::IsMouseHoveringAnyWindow();
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_wantCaptureMouse(JNIEnv* env, jclass clazz) {


//@line:106

	 	return ImGui::GetIO().WantCaptureMouse;
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_wantCaptureKeyboard(JNIEnv* env, jclass clazz) {


//@line:110

	 	return ImGui::GetIO().WantCaptureKeyboard;
	

}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_wantTextInput(JNIEnv* env, jclass clazz) {


//@line:114

	 	return ImGui::GetIO().WantTextInput;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setMouseWheel(JNIEnv* env, jclass clazz, jfloat value) {


//@line:118

		ImGuiIO& io = ImGui::GetIO();
	 	io.MouseWheel = value;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_newFrame(JNIEnv* env, jclass clazz) {


//@line:123

	 	ImGui::NewFrame();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_render(JNIEnv* env, jclass clazz) {


//@line:127

	 	ImGui::Render();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_shutdown(JNIEnv* env, jclass clazz) {


//@line:131

	 	ImGui::Shutdown();
	

}

JNIEXPORT jint JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDrawListCount(JNIEnv* env, jclass clazz) {


//@line:135

	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->CmdListsCount;
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDrawList(JNIEnv* env, jclass clazz, jint index) {


//@line:140

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


//@line:174

		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawVert* vtx_buffer = cmd_list->VtxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, vtx_buffer, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
	
	env->ReleasePrimitiveArrayCritical(obj_out, out, 0);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_getIdxBuffer(JNIEnv* env, jclass clazz, jshortArray obj_out, jint cmdListIndex) {
	short* out = (short*)env->GetPrimitiveArrayCritical(obj_out, 0);


//@line:183

		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawIdx* idx_buffer = cmd_list->IdxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, idx_buffer, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
	
	env->ReleasePrimitiveArrayCritical(obj_out, out, 0);

}

JNIEXPORT jint JNICALL Java_com_badlogic_gdx_imgui_ImGui_getTotalVtxCount(JNIEnv* env, jclass clazz) {


//@line:192

	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->TotalVtxCount;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showUserGuide(JNIEnv* env, jclass clazz) {


//@line:200

	 	ImGui::ShowUserGuide();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showTestWindow(JNIEnv* env, jclass clazz) {


//@line:204

	 	ImGui::ShowTestWindow();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showMetricsWindow(JNIEnv* env, jclass clazz) {


//@line:208

	 	ImGui::ShowTestWindow();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_end(JNIEnv* env, jclass clazz) {


//@line:240
 ImGui::End(); 

}

static inline jboolean wrapped_Java_com_badlogic_gdx_imgui_ImGui_beginChild__Ljava_lang_String_2FFZI
(JNIEnv* env, jclass clazz, jstring obj_id, jfloat width, jfloat height, jboolean border, jint extraWindowFlags, char* id) {

//@line:251

	 	return ImGui::BeginChild(id, ImVec2(width, height), border, extraWindowFlags);
	
}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_beginChild__Ljava_lang_String_2FFZI(JNIEnv* env, jclass clazz, jstring obj_id, jfloat width, jfloat height, jboolean border, jint extraWindowFlags) {
	char* id = (char*)env->GetStringUTFChars(obj_id, 0);

	jboolean JNI_returnValue = wrapped_Java_com_badlogic_gdx_imgui_ImGui_beginChild__Ljava_lang_String_2FFZI(env, clazz, obj_id, width, height, border, extraWindowFlags, id);

	env->ReleaseStringUTFChars(obj_id, id);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_com_badlogic_gdx_imgui_ImGui_beginChild__IFFI(JNIEnv* env, jclass clazz, jint id, jfloat width, jfloat height, jint extraWindowFlags) {


//@line:255

	 	return ImGui::BeginChild(id, ImVec2(width, height), false, extraWindowFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_endChild(JNIEnv* env, jclass clazz) {


//@line:259

		ImGui::EndChild();
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getContentRegionMax(JNIEnv* env, jclass clazz) {


//@line:264

		return toGdxVec2(env, ImGui::GetContentRegionMax());
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getContentRegionAvail(JNIEnv* env, jclass clazz) {


//@line:269

		return toGdxVec2(env, ImGui::GetContentRegionAvail());
	

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getContentRegionAvailWidth(JNIEnv* env, jclass clazz) {


//@line:273

		return ImGui::GetContentRegionAvailWidth();
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getWindowContentRegionMin(JNIEnv* env, jclass clazz) {


//@line:278

		return toGdxVec2(env, ImGui::GetWindowContentRegionMin());
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getWindowContentRegionMax(JNIEnv* env, jclass clazz) {


//@line:283

		return toGdxVec2(env, ImGui::GetWindowContentRegionMax());
	

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getWindowContentRegionWidth(JNIEnv* env, jclass clazz) {


//@line:287

	 	return ImGui::GetWindowContentRegionWidth();
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getWindowPos(JNIEnv* env, jclass clazz) {


//@line:296

		return toGdxVec2(env, ImGui::GetWindowPos());
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getWindowSize(JNIEnv* env, jclass clazz) {


//@line:301

		return toGdxVec2(env, ImGui::GetWindowSize());
	

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getWindowWidth(JNIEnv* env, jclass clazz) {


//@line:305

	 	return ImGui::GetWindowWidth();
	

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getWindowHeight(JNIEnv* env, jclass clazz) {


//@line:309

	 	return ImGui::GetWindowHeight();
	

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_isWindowCollapsed(JNIEnv* env, jclass clazz) {


//@line:313

	 	return ImGui::IsWindowCollapsed();
	

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowFontScale(JNIEnv* env, jclass clazz, jfloat scale) {


//@line:317

	 	ImGui::SetWindowFontScale(scale);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowPos(JNIEnv* env, jclass clazz, jfloat x, jfloat y, jint condFlags) {


//@line:330

		ImGui::SetNextWindowPos(ImVec2(x, y), condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowPosCenter(JNIEnv* env, jclass clazz, jint condFlags) {


//@line:341

		ImGui::SetNextWindowPosCenter(condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowSize(JNIEnv* env, jclass clazz, jfloat width, jfloat height, jint condFlags) {


//@line:352

		ImGui::SetNextWindowSize(ImVec2(width, height), condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowSizeConstraints(JNIEnv* env, jclass clazz, jfloat minWidth, jfloat minHeight, jfloat maxWidth, jfloat maxHeight) {


//@line:358

		ImGuiSizeConstraintCallback custom_callback = NULL;
		void* custom_callback_data = NULL;
		ImGui::SetNextWindowSizeConstraints(ImVec2(minWidth, minHeight), ImVec2(maxWidth, maxHeight), custom_callback, custom_callback_data);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowContentSize(JNIEnv* env, jclass clazz, jfloat width, jfloat height) {


//@line:365

		ImGui::SetNextWindowContentSize(ImVec2(width, height));
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowContentWidth(JNIEnv* env, jclass clazz, jfloat width) {


//@line:370

		ImGui::SetNextWindowContentWidth(width);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowCollapsed(JNIEnv* env, jclass clazz, jboolean collapsed, jint condFlags) {


//@line:380

	 	ImGui::SetNextWindowCollapsed(collapsed, condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setNextWindowFocus(JNIEnv* env, jclass clazz) {


//@line:385
 ImGui::SetNextWindowFocus(); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowPos__FFI(JNIEnv* env, jclass clazz, jfloat x, jfloat y, jint condFlags) {


//@line:395
 ImGui::SetWindowPos(ImVec2(x, y), condFlags); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowSize__FFI(JNIEnv* env, jclass clazz, jfloat width, jfloat height, jint condFlags) {


//@line:404

		ImGui::SetWindowSize(ImVec2(width, height), condFlags);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowCollapsed__ZI(JNIEnv* env, jclass clazz, jboolean collapsed, jint condFlags) {


//@line:414
 ImGui::SetWindowCollapsed(collapsed, condFlags); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowFocus__(JNIEnv* env, jclass clazz) {


//@line:417
 ImGui::SetWindowFocus(); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowPos__Ljava_lang_String_2FFI(JNIEnv* env, jclass clazz, jstring obj_name, jfloat x, jfloat y, jint condFlags) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:426

		ImGui::SetWindowPos(name, ImVec2(x, y), condFlags);
	
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowSize__Ljava_lang_String_2FFI(JNIEnv* env, jclass clazz, jstring obj_name, jfloat width, jfloat height, jint condFlags) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:437

		ImGui::SetWindowSize(name, ImVec2(width, height), condFlags);
	
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowCollapsed__Ljava_lang_String_2ZI(JNIEnv* env, jclass clazz, jstring obj_name, jboolean collapsed, jint condFlags) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:449

	 	ImGui::SetWindowCollapsed(name, collapsed, condFlags);
	
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setWindowFocus__Ljava_lang_String_2(JNIEnv* env, jclass clazz, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);


//@line:454

		ImGui::SetWindowFocus(name);
	
	env->ReleaseStringUTFChars(obj_name, name);

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getScrollX(JNIEnv* env, jclass clazz) {


//@line:459
 return ImGui::GetScrollX(); 

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getScrollY(JNIEnv* env, jclass clazz) {


//@line:462
 return ImGui::GetScrollY(); 

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getScrollMaxX(JNIEnv* env, jclass clazz) {


//@line:465
 return ImGui::GetScrollMaxX(); 

}

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getScrollMaxY(JNIEnv* env, jclass clazz) {


//@line:468
 return ImGui::GetScrollMaxY(); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setScrollX(JNIEnv* env, jclass clazz, jfloat scrollX) {


//@line:471
 ImGui::SetScrollX(scrollX); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setScrollY(JNIEnv* env, jclass clazz, jfloat scrollY) {


//@line:474
 ImGui::SetScrollY(scrollY); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setScrollHere(JNIEnv* env, jclass clazz, jfloat centerYRatio) {


//@line:477
 ImGui::SetScrollHere(centerYRatio); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setScrollFromPosY(JNIEnv* env, jclass clazz, jfloat posY, jfloat centerYRatio) {


//@line:480
 ImGui::SetScrollFromPosY(posY, centerYRatio); 

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setKeyboardFocusHere(JNIEnv* env, jclass clazz, jint offset) {


//@line:487
 ImGui::SetKeyboardFocusHere(offset); 

}

static inline jboolean wrapped_Java_com_badlogic_gdx_imgui_ImGui_beginJni__Ljava_lang_String_2I
(JNIEnv* env, jclass clazz, jstring obj_name, jint flags, char* name) {

//@line:495

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

//@line:500

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

