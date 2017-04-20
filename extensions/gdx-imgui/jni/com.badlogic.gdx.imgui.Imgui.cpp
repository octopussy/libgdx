#include <com.badlogic.gdx.imgui.Imgui.h>
JNIEXPORT jstring JNICALL Java_com_badlogic_gdx_imgui_Imgui_getString(JNIEnv* env, jclass clazz, jobject i) {


//@line:8

	 int iIIIII = 0;

	 jstring result;
	 result = env->NewStringUTF("Hello!!!");
	 return result;
	

}

JNIEXPORT jlong JNICALL Java_com_badlogic_gdx_imgui_Imgui_getLong(JNIEnv* env, jclass clazz) {


//@line:16

	 return (jlong)723;
	

}

