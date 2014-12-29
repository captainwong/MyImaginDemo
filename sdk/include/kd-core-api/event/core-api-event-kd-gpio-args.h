
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiEventKdGpioArgs header file.
 *
 * Definitions of CoreApiEventKdGpioArgs class.
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-6-12 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_EVENT_KD_GPIO_ARGS_H_
#define CORE_API_EVENT_KD_GPIO_ARGS_H_

#include "stdint.h"                 //" int32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"

#include "device/core-api-device-alarm-event-args.h"

#include "event/core-api-event-enums.h"


CORE_API_BEGIN_DECLS

#define CORE_API_EVENT_KD_GPIO_NAME     "kd-gpio"

typedef CoreApiObj CoreApiEventKdGpioArgsObj;

/**
 * this function could return CORE_API_INVALID_OBJ,
 * use core_api_obj_is_valid() to check it.
 */
CORE_API_EXPORT CoreApiEventKdGpioArgsObj core_api_event_kd_gpio_args_try_new_from_args(CoreApiDeviceAlarmEventArgsStructObj args);
CORE_API_EXPORT CoreApiEventKdGpioArgsObj core_api_event_kd_gpio_args_ref(CoreApiEventKdGpioArgsObj gpio);
CORE_API_EXPORT void core_api_event_kd_gpio_args_unref(CoreApiEventKdGpioArgsObj gpio);


CORE_API_EXPORT int32_t core_api_event_kd_gpio_args_get_id(CoreApiEventKdGpioArgsObj gpio);
CORE_API_EXPORT CoreApiEventAction core_api_event_kd_gpio_args_get_action(CoreApiEventKdGpioArgsObj gpio);


CORE_API_END_DECLS

#endif /* CORE_API_EVENT_KD_GPIO_ARGS_H_ */

/**
 * @}
 */
