LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := sfml-example

LOCAL_SRC_FILES := main.cpp
LOCAL_SRC_FILES += cards.cpp
LOCAL_SRC_FILES += cardStructure.cpp
LOCAL_SRC_FILES += draw.cpp
LOCAL_SRC_FILES += game.cpp
LOCAL_SRC_FILES += input.cpp
LOCAL_SRC_FILES += android.cpp
LOCAL_SRC_FILES += gameClass.cpp
LOCAL_SRC_FILES += textures.cpp

LOCAL_SHARED_LIBRARIES := sfml-system
LOCAL_SHARED_LIBRARIES += sfml-window
LOCAL_SHARED_LIBRARIES += sfml-graphics
LOCAL_WHOLE_STATIC_LIBRARIES := sfml-main

include $(BUILD_SHARED_LIBRARY)

$(call import-module,sfml)
