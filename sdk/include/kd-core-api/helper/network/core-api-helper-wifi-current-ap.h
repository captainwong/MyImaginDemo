
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperWifiCurrentAp header file.
 *
 * Definitions of KdCoreApiHelperWifiCurrentAp class.
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

#ifndef CORE_API_HELPER_WIFI_CURRENT_AP_H_
#define CORE_API_HELPER_WIFI_CURRENT_AP_H_
#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-wifi-ap.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiHelperWifiCurrentApObj;

CORE_API_EXPORT CoreApiHelperWifiCurrentApObj core_api_helper_wifi_current_ap_ref(CoreApiHelperWifiCurrentApObj cur_ap);
CORE_API_EXPORT void core_api_helper_wifi_current_ap_unref_later(CoreApiHelperWifiCurrentApObj cur_ap);

CORE_API_EXPORT void core_api_helper_wifi_current_ap_get(CoreApiHelperWifiCurrentApObj cur_ap, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_EXPORT CoreApiWifiApObj core_api_helper_wifi_current_ap_view_ap_ref(CoreApiHelperWifiCurrentApObj cur_ap);



CORE_API_END_DECLS


#endif /* CORE_API_HELPER_WIFI_CURRENT_AP_H_ */

/**
 * @}
 */
