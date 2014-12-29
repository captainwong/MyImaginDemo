
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperRTSensor header file.
 *
 * Definitions of KdCoreApiHelperRTSensor class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-01-04 zhuangzhida@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_RT_SENSOR_H_
#define CORE_API_HELPER_RT_SENSOR_H_

#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiHelperRtSensorObj;

/**
 *  CoreApiHelperSensor
 * {
 *      uint32_t        saturation;         //" [0,100]
 *      uint32_t        brightness;         //" [0,100]
 *      uint32_t        contrast;           //" [0,100]
 *      uint32_t        upsidedown;         //" [0,1]
 *      uint32_t        mirror;             //" [0,1]
 * }
 */

CORE_API_EXPORT CoreApiHelperRtSensorObj core_api_helper_rt_sensor_ref(CoreApiHelperRtSensorObj rt_sensor);
CORE_API_EXPORT void core_api_helper_rt_sensor_unref_later(CoreApiHelperRtSensorObj rt_sensor);

CORE_API_EXPORT void core_api_helper_rt_sensor_set(CoreApiHelperRtSensorObj rt_sensor, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_EXPORT void core_api_helper_rt_sensor_edit_saturation(CoreApiHelperRtSensorObj rt_sensor, uint32_t saturation);
CORE_API_EXPORT void core_api_helper_rt_sensor_edit_brightness(CoreApiHelperRtSensorObj rt_sensor, uint32_t brightness);
CORE_API_EXPORT void core_api_helper_rt_sensor_edit_contrast(CoreApiHelperRtSensorObj rt_sensor, uint32_t constrast);
CORE_API_EXPORT void core_api_helper_rt_sensor_edit_upsidedown(CoreApiHelperRtSensorObj rt_sensor, uint32_t upsidedown);
CORE_API_EXPORT void core_api_helper_rt_sensor_edit_mirror(CoreApiHelperRtSensorObj rt_sensor, uint32_t mirror);


CORE_API_END_DECLS



#endif /* CORE_API_HELPER_RT_SENSOR_H_ */

/**
 * @}
 */
