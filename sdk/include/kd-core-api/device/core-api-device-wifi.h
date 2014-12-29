
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDeviceWifi header file.
 *
 * Definitions of KdCoreApiDeviceWifi class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-19 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_DEVICE_WIFI_H_
#define CORE_API_DEVICE_WIFI_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"

#include "helper/network/core-api-helper-wifi-ap-enumerator.h"
#include "helper/network/core-api-helper-wifi-alt-ap-enumerator.h"
#include "helper/network/core-api-helper-wifi-wps.h"
#include "helper/network/core-api-helper-wifi-scan.h"
#include "helper/network/core-api-helper-wifi-add-alt-ap.h"
#include "helper/network/core-api-helper-wifi-del-alt-ap.h"
#include "helper/network/core-api-helper-wifi-current-ap.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDeviceWifiObj;

#if 0
typedef struct
{
    void *              udata;

    void                (*ap_connected)(void *udata, CoreApiDeviceWifiObj wifi, CoreApiWifiApObj ap);
    void                (*ap_disconnected)(void *udata, CoreApiDeviceWifiObj wifi, CoreApiWifiApObj ap);
    void                (*ap_quality_changed)(void *udata, CoreApiDeviceWifiObj wifi, CoreApiWifiApObj ap);

    void                (*scan_done)(void *udata, CoreApiDeviceWifiObj wifi);
    void                (*wps_done)(void *udata, CoreApiDeviceWifiObj wifi);
}CoreApiDeviceWifiCb;



typedef struct
{
    void *              udata;

    void                (*on_result)(void *udata, CoreApiDeviceWifiObj wifi, CoreApiAsyncCallerObj caller, char *ssid[]);
}CoreApiDeviceWifiGetAltApCb;




CORE_API_EXPORT CoreApiDeviceWifiObj core_api_device_wifi_ref(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT void core_api_device_wifi_unref(CoreApiDeviceWifiObj wifi);
/**
 * subscribe/unsubscribe event
 * async operation
 */
CORE_API_EXPORT void core_api_device_wifi_subs_event(CoreApiDeviceWifiObj wifi, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_device_wifi_unsubs_event(CoreApiDeviceWifiObj wifi, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_EXPORT void core_api_device_wifi_scan(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT void core_api_device_wifi_wps(CoreApiDeviceWifiObj wifi);

/**
 * get connected AP.
 * this would be NULL if no AP connected.
 */
CORE_API_EXPORT CoreApiWifiApObj core_api_device_wifi_get_connected_ap_ref(CoreApiDeviceWifiObj wifi);


CORE_API_EXPORT CoreApiHelperWifiApEnumeratorObj core_api_device_wifi_create_ap_enumerator(CoreApiDeviceWifiObj wifi);

CORE_API_EXPORT void core_api_device_wifi_get_alt_ap_list(CoreApiDeviceWifiObj wifi, const CoreApiDeviceWifiGetAltApCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_device_wifi_add_alt_ap(CoreApiDeviceWifiObj wifi, CoreApiWifiApObj ap, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_device_wifi_del_alt_ap(CoreApiDeviceWifiObj wifi, const char *ssid, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
#endif


CORE_API_EXPORT CoreApiDeviceWifiObj core_api_device_wifi_ref(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT void core_api_device_wifi_unref(CoreApiDeviceWifiObj wifi);

CORE_API_EXPORT CoreApiHelperWifiApEnumeratorObj core_api_device_wifi_create_ap_enumerator(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT CoreApiHelperWifiAltApEnumeratorObj core_api_device_wifi_create_alt_ap_enumerator(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT CoreApiHelperWifiScanObj core_api_device_wifi_create_scan(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT CoreApiHelperWifiWpsObj core_api_device_wifi_create_wps(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT CoreApiHelperWifiDelAltApObj core_api_device_wifi_create_del_alt_ap(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT CoreApiHelperWifiAddAltApObj core_api_device_wifi_create_add_alt_ap(CoreApiDeviceWifiObj wifi);
CORE_API_EXPORT CoreApiHelperWifiCurrentApObj core_api_device_wifi_create_current_ap(CoreApiDeviceWifiObj wifi);

CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_WIFI_H_ */

/**
 * @}
 */
