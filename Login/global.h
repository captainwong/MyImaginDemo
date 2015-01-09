#pragma once


#include <assert.h>
#include "../sdk/include/kd-core-api/kd-core-api.h"
#pragma comment(lib, "../sdk/lib/win32/Debug/KdCoreApi.lib")


#define NAMESPACE_BEGIN(__namespace)	namespace __namespace{
#define NAMESPACE_END					};


NAMESPACE_BEGIN(Imagin)

#define DECLARE_UNCOPYABLE(classname) \
	private:\
		classname(const classname&) {}\
		classname& operator=(const classname&) {}


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
