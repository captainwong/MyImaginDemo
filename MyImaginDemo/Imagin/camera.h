#pragma once

#include <list>
#include "global.h"


namespace Imagin
{




class Stream;
class Camera
{
	DECLARE_UNCOPYABLE(Camera)
public:

private:
	CoreApiDeviceCameraObj				_deviceCameraObj;
	CoreApiAsyncCallerObj				_callerObj;
	CoreApiAsyncCallerCb				_callerCb;
	AsyncCallerCb						_enumStreamResultCb;
	CoreApiHelperStreamEnumeratorObj	_helperStreamEnumeratorObj;
	std::list<Stream*>					_streamList;
	std::list<Stream*>::iterator		_streamListIterator;
	void*								_udata;
	Camera() {}

public:
	
	Camera(const CoreApiDeviceCameraObj cameraObj,
		   AsyncCallerCb enumStreamResultCb,
		   void* udata);

	~Camera();

	bool EnumStream();

	bool OpenMedia(INT32 nstream,
				   MediaInfoCb* mediaInfoCb,
				   AsyncCallerCb openResultCb,
				   void* udata);

	void CloseMedia(INT32 nstream);

	CoreApiVSize GetStreamMediaVideoSize(INT32 nstream);

	INT32 GetStreamCount() const
	{
		return _streamList.size();
	}

protected:
	// static callback functions
	/*static void enum_stream_on_result(void* udata,
									  CoreApiObj obj,
									  CoreApiAsyncCallerObj caller,
									  CoreApiResultObj result);*/

protected:

	void ClearStreamList();

	void CreateStreamList();

public:
	// called by the callback functions
	void EnumStreamOnResult(CoreApiResultObj result);
};


NAMESPACE_END
