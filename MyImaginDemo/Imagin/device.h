#pragma once

#include "global.h"
#include <string>
#include <list>

namespace Imagin
{

class CTimer;
class Device;
class Stream;
class Camera;

typedef void(__stdcall *DeviceStateChangeCb)(Device* device,
											 DeviceState deviceState,
											 void* udata);

typedef void(__stdcall *CameraStateChangeCb)(Device* device,
											 CameraState cameraState,
											 void* udata);


class Device
{
	DECLARE_UNCOPYABLE(Device)
public:
	Device(CoreApiDevManagerObj devMngrObj, CoreApiDevObj devObj);
	
	~Device();

	const char* GetDeviceName() const;

	const char* GetDeviceAliasName() const;

	const char* GetDeviceUid() const { return _deviceUid.c_str(); }

	const char* GetDevcieProductName() const { return _deviceProductName.c_str(); }

	const char* GetDeviceProductDesc() const { return _deviceProductDesc.c_str(); }

	const CoreApiDevObj GetDevObj() const { return _devObj; }

	const CoreApiDeviceObj GetDeciveObj() const { return _deviceObj; }

	DeviceState GetDeviceState() const { return _deviceState; }

	CameraState GetCameraState() const { return _cameraState; }

	bool IsDeviceReady() const { return _deviceState == DS_READY; }

	bool IsCameraReady() const { return _cameraState == CS_READY; }

	void EnumCamera();

	void SetDeviceEvent(DeviceEvent deviceEvent);

	bool OpenMedia(INT32 ncamera, 
				   INT32 nstream, 
				   MediaInfoCb* mediaInfoCb, 
				   AsyncCallerCb openResultCb, 
				   void* udata);

	void CloseMedia(INT32 ncamera, INT32 nstream);
	
protected:	// static callback functions
	/*static void enum_camera_on_result(void*,
									  CoreApiObj,
									  CoreApiAsyncCallerObj,
									  CoreApiResultObj);

	static void __stdcall re_enum_camera(CTimer* timer, void* udata);

	static void __stdcall enum_stream_on_result(Camera* camera,
												bool success,
												int code,
												const char* phrase,
												void* udata);
	*/
public:	// called by those callback functions
	void EnumCameraOnResult(CoreApiResultObj result);

	void EnumStreamOnResult(FUNCTION_PARAMETER_USER_3);

protected:

	void ClearCameraList();

	bool CreateCameraList();

	void SetDeviceState(DeviceState deviceState);

	void SetCameraState(CameraState cameraState);

	bool CreateDeviceObj();

private:
	Device() {}

	std::string _deviceUid;
	std::string _deviceProductName;
	std::string _deviceProductDesc;

	DeviceState _deviceState;
	CameraState _cameraState;

	CoreApiDevObj						_devObj;
	CoreApiDevManagerObj				_devMngrObj;
	CoreApiDeviceObj					_deviceObj;
	CoreApiDeviceCb						_deviceCb;
	CoreApiHelperCameraEnumeratorObj	_helperCameraEnumeratorObj;
	CoreApiAsyncCallerObj				_callerObj;
	CoreApiAsyncCallerCb				_callerCb;

	DeviceStateChangeCb _deviceStateChangeCb;
	CameraStateChangeCb _cameraStateChangeCb;
	void* _udataDeviceState;
	void* _udataCameraState;

	std::list<Camera*> _cameraList;
	std::list<Camera*>::iterator _cameraListIterator;

	CTimer* _timer;
};

NAMESPACE_END
