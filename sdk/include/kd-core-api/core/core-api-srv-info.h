
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiSrvInfo header file.
 *
 * Definitions of KdCoreApiSrvInfo class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-18 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_SRV_INFO_H_
#define CORE_API_SRV_INFO_H_

#include "stdint.h"     //" int16_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-cred.h"
#include "core/core-api-transport.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiSrvInfoObj;


CORE_API_EXPORT CoreApiSrvInfoObj core_api_srv_info_new(void);
CORE_API_EXPORT CoreApiSrvInfoObj core_api_srv_info_new_full(CoreApiTransport transport, const char *domain, uint16_t port);
CORE_API_EXPORT CoreApiSrvInfoObj core_api_srv_info_ref(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT void core_api_srv_info_unref(CoreApiSrvInfoObj srvinfo);

CORE_API_EXPORT CoreApiTransport core_api_srv_info_get_transport(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT void core_api_srv_info_set_transport(CoreApiSrvInfoObj srvinfo, CoreApiTransport transport);

CORE_API_EXPORT const char * core_api_srv_info_get_domain(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT void core_api_srv_info_set_domain(CoreApiSrvInfoObj srvinfo, const char *domain);

CORE_API_EXPORT uint16_t core_api_srv_info_get_port(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT void core_api_srv_info_set_port(CoreApiSrvInfoObj srvinfo, uint16_t port);





/** extends methods */
CORE_API_EXPORT const char * core_api_srv_info_get_username(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT void core_api_srv_info_set_username(CoreApiSrvInfoObj srvinfo, const char *username);

CORE_API_EXPORT CoreApiCredObj core_api_srv_info_get_cred_ref(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT void core_api_srv_info_set_cred(CoreApiSrvInfoObj srvinfo, CoreApiCredObj cred);

CORE_API_END_DECLS

#endif /* CORE_API_SRV_INFO_H_ */

/**
 * @}
 */
