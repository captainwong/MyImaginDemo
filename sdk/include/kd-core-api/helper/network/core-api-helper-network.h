
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperNetwork header file.
 *
 * Definitions of KdCoreApiHelperNetwork class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-12-24 zhuangzhida@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_HELPER_NETWORK_H_
#define CORE_API_HELPER_NETWORK_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-network.h"

#include "device/core-api-device-wifi.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiHelperNetworkObj;


/** CoreApiHelperNetwork */
CORE_API_EXPORT CoreApiHelperNetworkObj core_api_helper_network_ref(CoreApiHelperNetworkObj network);
CORE_API_EXPORT void core_api_helper_network_unref_later(CoreApiHelperNetworkObj network);
/**
 * async operation;
 */
CORE_API_EXPORT void core_api_helper_network_set(CoreApiHelperNetworkObj network, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * view/edit
 */

CORE_API_EXPORT void core_api_helper_network_edit_mtu(CoreApiHelperNetworkObj network, int32_t mtu);
CORE_API_EXPORT void core_api_helper_network_edit_mac(CoreApiHelperNetworkObj network, const char *mac);
CORE_API_EXPORT int32_t core_api_helper_network_view_mtu(CoreApiHelperNetworkObj network);
CORE_API_EXPORT const char* core_api_helper_network_view_mac(CoreApiHelperNetworkObj network);


CORE_API_END_DECLS

#endif /* CORE_API_HELPER_NETWORK_H_ */

/**
 * @}
 */
