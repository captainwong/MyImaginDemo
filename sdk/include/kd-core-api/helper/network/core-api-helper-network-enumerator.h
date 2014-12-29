
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperNetworkEnumerator header file.
 *
 * Definitions of KdCoreApiHelperNetworkEnumerator class.
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




#ifndef CORE_API_HELPER_NETWORK_ENUMERATOR_H_
#define CORE_API_HELPER_NETWORK_ENUMERATOR_H_

#include "stdint.h"                 //" int32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"

#include "helper/network/core-api-helper-network.h"
#include "device/core-api-device-network.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiHelperNetworkEnumeratorObj;







/** CoreApiHelperNetworkEnumerator */
CORE_API_EXPORT CoreApiHelperNetworkEnumeratorObj core_api_helper_network_enumerator_ref(CoreApiHelperNetworkEnumeratorObj networkenum);
CORE_API_EXPORT void core_api_helper_network_enumerator_unref_later(CoreApiHelperNetworkEnumeratorObj networkenum);
/**
 * start enumerator
 * async operation.
 */
CORE_API_EXPORT void core_api_helper_network_enumerator_enum(CoreApiHelperNetworkEnumeratorObj networkenum, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * loop each CoreApiHelperNetwork
 * @pre enum_result() with success.
 */
CORE_API_EXPORT uint32_t core_api_helper_network_enumerator_count(CoreApiHelperNetworkEnumeratorObj networkenum);
CORE_API_EXPORT CoreApiDeviceNetworkObj core_api_helper_network_enumerator_get_network_ref(CoreApiHelperNetworkEnumeratorObj networkenum, uint32_t index);







CORE_API_END_DECLS

#endif /* CORE_API_HELPER_NETWORK_ENUMERATOR_H_ */

/**
 * @}
 */
