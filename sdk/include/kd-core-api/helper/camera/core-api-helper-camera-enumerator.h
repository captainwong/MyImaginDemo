
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperCameraEnumerator header file.
 *
 * Definitions of KdCoreApiHelperCameraEnumerator class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-20 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_HELPER_CAMERA_ENUMERATOR_H_
#define CORE_API_HELPER_CAMERA_ENUMERATOR_H_

#include "stdint.h"                 //" int32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"

#include "device/core-api-device-camera.h"



CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperCameraEnumeratorObj;



/** CoreApiHelperCameraEnumerator */
CORE_API_EXPORT CoreApiHelperCameraEnumeratorObj core_api_helper_camera_enumerator_ref(CoreApiHelperCameraEnumeratorObj cameraenum);
CORE_API_EXPORT void core_api_helper_camera_enumerator_unref_later(CoreApiHelperCameraEnumeratorObj cameraenum);
/**
 * start enumerator
 * async operation.
 */
CORE_API_EXPORT void core_api_helper_camera_enumerator_enum(CoreApiHelperCameraEnumeratorObj cameraenum, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * loop each CoreApiDeviceCamera
 * @pre on_result() with success.
 */
CORE_API_EXPORT uint32_t core_api_helper_camera_enumerator_count(CoreApiHelperCameraEnumeratorObj cameraenum);
CORE_API_EXPORT CoreApiDeviceCameraObj core_api_helper_camera_enumerator_get_camera_ref(CoreApiHelperCameraEnumeratorObj cameraenum, uint32_t index);





CORE_API_END_DECLS

#endif /* CORE_API_HELPER_CAMERA_ENUMERATOR_H_ */

/**
 * @}
 */
