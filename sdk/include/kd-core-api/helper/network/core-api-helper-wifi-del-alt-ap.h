/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperWifiDelAltAp header file.
 *
 * Definitions of KdCoreApiHelperWifiDelAltAp class.
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

#ifndef CORE_API_HELPER_WIFI_DEL_ALT_AP_H_
#define CORE_API_HELPER_WIFI_DEL_ALT_AP_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-wifi-ap.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiHelperWifiDelAltApObj;

CORE_API_EXPORT CoreApiHelperWifiDelAltApObj core_api_helper_wifi_del_alt_ap_ref(CoreApiHelperWifiDelAltApObj del_alt_ap);
CORE_API_EXPORT void core_api_helper_wifi_del_alt_ap_unref_later(CoreApiHelperWifiDelAltApObj del_alt_ap);

CORE_API_EXPORT void core_api_helper_wifi_del_alt_ap_del(CoreApiHelperWifiDelAltApObj del_alt_ap, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_EXPORT void core_api_helper_wifi_del_alt_ap_edit_ap(CoreApiHelperWifiDelAltApObj del_alt_ap, CoreApiWifiApObj ap);

CORE_API_EXPORT void core_api_helper_wifi_del_alt_ap_edit_ap_ssid(CoreApiHelperWifiDelAltApObj del_alt_ap, const char* ssid);


CORE_API_END_DECLS



#endif /* CORE_API_HELPER_WIFI_DEL_ALT_AP_H_ */

/**
 * @}
 */
