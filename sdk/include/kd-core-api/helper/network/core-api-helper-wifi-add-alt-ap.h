
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperWifiAddAltApObj header file.
 *
 * Definitions of KdCoreApiHelperWifiAddAltApObj class.
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


#ifndef CORE_API_HELPER_WIFI_ADD_ALT_AP_H_
#define CORE_API_HELPER_WIFI_ADD_ALT_AP_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-wifi-ap.h"
#include "core/core-api-wifi-cred.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiHelperWifiAddAltApObj;

CORE_API_EXPORT CoreApiHelperWifiAddAltApObj core_api_helper_wifi_add_alt_ap_ref(CoreApiHelperWifiAddAltApObj add_alt_ap);
CORE_API_EXPORT void core_api_helper_wifi_add_alt_ap_unref_later(CoreApiHelperWifiAddAltApObj add_alt_ap);

CORE_API_EXPORT void core_api_helper_wifi_add_alt_ap_add(CoreApiHelperWifiAddAltApObj add_alt_ap, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_EXPORT void core_api_helper_wifi_add_alt_ap_edit_ap(CoreApiHelperWifiAddAltApObj add_alt_ap, CoreApiWifiApObj ap);

CORE_API_EXPORT void core_api_helper_wifi_add_alt_ap_edit_cred(CoreApiHelperWifiAddAltApObj add_alt_ap, CoreApiWifiCredObj cred);

CORE_API_END_DECLS

#endif /* CORE_API_HELPER_WIFI_ADD_ALT_AP_H_ */

/**
 * @}
 */
