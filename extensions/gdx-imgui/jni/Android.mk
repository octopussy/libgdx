LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
 
LOCAL_MODULE    := gdx-imgui
LOCAL_C_INCLUDES := imgui/ 
 
LOCAL_CFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O2 -Wall -D__ANDROID__
LOCAL_CPPFLAGS := $(LOCAL_C_INCLUDES:%=-I%) -O2 -Wall -D__ANDROID__
LOCAL_LDLIBS := -lm
LOCAL_ARM_MODE  := arm
 
LOCAL_SRC_FILES := com.badlogic.gdx.imgui.ImGui.cpp\
	imgui/imgui.cpp\
	imgui/imgui_demo.cpp\
	imgui/imgui_draw.cpp
 
include $(BUILD_SHARED_LIBRARY)
