
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreIceStunUri advance header file.
 *
 * Definitions of CoreIceStunUri class.
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-4-1 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_ICE_STUN_URI_ADVANCE_H_
#define CORE_API_ICE_STUN_URI_ADVANCE_H_

#include "core/core-api-global.h"

#include "core/core-api-srv-info.h"
#include "ice/core-ice-stun-uri.h"

CORE_API_BEGIN_DECLS


CORE_API_EXPORT CoreIceStunUri *  core_api_srv_info_to_ice_stun_uri(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT CoreApiSrvInfoObj core_api_ice_stun_uri_to_srv_info(CoreIceStunUri *account);

CORE_API_END_DECLS

#endif /* CORE_API_ICE_STUN_URI_ADVANCE_H_ */

/**
 * @}
 */
