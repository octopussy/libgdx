#ifndef _Included_Utils_h
#define _Included_Utils_h

/*#ifdef __cplusplus
extern "C" {
#endif*/

#include <imgui.h>

jobject toGdxVec2(JNIEnv* env, const ImVec2& v) {
    assert(env != NULL);
    jclass vecCls = env->FindClass("com/badlogic/gdx/math/Vector2");
    assert(vecCls != NULL);
    jmethodID vecCtor = env->GetMethodID(vecCls, "<init>", "(FF)V");
    assert(vecCtor != NULL);
    return env->NewObject(vecCls, vecCtor, v.x, v.y);
}

#endif