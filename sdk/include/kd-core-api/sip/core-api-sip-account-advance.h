
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreSipAccount header file.
 *
 * Definitions of CoreSipAccount class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-10-28 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_SIP_ACCOUNT_ADVANCE_H_
#define CORE_API_SIP_ACCOUNT_ADVANCE_H_

#include "core/core-api-global.h"

#include "core/core-api-srv-info.h"
#include "sip/core-sip-account.h"

CORE_API_BEGIN_DECLS


CORE_API_EXPORT CoreSipAccount *  core_api_srv_info_to_sip_account(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT CoreApiSrvInfoObj core_api_sip_account_to_srv_info(CoreSipAccount *account);

CORE_API_END_DECLS


#endif /* CORE_API_SIP_ACCOUNT_ADVANCE_H_ */

/**
 * @}
 */
