
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiNetwork header file.
 *
 * Definitions of KdCoreApiNetwork class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-20 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_NETWORK_H_
#define CORE_API_NETWORK_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiIPv4AddrObj;
typedef CoreApiObj CoreApiDnsAddrObj;


typedef enum
{
    CORE_API_NETWORK_ETHER,         //" Ethernet
    CORE_API_NETWORK_WIFI,          //" WiFi
    CORE_API_NETWORK_DSL,           //" PPPoE
    CORE_API_NETWORK_MOBILE,        //" 3G/4G
}CoreApiNetworkType;
typedef enum
{
    CORE_API_NETWORK_ADDR_DHCP,
    CORE_API_NETWORK_ADDR_MANUAL,
    CORE_API_NETWORK_ADDR_PPP,
}CoreApiNetworkAddrType;







/**
 * CoreApiIPv4Addr
 * {
 *      char *      ip;
 *      char *      mask;
 *      char *      gateway;
 * }
 */
CORE_API_EXPORT CoreApiIPv4AddrObj core_api_ipv4_addr_new(void);
CORE_API_EXPORT CoreApiIPv4AddrObj core_api_ipv4_addr_new_full(const char *ip, const char *mask, const char *gateway);
CORE_API_EXPORT CoreApiIPv4AddrObj core_api_ipv4_addr_ref(CoreApiIPv4AddrObj addr);
CORE_API_EXPORT void core_api_ipv4_addr_unref(CoreApiIPv4AddrObj addr);

CORE_API_EXPORT const char * core_api_ipv4_addr_get_ip(CoreApiIPv4AddrObj addr);
CORE_API_EXPORT void core_api_ipv4_addr_set_ip(CoreApiIPv4AddrObj addr, const char *ip);

CORE_API_EXPORT const char * core_api_ipv4_addr_get_mask(CoreApiIPv4AddrObj addr);
CORE_API_EXPORT void core_api_ipv4_addr_set_mask(CoreApiIPv4AddrObj addr, const char *mask);

CORE_API_EXPORT const char * core_api_ipv4_addr_get_gateway(CoreApiIPv4AddrObj addr);
CORE_API_EXPORT void core_api_ipv4_addr_set_gateway(CoreApiIPv4AddrObj addr, const char *gateway);


/**
 * CoreApiDnsAddr
 * {
 *      char *      primary;
 *      char *      secondary;
 * }
 */
CORE_API_EXPORT CoreApiDnsAddrObj core_api_dns_addr_new(void);
CORE_API_EXPORT CoreApiDnsAddrObj core_api_dns_addr_new_full(const char *primary, const char *secondary);
CORE_API_EXPORT CoreApiDnsAddrObj core_api_dns_addr_ref(CoreApiDnsAddrObj addr);
CORE_API_EXPORT void core_api_dns_addr_unref(CoreApiDnsAddrObj addr);

CORE_API_EXPORT const char * core_api_dns_addr_get_primary(CoreApiDnsAddrObj addr);
CORE_API_EXPORT void core_api_dns_addr_set_primary(CoreApiDnsAddrObj addr, const char *primary);

CORE_API_EXPORT const char * core_api_dns_addr_get_secondary(CoreApiDnsAddrObj addr);
CORE_API_EXPORT void core_api_dns_addr_set_secondary(CoreApiDnsAddrObj addr, const char *secondary);


CORE_API_END_DECLS

#endif /* CORE_API_NETWORK_H_ */

/**
 * @}
 */
