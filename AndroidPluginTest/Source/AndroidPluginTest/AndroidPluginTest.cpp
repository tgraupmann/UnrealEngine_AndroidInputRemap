// Fill out your copyright notice in the Description page of Project Settings.

#include "AndroidPluginTest.h"

// this test is Android specific
#if PLATFORM_ANDROID

// Get access to Android logging
#include <android/log.h>

// The Android Input callback is defined in the launcher code
#include "../../../Launch/Public/Android/LaunchAndroid.h"

// Redefine a tag for logging
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "AndroidPluginTest"

#endif

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, AndroidPluginTest, "AndroidPluginTest" );

// this test is Android specific
#if PLATFORM_ANDROID

// Use a global variable to cause the constructor to invoke
AndroidPluginTestSetupCallbackAndroidInput GSetupCallbackAndroidInput;

// define the callback function that will get the android input events
int32_t AndroidPluginTestHandleRegisterCallbackAndroidInput(struct android_app* app, AInputEvent* event)
{
	// check the adb logcat
	__android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, "*** This indicates a successful test. The callback was invoked! ***");

	return 0;
}

// Use the constructor to register the input callback using the global var: `GSetupCallbackAndroidInput`
AndroidPluginTestSetupCallbackAndroidInput::AndroidPluginTestSetupCallbackAndroidInput()
{
	RegisterCallbackAndroidInput(AndroidPluginTestHandleRegisterCallbackAndroidInput);
}

#endif
