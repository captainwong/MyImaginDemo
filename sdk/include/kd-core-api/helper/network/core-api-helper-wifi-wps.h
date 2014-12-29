
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperWifiWps header file.
 *
 * Definitions of KdCoreApiHelperWifiWps class.
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




#ifndef CORE_API_HELPER_WIFI_WPS_H_
#define CORE_API_HELPER_WIFI_WPS_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiHelperWifiWpsObj;


/** CoreApiHelperWifiWPS */
CORE_API_EXPORT CoreApiHelperWifiWpsObj core_api_helper_wifi_wps_ref(CoreApiHelperWifiWpsObj wifi_wps);
CORE_API_EXPORT void core_api_helper_wifi_wps_unref_later(CoreApiHelperWifiWpsObj wifi_wps);
/**
 * async operation;
 */
CORE_API_EXPORT void core_api_helper_wifi_wps_do(CoreApiHelperWifiWpsObj wifi_wps, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);


CORE_API_END_DECLS

#endif /* CORE_API_HELPER_WIFI_WPS_H_ */

/**
 * @}
 */
