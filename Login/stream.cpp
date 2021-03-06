#include "stream.h"

NAMESPACE_BEGIN(Imagin)

Stream::Stream(CoreApiDeviceStreamObj deviceStreamObj)
	: _deviceMediaObj(CORE_API_INVALID_OBJ)
	, _callerObj(CORE_API_INVALID_OBJ)
	, _openMediaCallerCb(NULL)
	, _pMediaInfoCb(NULL)
	, _udata(NULL)
{
	assert(core_api_obj_is_valid(deviceStreamObj));
	_deviceStreamObj = core_api_device_stream_ref(deviceStreamObj);

	_openMediaCb.on_result = open_media_on_result;
	_openMediaCb.udata = this;

	_deviceMediaCb.on_audio_codec = media_audio_codec;
	_deviceMediaCb.on_audio_rtcp = media_audio_rtcp;
	_deviceMediaCb.on_audio_rtp = media_audio_rtp;
	_deviceMediaCb.on_shutdown = media_shutdown;
	_deviceMediaCb.on_video_codec = media_video_codec;
	_deviceMediaCb.on_video_rtcp = media_video_rtcp;
	_deviceMediaCb.on_video_rtp = media_video_rtp;
	_deviceMediaCb.udata = this;
}


Stream::~Stream()
{
	assert(0);
}


bool Stream::CreateDeviceMedia()
{
	assert(core_api_obj_is_valid(_deviceStreamObj));
	if (core_api_obj_is_valid(_deviceMediaObj)) {
		CloseMedia();
	}

	_deviceMediaObj = core_api_device_stream_create_media(_deviceStreamObj,
														  &_deviceMediaCb);

	return core_api_obj_is_valid(_deviceMediaObj);
}


bool Stream::OpenMedia(MediaInfoCb* mediaInfoCb, AsyncCallerCb openResultCb, void* udata)
{
	if (!CreateDeviceMedia()) {
		return false;
	}

	_pMediaInfoCb = mediaInfoCb;
	_openMediaCallerCb = openResultCb;
	_udata = udata;

	async_caller_cancel_and_unref_later(_callerObj);

	core_api_device_media_set_audio_recv(_deviceMediaObj, 0);
	core_api_device_media_open(_deviceMediaObj, &_openMediaCb, &_callerObj);

	return true;
}


void Stream::CloseMedia()
{
	_pMediaInfoCb = NULL;
	_openMediaCallerCb = NULL;
	_udata = NULL;

	if (core_api_obj_is_valid(_deviceMediaObj)) {
		async_caller_cancel_and_unref_later(_callerObj);
		core_api_device_media_close(_deviceMediaObj, NULL, NULL);
		core_api_device_media_unref_later(_deviceMediaObj);
		_deviceMediaObj = CORE_API_INVALID_OBJ;
	}
}


// **********static callback functions begin**********************//
void Stream::open_media_on_result(void* udata,
								 CoreApiObj obj,
								 CoreApiAsyncCallerObj caller,
								 CoreApiResultObj result)
{
	Stream* stream = reinterpret_cast<Stream*>(udata); assert(stream);
	stream->OpenMediaOnResult(result);
}


void Stream::media_audio_codec(void* udata,
							  CoreApiDeviceMediaObj media,
							  const char* name,
							  int32_t pt,
							  const char* rtpmap,
							  const char** fmtp)
{
	Stream* stream = reinterpret_cast<Stream*>(udata); assert(stream);
	stream->MediaAudioCodec(name, pt, rtpmap, fmtp);
}

void Stream::media_video_codec(void* udata,
							  CoreApiDeviceMediaObj media,
							  const char* name,
							  int32_t pt,
							  const char* rtpmap,
							  const char** fmtp)
{
	Stream* stream = reinterpret_cast<Stream*>(udata); assert(stream);
	stream->MediaVideoCodec(name, pt, rtpmap, fmtp);
}

void Stream::media_audio_rtp(void* udata,
							CoreApiDeviceMediaObj media,
							const uint8_t* buff,
							uint32_t size)
{
	Stream* stream = reinterpret_cast<Stream*>(udata); assert(stream);
	stream->MediaAudioRtp(udata, media, buff, size);
}

void Stream::media_audio_rtcp(void* udata,
							 CoreApiDeviceMediaObj media,
							 const uint8_t* buff,
							 uint32_t size)
{
	Stream* stream = reinterpret_cast<Stream*>(udata); assert(stream);
	stream->MediaAudioRtcp(udata, media, buff, size);
}

void Stream::media_video_rtp(void* udata,
							CoreApiDeviceMediaObj media,
							const uint8_t* buff,
							uint32_t size)
{
	Stream* stream = reinterpret_cast<Stream*>(udata); assert(stream);
	stream->MediaVideoRtp(udata, media, buff, size);
}

void Stream::media_video_rtcp(void* udata,
							 CoreApiDeviceMediaObj media,
							 const uint8_t* buff,
							 uint32_t size)
{
	Stream* stream = reinterpret_cast<Stream*>(udata); assert(stream);
	stream->MediaVideoRtcp(udata, media, buff, size);
}

void Stream::media_shutdown(void* udata, CoreApiDeviceMediaObj media)
{
	Stream* stream = reinterpret_cast<Stream*>(udata); assert(stream);
	stream->MediaShutdown();
}
// **********static callback functions end************************//

// protected:
// **********called by the callback functions begin***************//
void Stream::OpenMediaOnResult(CoreApiResultObj result)
{
	assert(core_api_obj_is_valid(result));
	int code = core_api_result_get_code(result);
	if (100 < code && code < CORE_API_RESULT_OK->code) {
		return;
	} else {
		bool success = code == CORE_API_RESULT_OK->code;
		async_caller_unref_later(_callerObj);
		if (_openMediaCallerCb) {
			_openMediaCallerCb(this, 
							   success, 
							   code,
							   core_api_result_get_phrase(result),
							   _udata);
		}
	}
}

void Stream::MediaAudioCodec(const char* name,
					 int32_t pt,
					 const char* rtpmap,
					 const char** fmtp)
{
	if ((NULL != _pMediaInfoCb) && (NULL != _pMediaInfoCb->audioCodecCb)) {
		_pMediaInfoCb->audioCodecCb(_pMediaInfoCb->udata, name, pt, rtpmap, fmtp);
	}
}

void Stream::MediaVideoCodec(const char* name,
					 int32_t pt,
					 const char* rtpmap,
					 const char** fmtp)
{
	if ((NULL != _pMediaInfoCb) && (NULL != _pMediaInfoCb->videoCodecCb)) {
		_pMediaInfoCb->videoCodecCb(_pMediaInfoCb->udata, name, pt, rtpmap, fmtp);
	}
}

void Stream::MediaAudioRtp(void* uata,
				   CoreApiDeviceMediaObj media,
				   const uint8_t* buff,
				   uint32_t size)
{
	if ((NULL != _pMediaInfoCb) && (NULL != _pMediaInfoCb->audioRtpCb)) {
		_pMediaInfoCb->audioRtpCb(_pMediaInfoCb->udata, buff, size);
	}
}

void Stream::MediaAudioRtcp(void* uata,
					CoreApiDeviceMediaObj media,
					const uint8_t* buff,
					uint32_t size)
{
	if ((NULL != _pMediaInfoCb) && (NULL != _pMediaInfoCb->audioRtcpCb)) {
		_pMediaInfoCb->audioRtcpCb(_pMediaInfoCb->udata, buff, size);
	}
}

void Stream::MediaVideoRtp(void* uata,
				   CoreApiDeviceMediaObj media,
				   const uint8_t* buff,
				   uint32_t size)
{
	if ((NULL != _pMediaInfoCb) && (NULL != _pMediaInfoCb->videoRtpCb)) {
		_pMediaInfoCb->videoRtpCb(_pMediaInfoCb->udata, buff, size);
	}
}

void Stream::MediaVideoRtcp(void* uata,
					CoreApiDeviceMediaObj media,
					const uint8_t* buff,
					uint32_t size)
{
	if ((NULL != _pMediaInfoCb) && (NULL != _pMediaInfoCb->videoRtcpCb)) {
		_pMediaInfoCb->videoRtcpCb(_pMediaInfoCb->udata, buff, size);
	}
}

void Stream::MediaShutdown()
{
	if ((NULL != _pMediaInfoCb) && (NULL != _pMediaInfoCb->shutdownCb)) {
		_pMediaInfoCb->shutdownCb(_pMediaInfoCb->udata);
	}
}
// **********called by the callback functions end*****************//

NAMESPACE_END
