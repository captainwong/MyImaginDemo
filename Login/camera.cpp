#include "camera.h"
#include "stream.h"

NAMESPACE_BEGIN(Imagin)


Camera::Camera(const CoreApiDeviceCameraObj cameraObj,
				EnumStreamResultCb enumStreamResultCb,
				void* udata)
	: _callerObj(CORE_API_INVALID_OBJ)
	, _enumStreamResultCb(CORE_API_INVALID_OBJ)
	, _udata(udata)
{
	_callerCb.udata = this;
	_callerCb.on_result = enum_stream_on_result;

	assert(core_api_obj_is_valid(cameraObj));
	_deviceCameraObj = core_api_device_camera_ref(cameraObj);

	EnumStream();
}


Camera::~Camera()
{
	assert(0);
}


bool Camera::EnumStream()
{
	async_caller_cancel_and_unref_later(_callerObj);

	if (core_api_obj_is_valid(_helperStreamEnumeratorObj)) {
		core_api_helper_stream_enumerator_unref_later(_helperStreamEnumeratorObj);
		_helperStreamEnumeratorObj = CORE_API_INVALID_OBJ;
	}

	ClearStreamList();

	_helperStreamEnumeratorObj =
		core_api_device_camera_create_stream_enumerator(_deviceCameraObj);
	if (!core_api_obj_is_valid(_helperStreamEnumeratorObj)) {
		return false;
	}

	core_api_helper_stream_enumerator_enum(_helperStreamEnumeratorObj,
										   &_callerCb,
										   &_callerObj);

	return true;
}


bool Camera::OpenMedia(INT32 nstream,
					   MediaInfoCb* mediaInfoCb,
					   AsyncCallerCb openResultCb,
					   void* udata)
{
	assert((0 <= nstream) && ((size_t)nstream < _streamList.size()));
	_streamListIterator = _streamList.begin();
	while (nstream-- && _streamListIterator != _streamList.end()) {
		_streamListIterator++;
	}

	if (_streamListIterator != _streamList.end()) {
		Stream* stream = *_streamListIterator;	assert(stream);
		return stream->OpenMedia(mediaInfoCb, openResultCb, udata);
	}

	return false;
}


void Camera::CloseMedia(INT32 nstream)
{
	assert((0 <= nstream) && ((size_t)nstream < _streamList.size()));
	_streamListIterator = _streamList.begin();
	while (nstream-- && _streamListIterator != _streamList.end()) {
		_streamListIterator++;
	}
	Stream* stream = *_streamListIterator;	assert(stream);
	stream->CloseMedia();
}


CoreApiVSize Camera::GetStreamMediaVideoSize(INT32 nstream)
{
	assert((0 <= nstream) && ((size_t)nstream < _streamList.size()));
	_streamListIterator = _streamList.begin();
	while (nstream-- && _streamListIterator != _streamList.end()) {
		_streamListIterator++;
	}
	Stream* stream = *_streamListIterator;	assert(stream);
	return stream->GetMediaVideoSize();
}


// static callback functions
void Camera::enum_stream_on_result(void* udata,
								   CoreApiObj obj,
								   CoreApiAsyncCallerObj caller,
								   CoreApiResultObj result)
{
	Camera* camera = reinterpret_cast<Camera*>(udata); assert(camera);
	camera->EnumStreamResult(result);
}


// protected:
void Camera::ClearStreamList()
{
	if (_streamList.size() > 0) {
		_streamListIterator = _streamList.begin();
		while (_streamListIterator != _streamList.end()) {
			Stream* stream = *_streamListIterator++;
			delete stream;
		}
		_streamList.clear();
	}
}


void Camera::CreateStreamList()
{
	ClearStreamList();

	assert(core_api_obj_is_valid(_helperStreamEnumeratorObj));
	int stream_count = core_api_helper_stream_enumerator_count(_helperStreamEnumeratorObj);
	for (int i = 0; i < stream_count; i++) {
		CoreApiDeviceStreamObj streamObj = core_api_helper_stream_enumerator_get_stream_ref(
			_helperStreamEnumeratorObj, i);
		if (CORE_API_STREAM_TYPE_IMAGE == core_api_device_stream_view_stream_type(streamObj)) {
			core_api_device_stream_unref(streamObj);
			continue;
		}

		Stream* stream = new Stream(streamObj);
		core_api_device_stream_unref(streamObj);

		if (CORE_API_STREAM_TYPE_MAIN == core_api_device_stream_view_stream_type(streamObj)) {
			_streamList.push_front(stream);
		}

		if (CORE_API_STREAM_TYPE_MOBILE == core_api_device_stream_view_stream_type(streamObj)) {
			_streamList.push_back(stream);
		}
	}
}


// called by the callback functions
void Camera::EnumStreamResult(CoreApiResultObj result)
{
	assert(core_api_obj_is_valid(result));
	int code = core_api_result_get_code(result);
	if (100 < code && code < CORE_API_RESULT_OK->code) {
		return;
	} else {
		bool success = code == CORE_API_RESULT_OK->code;
		if (success) {
			CreateStreamList();
		}
		async_caller_unref_later(_callerObj);
		if (_enumStreamResultCb) {
			_enumStreamResultCb(this, success, code,
								core_api_result_get_phrase(result),
								_udata);
		}
	}
}

NAMESPACE_END
