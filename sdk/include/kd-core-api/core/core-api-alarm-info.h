
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiAlarmInfo header file.
 *
 * Definitions of KdCoreApiAlarmInfo class.
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-4-18 zhuangzhida@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_ALARM_INFO_H_
#define CORE_API_ALARM_INFO_H_


#include "time.h"
#if defined(_MSC_VER)
#include "WinSock2.h"  //" struct timeval
#else
#include "sys/time.h"
#endif


#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiAlarmInfoObj;

CORE_API_EXPORT CoreApiAlarmInfoObj core_api_alarm_info_new();
CORE_API_EXPORT CoreApiAlarmInfoObj core_api_alarm_info_ref(CoreApiAlarmInfoObj alarminfo);
CORE_API_EXPORT void core_api_alarm_info_unref(CoreApiAlarmInfoObj alarminfo);

CORE_API_EXPORT const char* core_api_alarm_info_get_id(CoreApiAlarmInfoObj alarminfo);
CORE_API_EXPORT const char* core_api_alarm_info_get_name(CoreApiAlarmInfoObj alarminfo);
CORE_API_EXPORT const char* core_api_alarm_info_get_full(CoreApiAlarmInfoObj alarminfo);
CORE_API_EXPORT struct timeval core_api_alarm_info_get_timeval(CoreApiAlarmInfoObj alarminfo);


CORE_API_END_DECLS

#endif /* CORE_API_ALARM_INFO_H_ */

/**
 * @}
 */
