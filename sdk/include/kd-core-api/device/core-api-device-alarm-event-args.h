
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiDeviceAlarmEventArgsStruct header file.
 *
 * Definitions of CoreApiDeviceAlarmEventArgsStruct class.
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-6-9 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_DEVICE_ALARM_EVENT_ARGS_H_
#define CORE_API_DEVICE_ALARM_EVENT_ARGS_H_

#include "stdint.h"             //" uint32_t

#include "time.h"
#if defined(_MSC_VER)
#include "WinSock2.h"  //" struct timeval
#else
#include "sys/time.h"
#endif


#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiDeviceAlarmEventArgsStructObj;

CORE_API_EXPORT CoreApiDeviceAlarmEventArgsStructObj core_api_device_alarm_event_args_struct_ref(CoreApiDeviceAlarmEventArgsStructObj strt);
CORE_API_EXPORT void core_api_device_alarm_event_args_struct_unref(CoreApiDeviceAlarmEventArgsStructObj strt);

/**
 * get value by key from args-struct
 *
 * @return boolean
 */
CORE_API_EXPORT int core_api_device_alarm_event_args_struct_get_boolean(CoreApiDeviceAlarmEventArgsStructObj strt, const char *key, int *value);
CORE_API_EXPORT int core_api_device_alarm_event_args_struct_get_int(CoreApiDeviceAlarmEventArgsStructObj strt,     const char *key, int32_t *value);
CORE_API_EXPORT int core_api_device_alarm_event_args_struct_get_double(CoreApiDeviceAlarmEventArgsStructObj strt,  const char *key, double *value);
CORE_API_EXPORT int core_api_device_alarm_event_args_struct_get_tv(CoreApiDeviceAlarmEventArgsStructObj strt,      const char *key, struct timeval *value);
CORE_API_EXPORT int core_api_device_alarm_event_args_struct_get_string(CoreApiDeviceAlarmEventArgsStructObj strt,  const char *key, const char  **value);

/**
 * get struct from struct by key.
 *
 * the returned struct is a ref, you MUST use core_api_device_alarm_event_args_struct_unref() to release it
 */
CORE_API_EXPORT int core_api_device_alarm_event_args_struct_get_struct_ref(CoreApiDeviceAlarmEventArgsStructObj strt,const char *key, CoreApiDeviceAlarmEventArgsStructObj *value);

CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_ALARM_EVENT_ARGS_H_ */

/**
 * @}
 */
