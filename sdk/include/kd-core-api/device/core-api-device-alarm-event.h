
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDeviceAlarmEvent header file.
 *
 * Definitions of KdCoreApiDeviceAlarmEvent class.
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




#ifndef CORE_API_DEVICE_ALARM_EVENT_H_
#define CORE_API_DEVICE_ALARM_EVENT_H_


#include "time.h"
#if defined(_MSC_VER)
#include "WinSock2.h"  //" struct timeval
#else
#include "sys/time.h"
#endif

#include "core/core-api-global.h"
#include "core/core-api-obj.h"

#include "device/core-api-device-alarm-event-args.h"

CORE_API_BEGIN_DECLS

/** event */
typedef CoreApiObj CoreApiDeviceAlarmEventObj;


/**
 * try create CoreApiDeviceAlarmEvent from event-record item.
 *
 * @see core_api_alarm_info_get_full()
 *
 * @retval CORE_API_INVALID_OBJ if failed.
 */
CORE_API_EXPORT CoreApiDeviceAlarmEventObj core_api_device_alarm_event_try_new_from_full(const char *full);
CORE_API_EXPORT CoreApiDeviceAlarmEventObj core_api_device_alarm_event_ref(CoreApiDeviceAlarmEventObj event);
CORE_API_EXPORT void core_api_device_alarm_event_unref(CoreApiDeviceAlarmEventObj event);


/** event attribute */
CORE_API_EXPORT const char * core_api_device_alarm_event_get_id(CoreApiDeviceAlarmEventObj event);
CORE_API_EXPORT const char * core_api_device_alarm_event_get_name(CoreApiDeviceAlarmEventObj event);
CORE_API_EXPORT const struct timeval * core_api_device_alarm_event_get_tv_utc(CoreApiDeviceAlarmEventObj event);


/** event args */
CORE_API_EXPORT CoreApiDeviceAlarmEventArgsStructObj core_api_device_alarm_event_get_args(CoreApiDeviceAlarmEventObj event);




CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_ALARM_EVENT_H_ */

/**
 * @}
 */
