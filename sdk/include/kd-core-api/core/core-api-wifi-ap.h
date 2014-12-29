
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiWifiAp header file.
 *
 * Definitions of KdCoreApiWifiAp class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-01-01 zhuangzhida@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_WIFI_AP_H_
#define CORE_API_WIFI_AP_H_

#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiWifiApObj;



/**
 * CoreApiWifiAp
 * {
 *      char *      ssid;       //" string
 *      char *      bssid;      //" mac-address, such as 00:11:22:33:44:55
 *      uint32_t    wps;       //" [0,1]
 *      uint32_t    quality;    //" [0,100]
 * }
 */

CORE_API_EXPORT CoreApiWifiApObj core_api_wifi_ap_new();
CORE_API_EXPORT CoreApiWifiApObj core_api_wifi_ap_ref(CoreApiWifiApObj ap);
CORE_API_EXPORT void core_api_wifi_ap_unref(CoreApiWifiApObj ap);


CORE_API_EXPORT const char * core_api_wifi_ap_get_ssid(CoreApiWifiApObj ap);
CORE_API_EXPORT const char * core_api_wifi_ap_get_bssid(CoreApiWifiApObj ap);
CORE_API_EXPORT uint32_t core_api_wifi_ap_get_wps(CoreApiWifiApObj ap);
CORE_API_EXPORT uint32_t core_api_wifi_ap_get_quality(CoreApiWifiApObj ap);
CORE_API_EXPORT void core_api_wifi_ap_set_ssid(CoreApiWifiApObj ap, const char * ssid);
CORE_API_EXPORT void core_api_wifi_ap_set_bssid(CoreApiWifiApObj ap, const char * bssid);



CORE_API_END_DECLS

#endif /* CORE_API_WIFI_AP_H_ */

/**
 * @}
 */
