
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreIceTurnAccount advance header file.
 *
 * Definitions of CoreIceTurnAccount class.
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


#ifndef CORE_API_ICE_TURN_ACCOUNT_ADVANCE_H_
#define CORE_API_ICE_TURN_ACCOUNT_ADVANCE_H_

#include "core/core-api-global.h"

#include "core/core-api-srv-info.h"
#include "ice/core-ice-turn-account.h"

CORE_API_BEGIN_DECLS


CORE_API_EXPORT CoreIceTurnAccount *  core_api_srv_info_to_ice_turn_account(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT CoreApiSrvInfoObj core_api_ice_turn_account_to_srv_info(CoreIceTurnAccount *account);

CORE_API_END_DECLS

#endif /* CORE_API_ICE_TURN_ACCOUNT_ADVANCE_H_ */

/**
 * @}
 */
