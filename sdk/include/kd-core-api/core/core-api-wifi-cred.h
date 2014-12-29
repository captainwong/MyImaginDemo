/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiWifiCred header file.
 *
 * Definitions of KdCoreApiWifiCred class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-12-28 zhuangzhida@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_WIFI_CRED_H_
#define CORE_API_WIFI_CRED_H_

#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiWifiCredObj;

/**
 * CoreApiWifiCred
 * {
 *      char * psk;
 * }
 *
 *
 */

CORE_API_EXPORT CoreApiWifiCredObj core_api_wifi_cred_new();
CORE_API_EXPORT CoreApiWifiCredObj core_api_wifi_cred_new_full(const char *psk);
CORE_API_EXPORT CoreApiWifiCredObj core_api_wifi_cred_ref(CoreApiWifiCredObj obj);
CORE_API_EXPORT void core_api_wifi_cred_unref(CoreApiWifiCredObj obj);
CORE_API_EXPORT void core_api_wifi_cred_set_psk(CoreApiWifiCredObj cred, const char *psk);
CORE_API_EXPORT const char * core_api_wifi_cred_get_psk(CoreApiWifiCredObj cred);




CORE_API_END_DECLS



#endif /* CORE_API_WIFI_CRED_H_ */

/**
 * @}
 */
