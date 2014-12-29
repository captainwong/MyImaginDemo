
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperWifiAltApEnumerator header file.
 *
 * Definitions of KdCoreApiHelperWifiAltApEnumerator class.
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




#ifndef CORE_API_HELPER_WIFI_ALT_AP_ENUMERATOR_H_
#define CORE_API_HELPER_WIFI_ALT_AP_ENUMERATOR_H_

#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-wifi-ap.h"


CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperWifiAltApEnumeratorObj;


/** CoreApiHelperWifiAltApEnumerator */
CORE_API_EXPORT CoreApiHelperWifiAltApEnumeratorObj core_api_helper_wifi_alt_ap_enumerator_ref(CoreApiHelperWifiAltApEnumeratorObj wifi_apenum);
CORE_API_EXPORT void core_api_helper_wifi_alt_ap_enumerator_unref_later(CoreApiHelperWifiAltApEnumeratorObj wifi_apenum);
/**
 * start enumerator
 * async operation.
 */
CORE_API_EXPORT void core_api_helper_wifi_alt_ap_enumerator_enum(CoreApiHelperWifiAltApEnumeratorObj apenum, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * loop each ap
 */
CORE_API_EXPORT uint32_t core_api_helper_wifi_alt_ap_enumerator_count(CoreApiHelperWifiAltApEnumeratorObj apenum);
CORE_API_EXPORT CoreApiWifiApObj core_api_helper_wifi_alt_ap_enumerator_get_ap_ref(CoreApiHelperWifiAltApEnumeratorObj apenum, uint32_t index);


CORE_API_END_DECLS

#endif /* CORE_API_HELPER_WIFI_ALT_AP_ENUMERATOR_H_ */

/**
 * @}
 */
