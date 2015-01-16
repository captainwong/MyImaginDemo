#pragma once

#include "global.h"

namespace Imagin
{

class Stream
{
	DECLARE_UNCOPYABLE(Stream)
private:
	CoreApiDeviceStreamObj	_deviceStreamObj;
	CoreApiDeviceMediaObj	_deviceMediaObj;
	CoreApiDeviceMediaCb	_deviceMediaCb;
	CoreApiAsyncCallerObj	_callerObj;
	CoreApiAsyncCallerCb	_openMediaCb;
	AsyncCallerCb			_openMediaCallerCb;
	MediaInfoCb*			_pMediaInfoCb;
	void*					_udata;
	Stream() {}

public:
	Stream(CoreApiDeviceStreamObj deviceStreamObj);
	~Stream();
	bool CreateDeviceMedia();

	bool OpenMedia(MediaInfoCb* mediaInfoCb, AsyncCallerCb openResultCb, void* udata);

	CoreApiVSize GetMediaVideoSize() const
	{
		assert(core_api_obj_is_valid(_deviceStreamObj));
		return core_api_device_stream_view_size(_deviceStreamObj);
	}

	void CloseMedia();
	
protected:
	// static callback functions
	static void open_media_on_result(void* udata,
									 CoreApiObj obj,
									 CoreApiAsyncCallerObj caller,
									 CoreApiResultObj result);

	static void media_audio_codec(void* udata,
								  CoreApiDeviceMediaObj media,
								  const char* name,
								  int32_t pt,
								  const char* rtpmap,
								  const char** fmtp);

	static void media_video_codec(void* udata,
								  CoreApiDeviceMediaObj media,
								  const char* name,
								  int32_t pt,
								  const char* rtpmap,
								  const char** fmtp);

	static void media_audio_rtp(void* udata,
								CoreApiDeviceMediaObj media,
								const uint8_t* buff,
								uint32_t size);

	static void media_audio_rtcp(void* udata,
								 CoreApiDeviceMediaObj media,
								 const uint8_t* buff,
								 uint32_t size);

	static void media_video_rtp(void* udata,
								CoreApiDeviceMediaObj media,
								const uint8_t* buff,
								uint32_t size);

	static void media_video_rtcp(void* udata,
								 CoreApiDeviceMediaObj media,
								 const uint8_t* buff,
								 uint32_t size);

	static void media_shutdown(void* udata, CoreApiDeviceMediaObj media);

protected:
	// called by the callback functions
	void OpenMediaOnResult(CoreApiResultObj result);

	void MediaAudioCodec(const char* name,
						 int32_t pt,
						 const char* rtpmap,
						 const char** fmtp);

	void MediaVideoCodec(const char* name,
						 int32_t pt,
						 const char* rtpmap,
						 const char** fmtp);

	void MediaAudioRtp(void* uata,
					   CoreApiDeviceMediaObj media,
					   const uint8_t* buff,
					   uint32_t size);

	void MediaAudioRtcp(void* uata,
						CoreApiDeviceMediaObj media,
						const uint8_t* buff,
						uint32_t size);

	void MediaVideoRtp(void* uata,
					   CoreApiDeviceMediaObj media,
					   const uint8_t* buff,
					   uint32_t size);

	void MediaVideoRtcp(void* uata,
						CoreApiDeviceMediaObj media,
						const uint8_t* buff,
						uint32_t size);

	void MediaShutdown();
};


NAMESPACE_END

