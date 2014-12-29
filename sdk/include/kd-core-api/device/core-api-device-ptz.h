
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDevicePtz header file.
 *
 * Definitions of KdCoreApiDevicePtz class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-19 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_DEVICE_PTZ_H_
#define CORE_API_DEVICE_PTZ_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDevicePtzObj;



CORE_API_EXPORT CoreApiDevicePtzObj core_api_device_ptz_ref(CoreApiDevicePtzObj ptz);
CORE_API_EXPORT void core_api_device_ptz_unref(CoreApiDevicePtzObj ptz);



CORE_API_EXPORT void core_api_device_ptz_up(CoreApiDevicePtzObj ptz, int32_t step, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_device_ptz_down(CoreApiDevicePtzObj ptz, int32_t step, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_device_ptz_left(CoreApiDevicePtzObj ptz, int32_t step, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_device_ptz_right(CoreApiDevicePtzObj ptz, int32_t step, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_device_ptz_stop(CoreApiDevicePtzObj ptz, int32_t step, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);


CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_PTZ_H_ */

/**
 * @}
 */
