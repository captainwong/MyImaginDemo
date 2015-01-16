#pragma once


#include <assert.h>
#include "../../sdk/include/kd-core-api/kd-core-api.h"
#pragma comment(lib, "../sdk/lib/win32/Debug/KdCoreApi.lib")


#define NAMESPACE_BEGIN(__namespace)	namespace __namespace{
#define NAMESPACE_END					};


namespace Imagin
{


#define DECLARE_UNCOPYABLE(classname) \
private:\
	classname(const classname&) {}\
	classname& operator=(const classname&) {}


#define DECLARE_CALLBACK_IMAGIN(function, caller_class, caller_function)\
	static void function(void* udata, \
						CoreApiObj obj, \
						CoreApiAsyncCallerObj caller, \
						CoreApiResultObj result) \
	{ \
		caller_class* cc = reinterpret_cast<caller_class*>(udata); assert(cc); \
		cc->caller_function(result); \
	}


#define DECLARE_CALLBACK_USER(function, caller_class, caller_function)\
	static void __stdcall function(void* caller, \
									bool success, \
									int code, \
									const char* phrase, \
									void* udata) \
	{ \
		caller_class* cc = reinterpret_cast<caller_class*>(caller); assert(cc); \
		cc->caller_function(success, code, phrase); \
	}

#define DECLARE_CALLBACK_TIMER(function, caller_class, caller_function) \
	static void __stdcall function(CTimer* timer, void* udata) \
	{ \
		caller_class* cc = reinterpret_cast<caller_class*>(udata); assert(cc); \
		cc->caller_function(); \
	}

	typedef void(_stdcall *AsyncCallerCb)(void* caller,
										  bool success,
										  int code,
										  const char* phrase,
										  void* udata);

	typedef  void(_stdcall *EmailExistsResultCB)(void* caller,
												 bool bResult,
												 int nCode,
												 const char* phrase,
												 bool exists,
												 void* udata);


	typedef void(_stdcall *MediaDataCb)(void* udata,
										const uint8_t *buf,
										uint32_t size);


	typedef void(_stdcall *MediaCodecCb)(void* udata,
										 const char* name,
										 int32_t pt,
										 const char* rtpmap,
										 const char** fmtp);


	typedef void(_stdcall *MediaShutdownCb)(void* udata);


	typedef struct MediaInfoCb
	{
		MediaDataCb		audioRtpCb;
		MediaDataCb		audioRtcpCb;
		MediaDataCb		videoRtpCb;
		MediaDataCb		videoRtcpCb;
		MediaCodecCb	audioCodecCb;
		MediaCodecCb	videoCodecCb;
		MediaShutdownCb	shutdownCb;
		void*			udata;
	}MediaInfoCb;


	static inline void async_caller_unref_later(CoreApiAsyncCallerObj& caller)
	{
		if (core_api_obj_is_valid(caller)) {
			core_api_async_caller_unref_later(caller);
			caller = CORE_API_INVALID_OBJ;
		}
	}


	static inline void async_caller_cancel_and_unref_later(CoreApiAsyncCallerObj& caller)
	{
		if (core_api_obj_is_valid(caller)) {
			core_api_async_caller_cancel(caller);
			core_api_async_caller_unref_later(caller);
			caller = CORE_API_INVALID_OBJ;
		}
	}


	typedef enum DeviceEvent
	{
		DE_DEL = 0,
		DE_ADD,
		DE_OFFLINE,
		DE_ONLINE,
		DE_UNUSEABLE,
		DE_USEABLE,
	}DeviceEvent;


	typedef enum DeviceState
	{
		DS_OFFLINE = 0,
		DS_ONLINE,
		DS_READY,
	}DeviceState;


	typedef enum CameraState
	{
		CS_NONE,
		CS_GETTING,
		CS_GETFAILED,
		CS_READY,
	}CameraState;


NAMESPACE_END
