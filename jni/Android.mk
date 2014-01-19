LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Disslove
#VisualGDBAndroid: AutoUpdateSourcesInNextLine
LOCAL_SRC_FILES := Disslove.cpp GLBatch.cpp GLShaderManager.cpp GLTools.cpp GLTriangleBatch.cpp \
				   math3d.cpp SuperBible.cpp GL6_6Dissolve.cpp
LOCAL_LDLIBS := -lGLESv2 -llog
LOCAL_CFLAGS := -DUSE_FILE32API -DGL_GLEXT_PROTOTYPES=1

include $(BUILD_SHARED_LIBRARY)
