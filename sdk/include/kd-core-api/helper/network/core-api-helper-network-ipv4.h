
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperNetworkIPv4 header file.
 *
 * Definitions of KdCoreApiHelperNetworkIPv4 class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-12-25 zhuangzhida@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_HELPER_NETWORK_IPV4_H_
#define CORE_API_HELPER_NETWORK_IPV4_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-network.h"

#include "device/core-api-device-wifi.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiHelperNetworkIPv4Obj;


/** CoreApiHelperNetworkIPv4 */
CORE_API_EXPORT CoreApiHelperNetworkIPv4Obj core_api_helper_network_ipv4_ref(CoreApiHelperNetworkIPv4Obj network_ipv4);
CORE_API_EXPORT void core_api_helper_network_ipv4_unref_later(CoreApiHelperNetworkIPv4Obj network_ipv4);
/**
 * async operation;
 */
CORE_API_EXPORT void core_api_helper_network_ipv4_set(CoreApiHelperNetworkIPv4Obj network_ipv4, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_network_ipv4_get(CoreApiHelperNetworkIPv4Obj network_ipv4, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * view/edit
 */

CORE_API_EXPORT void core_api_helper_network_ipv4_edit_addr_type(CoreApiHelperNetworkIPv4Obj network_ipv4, CoreApiNetworkAddrType addr_type);
CORE_API_EXPORT CoreApiNetworkAddrType core_api_helper_network_ipv4_view_addr_type(CoreApiHelperNetworkIPv4Obj network_ipv4);

CORE_API_EXPORT void core_api_helper_network_ipv4_edit_ipv4_addr(CoreApiHelperNetworkIPv4Obj network_ipv4, CoreApiIPv4AddrObj addr);
CORE_API_EXPORT CoreApiIPv4AddrObj core_api_helper_network_ipv4_view_ipv4_addr_ref(CoreApiHelperNetworkIPv4Obj network_ipv4);

CORE_API_EXPORT void core_api_helper_network_ipv4_edit_dnss(CoreApiHelperNetworkIPv4Obj network_ipv4, CoreApiDnsAddrObj dns);
CORE_API_EXPORT CoreApiDnsAddrObj core_api_helper_network_ipv4_view_dnss_ref(CoreApiHelperNetworkIPv4Obj network_ipv4);

CORE_API_END_DECLS

#endif /* CORE_API_HELPER_NETWORK_IPV4_H_ */

/**
 * @}
 */
