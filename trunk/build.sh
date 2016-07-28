#!/bin/bash

tmpPATH=$PATH
export PATH=$PATH":/opt/android-sdk/tools:/opt/android-ndk"

android update project --target "android-19" --path . && \
ndk-build && \
ant debug && \
#adb uninstall ca.eighty7.app && \
adb install -r bin/androidSpider-debug.apk && \
adb shell am start -n ca.eighty7.spiderSolitaire/android.app.NativeActivity

export PATH=$tmpPATH