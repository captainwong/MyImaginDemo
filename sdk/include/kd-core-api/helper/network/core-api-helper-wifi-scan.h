
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperWifiScan header file.
 *
 * Definitions of KdCoreApiHelperWifiScan class.
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




#ifndef CORE_API_HELPER_WIFI_SCAN_H_
#define CORE_API_HELPER_WIFI_SCAN_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiHelperWifiScanObj;


/** CoreApiHelperWifiScan */
CORE_API_EXPORT CoreApiHelperWifiScanObj core_api_helper_wifi_scan_ref(CoreApiHelperWifiScanObj wifi_wps);
CORE_API_EXPORT void core_api_helper_wifi_scan_unref_later(CoreApiHelperWifiScanObj wifi_wps);
/**
 * async operation;
 */
CORE_API_EXPORT void core_api_helper_wifi_scan_scan(CoreApiHelperWifiScanObj wifi_wps, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);


CORE_API_END_DECLS

#endif /* CORE_API_HELPER_WIFI_SCAN_H_ */

/**
 * @}
 */
