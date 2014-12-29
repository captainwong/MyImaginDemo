
/**
 * @addtogroup KdCoreApi
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
 * -# 2014-10-13 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_DEV_WIFI_TASK_H_
#define CORE_API_DEV_WIFI_TASK_H_

#include "stdint.h"     //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDevWifiTaskObj;

/**
 * devsn and devuid could not be NULL at the same time.
 *
 * @param [in]      devsn       sn of target dev, could be NULL.
 * @param [in]      devuid      uid of target dev, could be NULL.
 *
 */
CORE_API_EXPORT CoreApiDevWifiTaskObj core_api_dev_wifi_task_new_full(const char *ssid_utf8, const char *psk_utf8, const char *devsn, const char *devuid);
CORE_API_EXPORT CoreApiDevWifiTaskObj core_api_dev_wifi_task_ref(CoreApiDevWifiTaskObj task);
CORE_API_EXPORT void core_api_dev_wifi_task_unref(CoreApiDevWifiTaskObj task);




/**
 * after core_api_dev_wifi_task_start(),
 * CoreApiDevWifiTask will send taskrmation for loop,
 * interval_ms between every time.
 *
 * while timeout_sec reaches, it will sleep trynext_sec,
 * and then start send taskrmation again.
 *
 * user can stop it at any time by core_api_dev_wifi_task_stop().
 */
CORE_API_EXPORT void core_api_dev_wifi_task_start(CoreApiDevWifiTaskObj task);
CORE_API_EXPORT void core_api_dev_wifi_task_stop(CoreApiDevWifiTaskObj task);






















/**
 * if enc_by_key is set, ssid+psk will be encrypt by devsn or devuid.
 *
 * @default true
 * @retval  boolean
 */
CORE_API_EXPORT int core_api_dev_wifi_task_is_enc_by_key(CoreApiDevWifiTaskObj task);
CORE_API_EXPORT void core_api_dev_wifi_task_set_enc_by_key(CoreApiDevWifiTaskObj task, int enc);




/**
 * interval in milli-seconds
 * @default 10ms
 */
CORE_API_EXPORT uint32_t core_api_dev_wifi_task_get_interval(CoreApiDevWifiTaskObj task);
CORE_API_EXPORT void core_api_dev_wifi_task_set_interval(CoreApiDevWifiTaskObj task, uint32_t interval_ms);

/**
 * timeout in seconds
 * @default 4s
 */
CORE_API_EXPORT uint32_t core_api_dev_wifi_task_get_timeout(CoreApiDevWifiTaskObj task);
CORE_API_EXPORT void core_api_dev_wifi_task_set_timeout(CoreApiDevWifiTaskObj task, uint32_t timeout_sec);

/**
 * trynext in seconds
 * @default 5s
 */
CORE_API_EXPORT uint32_t core_api_dev_wifi_task_get_trynext(CoreApiDevWifiTaskObj task);
CORE_API_EXPORT void core_api_dev_wifi_task_set_trynext(CoreApiDevWifiTaskObj task, uint32_t trynext_sec);



CORE_API_END_DECLS

#endif /* CORE_API_DEV_WIFI_TASK_H_ */

/**
 * @}
 */
