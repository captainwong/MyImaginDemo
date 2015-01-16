#include "stdafx.h"
#include "device.h"
#include "stream.h"
#include "camera.h"
#include "Timer.h"

NAMESPACE_BEGIN(Imagin)

static const int RE_ENUM_CAMERA_INTERVAL = 10 * 1000;

DECLARE_CALLBACK_IMAGIN(enum_camera_on_result, Device, EnumCameraOnResult)
DECLARE_CALLBACK_TIMER(re_enum_camera, Device, EnumCamera)
DECLARE_CALLBACK_USER(enum_stream_on_result, Device, EnumStreamOnResult)

Device::Device(CoreApiDevManagerObj devMngrObj, CoreApiDevObj devObj)
	: _deviceUid()
	, _deviceProductName()
	, _deviceProductDesc()
	, _deviceState(DS_OFFLINE)
	, _cameraState(CS_NONE)
	, _deviceObj(CORE_API_INVALID_OBJ)
	, _udataCameraState(NULL)
	, _udataDeviceState(NULL)
	, _helperCameraEnumeratorObj(CORE_API_INVALID_OBJ)
	, _callerObj(CORE_API_INVALID_OBJ)
	, _deviceStateChangeCb(NULL)
	, _cameraStateChangeCb(NULL)
{
	assert(core_api_obj_is_valid(devMngrObj));
	assert(core_api_obj_is_valid(devObj));

	_devObj = core_api_dev_ref(devObj);
	_devMngrObj = core_api_dev_manager_ref(devMngrObj);

	_callerCb.on_result = enum_camera_on_result;
	_callerCb.udata = this;

	memset(&_deviceCb, 0, sizeof(_deviceCb));
	_deviceCb.udata = this;

	CoreApiDevInfoObj devInfoObj = core_api_dev_get_info_ref(devObj);
	_deviceUid = core_api_dev_info_get_uid(devInfoObj);
	_deviceProductName = core_api_dev_info_get_product_name(devInfoObj);
	_deviceProductDesc = core_api_dev_info_get_product_desc(devInfoObj);
	core_api_dev_info_unref(devInfoObj);

	_timer = new CTimer(re_enum_camera, this);
}


Device::~Device()
{
	async_caller_cancel_and_unref_later(_callerObj);

	if (core_api_obj_is_valid(_helperCameraEnumeratorObj)) {
		core_api_helper_camera_enumerator_unref_later(_helperCameraEnumeratorObj);
		_helperCameraEnumeratorObj = CORE_API_INVALID_OBJ;
	}

	ClearCameraList();

	if (core_api_obj_is_valid(_deviceObj)) {
		core_api_device_unref(_deviceObj);
		_deviceObj = CORE_API_INVALID_OBJ;
	}

	if (core_api_obj_is_valid(_devObj)) {
		core_api_dev_unref(_devObj);
		_devObj = CORE_API_INVALID_OBJ;
	}

	if (core_api_obj_is_valid(_devMngrObj)) {
		core_api_dev_manager_unref(_devMngrObj);
		_devMngrObj = CORE_API_INVALID_OBJ;
	}

	delete _timer;	_timer = NULL;
}


const char* Device::GetDeviceName() const
{
	CoreApiDevInfoObj devInfo = core_api_dev_get_info_ref(_devObj);
	const char* devName = core_api_dev_info_get_dev_name(devInfo);
	core_api_dev_info_unref(devInfo);
	return devName;
}


const char* Device::GetDeviceAliasName() const
{
	CoreApiDevInfoObj devInfo = core_api_dev_get_info_ref(_devObj);
	const char* aliasName = core_api_dev_info_get_alias_name(devInfo);
	core_api_dev_info_unref(devInfo);
	return aliasName;
}


void Device::EnumCamera()
{
	async_caller_cancel_and_unref_later(_callerObj);

	if (core_api_obj_is_valid(_helperCameraEnumeratorObj)) {
		core_api_helper_camera_enumerator_unref_later(_helperCameraEnumeratorObj);
		_helperCameraEnumeratorObj = CORE_API_INVALID_OBJ;
	}

	ClearCameraList();

	do {
		if (_deviceState != DS_READY)
			break;

		_helperCameraEnumeratorObj = core_api_device_create_camera_enumerator(_deviceObj);
		if (!core_api_obj_is_valid(_helperCameraEnumeratorObj))
			break;

		core_api_helper_camera_enumerator_enum(_helperCameraEnumeratorObj, 
											   &_callerCb, 
											   &_callerObj);

		SetCameraState(CS_GETTING);
	} while (0);
}


void Device::SetDeviceEvent(DeviceEvent deviceEvent)
{
	switch (deviceEvent) {
		case DE_ONLINE:
		case DE_UNUSEABLE:
			SetDeviceState(DS_ONLINE);
			break;
		case DE_USEABLE:
			if (CreateDeviceObj()) {
				SetDeviceState(DS_READY);
			}
			break;
		case DE_ADD:
		case DE_OFFLINE:
		default:
			SetDeviceState(DS_OFFLINE);
			break;
	}
}


bool Device::OpenMedia(INT32 ncamera,
					   INT32 nstream,
					   MediaInfoCb* mediaInfoCb,
					   AsyncCallerCb openResultCb,
					   void* udata)
{
	if (0 <= ncamera && (size_t)ncamera < _cameraList.size()) {
		_cameraListIterator = _cameraList.begin();
		while (ncamera-- && (_cameraListIterator != _cameraList.end())) {
			_cameraListIterator++;
		}
		if (_cameraListIterator != _cameraList.end()) {
			Camera* camera = *_cameraListIterator; assert(camera);
			return camera->OpenMedia(nstream, mediaInfoCb, openResultCb, udata);
		}
	}
	return false;
}


void Device::CloseMedia(INT32 ncamera, INT32 nstream)
{
	if (0 <= ncamera && (size_t)ncamera < _cameraList.size()) {
		_cameraListIterator = _cameraList.begin();
		while (ncamera-- && (_cameraListIterator != _cameraList.end())) {
			_cameraListIterator++;
		}
		if (_cameraListIterator != _cameraList.end()) {
			Camera* camera = *_cameraListIterator; assert(camera);
			camera->CloseMedia(nstream);
		}
	}
}


// static callback functions
//void Device::enum_camera_on_result(void* udata,
//								   CoreApiObj,
//								   CoreApiAsyncCallerObj,
//								   CoreApiResultObj result)
//{
//	Device* device = reinterpret_cast<Device*>(udata); assert(device);
//	device->EnumCameraOnResult(result);
//}



//void __stdcall Device::re_enum_camera(CTimer* timer, void* udata)
//{
//	Device* device = reinterpret_cast<Device*>(udata); assert(device);
//	device->EnumCamera();
//}


//void __stdcall Device::enum_stream_on_result(Camera* camera,
//											 bool success,
//											 int code,
//											 const char* phrase,
//											 void* udata)
//{
//	Device* device = reinterpret_cast<Device*>(udata); assert(device);
//	device->EnumStreamOnResult(success, code, phrase);
//}

// protected: called by those callback functions
void Device::EnumCameraOnResult(CoreApiResultObj result)
{
	do {
		if (_deviceState != DS_READY)
			break;

		int code = core_api_result_get_code(result);
		const char* phrase = core_api_result_get_phrase(result);
		
		if (code == CORE_API_RESULT_OK->code) {
			CreateCameraList();
		} else if ((100 < code) && (code < CORE_API_RESULT_OK->code)) {
			// continue to enum camera
			return;
		} else {
			SetCameraState(CS_GETFAILED);
			_timer->Start(RE_ENUM_CAMERA_INTERVAL);
		}
	} while (0);

	async_caller_unref_later(_callerObj);
}


void Device::EnumStreamOnResult(bool success, int code, const char* phrase)
{
	if (success) {
		SetCameraState(CS_READY);
	} else {
		SetCameraState(CS_GETFAILED);
		_timer->Start(RE_ENUM_CAMERA_INTERVAL);
	}
}


// protected
void Device::ClearCameraList()
{
	_cameraListIterator = _cameraList.begin();
	while (_cameraListIterator != _cameraList.end()) {
		Camera* camera = *_cameraListIterator++;
		delete camera;
	}
	_cameraList.clear();
}


bool Device::CreateCameraList()
{
	if (_deviceState != DS_READY)
		return false;

	if (!core_api_obj_is_valid(_helperCameraEnumeratorObj))
		return false;

	int count = core_api_helper_camera_enumerator_count(_helperCameraEnumeratorObj);
	for (int i = 0; i < count; i++) {
		CoreApiDeviceCameraObj deviceCameraObj = 
			core_api_helper_camera_enumerator_get_camera_ref(_helperCameraEnumeratorObj, i);
		Camera* camera = new Camera(deviceCameraObj, enum_stream_on_result, this);
		core_api_device_camera_unref(deviceCameraObj);
		_cameraList.push_back(camera);
	}

	return true;
}


void Device::SetDeviceState(DeviceState deviceState)
{
	_deviceState = deviceState;

	if (_deviceStateChangeCb != NULL) {
		_deviceStateChangeCb(this, _deviceState, _udataDeviceState);
	}

	if (_deviceState == DS_READY) {
		EnumCamera();
	} else {
		SetCameraState(CS_NONE);
	}
}


void Device::SetCameraState(CameraState cameraState)
{
	_cameraState = cameraState;

	if (_cameraState != CS_READY) {
		ClearCameraList();
	}

	if (_cameraStateChangeCb != NULL) {
		_cameraStateChangeCb(this, _cameraState, _udataCameraState);
	}
}


bool Device::CreateDeviceObj()
{
	if (core_api_obj_is_valid(_deviceObj)) {
		core_api_device_unref(_deviceObj);
		_deviceObj = CORE_API_INVALID_OBJ;
	}

	do {
		if (!core_api_obj_is_valid(_devObj))		break;
		if (!core_api_obj_is_valid(_devMngrObj))	break;
		_deviceObj = core_api_dev_manager_create_device(_devMngrObj, _devObj, &_deviceCb);
		if (!core_api_obj_is_valid(_deviceObj))		break;
		return true;
	} while (0);

	return false;
}




NAMESPACE_END
