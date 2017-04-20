#include <com.badlogic.gdx.imgui.ImGui.h>

//@line:9

		#include <imgui.h>
	 JNIEXPORT jobject JNICALL Java_com_badlogic_gdx_imgui_ImGui_getTexDataAsRGBA32(JNIEnv* env, jclass clazz) {


//@line:19

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


//@line:42

		ImGuiIO& io = ImGui::GetIO();
		return io.DeltaTime;
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDisplaySize(JNIEnv* env, jclass clazz, jfloat width, jfloat height) {


//@line:47

		ImGuiIO& io = ImGui::GetIO();
	 	io.DisplaySize = ImVec2(width, height);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_setDeltaTime(JNIEnv* env, jclass clazz, jfloat value) {


//@line:52

		ImGuiIO& io = ImGui::GetIO();
	 	io.DeltaTime = value > 0.0 ? value : (float)(1.0f/60.0f);
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_newFrame(JNIEnv* env, jclass clazz) {


//@line:57

	 	ImGui::NewFrame();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_render(JNIEnv* env, jclass clazz) {


//@line:61

	 	ImGui::NewFrame();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_shutdown(JNIEnv* env, jclass clazz) {


//@line:65

	 	ImGui::Shutdown();
	

}

JNIEXPORT void JNICALL Java_com_badlogic_gdx_imgui_ImGui_showUserGuide(JNIEnv* env, jclass clazz) {


//@line:69

	 	ImGui::ShowUserGuide();
	

}

