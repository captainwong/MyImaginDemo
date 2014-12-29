#pragma once

#include <assert.h>
#include "../sdk/include/kd-core-api/kd-core-api.h"
#pragma comment(lib, "../sdk/lib/win32/Debug/KdCoreApi.lib")

#define NAMESPACE_IMAGIN_BEGIN	namespace Imagin{
#define NAMESPACE_IMAGIN_END	};

NAMESPACE_IMAGIN_BEGIN

typedef void(_stdcall *AsyncCallerCb)(void* caller,
									  bool success,
									  int code,
									  const char* phrase,
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

static inline void async_caller_cancel_and_unref_later(CoreApiAsyncCallerObj& caller)
{
	if (core_api_obj_is_valid(caller)) {
		core_api_async_caller_cancel(caller);
		core_api_async_caller_unref_later(caller);
		caller = CORE_API_INVALID_OBJ;
	}
}

#include "stream.h"
#include "device.h"


NAMESPACE_IMAGIN_END
