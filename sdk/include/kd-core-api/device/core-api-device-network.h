
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDeviceNetwork header file.
 *
 * Definitions of KdCoreApiDeviceNetwork class.
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




#ifndef CORE_API_DEVICE_NETWORK_H_
#define CORE_API_DEVICE_NETWORK_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-network.h"

#include "device/core-api-device-media.h"
#include "device/core-api-device-wifi.h"

#include "helper/network/core-api-helper-network.h"
#include "helper/network/core-api-helper-network-ipv4.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDeviceNetworkObj;



CORE_API_EXPORT CoreApiDeviceNetworkObj core_api_device_network_ref(CoreApiDeviceNetworkObj network);
CORE_API_EXPORT void core_api_device_network_unref(CoreApiDeviceNetworkObj network);
CORE_API_EXPORT CoreApiNetworkType core_api_device_network_get_type(CoreApiDeviceNetworkObj network);

CORE_API_EXPORT CoreApiDeviceWifiObj core_api_device_network_get_wifi_ref(CoreApiDeviceNetworkObj network);
CORE_API_EXPORT CoreApiHelperNetworkObj core_api_device_network_create_network_helper(CoreApiDeviceNetworkObj network);
CORE_API_EXPORT CoreApiHelperNetworkIPv4Obj core_api_device_network_create_network_ipv4_helper(CoreApiDeviceNetworkObj network);


CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_NETWORK_H_ */

/**
 * @}
 */
