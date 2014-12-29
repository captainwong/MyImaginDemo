
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperSensor header file.
 *
 * Definitions of KdCoreApiHelperSensor class.
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




#ifndef CORE_API_HELPER_SENSOR_H_
#define CORE_API_HELPER_SENSOR_H_


#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperSensorObj;



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
CORE_API_EXPORT CoreApiHelperSensorObj core_api_helper_sensor_ref(CoreApiHelperSensorObj sensor);
CORE_API_EXPORT void core_api_helper_sensor_unref_later(CoreApiHelperSensorObj sensor);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_sensor_get(CoreApiHelperSensorObj sensor, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_sensor_set(CoreApiHelperSensorObj sensor, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view/edit
 */
CORE_API_EXPORT uint32_t core_api_helper_sensor_view_saturation(CoreApiHelperSensorObj sensor);
CORE_API_EXPORT void core_api_helper_sensor_edit_saturation(CoreApiHelperSensorObj sensor, uint32_t saturation);

CORE_API_EXPORT uint32_t core_api_helper_sensor_view_brightness(CoreApiHelperSensorObj sensor);
CORE_API_EXPORT void core_api_helper_sensor_edit_brightness(CoreApiHelperSensorObj sensor, uint32_t brightness);

CORE_API_EXPORT uint32_t core_api_helper_sensor_view_contrast(CoreApiHelperSensorObj sensor);
CORE_API_EXPORT void core_api_helper_sensor_edit_contrast(CoreApiHelperSensorObj sensor, uint32_t contrast);

CORE_API_EXPORT uint32_t core_api_helper_sensor_view_upsidedown(CoreApiHelperSensorObj sensor);
CORE_API_EXPORT void core_api_helper_sensor_edit_upsidedown(CoreApiHelperSensorObj sensor, uint32_t upsidedown);

CORE_API_EXPORT uint32_t core_api_helper_sensor_view_mirror(CoreApiHelperSensorObj sensor);
CORE_API_EXPORT void core_api_helper_sensor_edit_mirror(CoreApiHelperSensorObj sensor, uint32_t mirror);

CORE_API_END_DECLS

#endif /* CORE_API_HELPER_SENSOR_H_ */

/**
 * @}
 */
