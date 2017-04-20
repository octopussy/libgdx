package com.badlogic.gdx.imgui;

/**
 * @author mcpussy
 * @date 20/04/2017
 */
public class Imgui {
	public static native String getString(Integer i); /*
	 int iIIIII = 0;

	 jstring result;
	 result = env->NewStringUTF("Hello!!!");
	 return result;
	*/

	public static native long getLong(); /*
	 return (jlong)723;
	*/
}
