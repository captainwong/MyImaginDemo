
/**
 * @addtogroup D510
 * @{
 */

/**
 * @brief    file description
 *
 *  file details
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-9-22 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef D510HB_API_HELPER_DEVICE_H_
#define D510HB_API_HELPER_DEVICE_H_

#include <kd-core-api.h>

/** helper */
#include <helper/d510hb-api-helper-alarm-server.h>

CORE_API_BEGIN_DECLS

CORE_API_EXPORT D510HbApiHelperAlarmServerObj core_api_device_create_d510hb_alarm_server(CoreApiDeviceObj device);

CORE_API_END_DECLS

#endif /* D510HB_API_HELPER_DEVICE_H_ */

/**
 * @}
 */
