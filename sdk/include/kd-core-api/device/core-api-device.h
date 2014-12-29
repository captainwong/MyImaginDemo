
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDevice header file.
 *
 * Definitions of KdCoreApiDevice class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-18 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_DEVICE_H_
#define CORE_API_DEVICE_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-result.h"
#include "core/core-api-dev-info.h"

#include "device/core-api-device-alarm-event.h"




CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDeviceObj;

typedef struct
{
    void *              udata;

    void                (*subs_alarm_event)(void *udata, CoreApiDeviceObj device, CoreApiResultObj rslt);
    void                (*unsubs_alarm_event)(void *udata, CoreApiDeviceObj device, CoreApiResultObj rslt);
    void                (*alarm_event)(void *udata, CoreApiDeviceObj device, CoreApiDeviceAlarmEventObj event);
}CoreApiDeviceCb;

/** device */
CORE_API_EXPORT CoreApiDeviceObj core_api_device_ref(CoreApiDeviceObj device);
CORE_API_EXPORT void core_api_device_unref(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiDevInfoObj core_api_device_get_info_ref(CoreApiDeviceObj device);

CORE_API_EXPORT void core_api_device_enable_subs_alarm_event(CoreApiDeviceObj device);
CORE_API_EXPORT void core_api_device_disable_subs_alarm_event(CoreApiDeviceObj device);

CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_H_ */

/**
 * @}
 */
