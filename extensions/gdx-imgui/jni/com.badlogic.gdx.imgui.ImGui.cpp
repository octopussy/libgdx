#include <com.badlogic.gdx.imgui.ImGui.h>

//@line:11

		#include <imgui.h>
	 JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getTexDataAsRGBA32(JNIEnv* env, jclass clazz) {


//@line:21

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

JNIEXPORT jfloat JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDeltaTime(JNIEnv* env, jclass clazz) {


//@line:44

		ImGuiIO& io = ImGui::GetIO();
		return io.DeltaTime;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDisplaySize(JNIEnv* env, jclass clazz, jfloat width, jfloat height) {


//@line:49

		ImGuiIO& io = ImGui::GetIO();
	 	io.DisplaySize = ImVec2(width, height);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDeltaTime(JNIEnv* env, jclass clazz, jfloat value) {


//@line:54

		ImGuiIO& io = ImGui::GetIO();
	 	io.DeltaTime = value > 0.0 ? value : (float)(1.0f/60.0f);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_newFrame(JNIEnv* env, jclass clazz) {


//@line:59

	 	ImGui::NewFrame();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_render(JNIEnv* env, jclass clazz) {


//@line:63

	 	ImGui::Render();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_shutdown(JNIEnv* env, jclass clazz) {


//@line:67

	 	ImGui::Shutdown();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showUserGuide(JNIEnv* env, jclass clazz) {


//@line:71

	 	ImGui::ShowUserGuide();
	

}

JNIEXPORT jint JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDrawListCount(JNIEnv* env, jclass clazz) {


//@line:75

	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->CmdListsCount;
	

}

JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getDrawList(JNIEnv* env, jclass clazz, jint index) {


//@line:80

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
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_getVertBuffer(JNIEnv* env, jclass clazz, jfloatArray obj_out, jint cmdListIndex) {
	float* out = (float*)env->GetPrimitiveArrayCritical(obj_out, 0);


//@line:113

		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawVert* vtx_buffer = cmd_list->VtxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, vtx_buffer, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));
	
	env->ReleasePrimitiveArrayCritical(obj_out, out, 0);

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_getIndBuffer(JNIEnv* env, jclass clazz, jshortArray obj_out, jint cmdListIndex) {
	short* out = (short*)env->GetPrimitiveArrayCritical(obj_out, 0);


//@line:122

		ImDrawData* data = ImGui::GetDrawData();
		const ImDrawList* cmd_list = data->CmdLists[cmdListIndex];
		const ImDrawIdx* idx_buffer = cmd_list->IdxBuffer.Data;

		//float* pDst = (float *)env->GetDirectBufferAddress(out);
		memcpy(out, idx_buffer, cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx));
	
	env->ReleasePrimitiveArrayCritical(obj_out, out, 0);

}

JNIEXPORT jint JNICALL Java_com_badlogic_gdx_imgui_ImGui_getTotalVtxCount(JNIEnv* env, jclass clazz) {


//@line:131

	 	ImDrawData* data = ImGui::GetDrawData();
	 	return data->TotalVtxCount;
	

}

