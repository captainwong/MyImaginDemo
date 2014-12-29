
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreAccAccount advance header file.
 *
 * Definitions of CoreAccAccount class.
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


#ifndef CORE_API_ACC_ACCOUNT_ADVANCE_H_
#define CORE_API_ACC_ACCOUNT_ADVANCE_H_

#include "core/core-api-global.h"

#include "core/core-api-srv-info.h"
#include "acc2/core-acc2-account.h"

CORE_API_BEGIN_DECLS


CORE_API_EXPORT CoreAcc2Account *  core_api_srv_info_to_acc2_account(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT CoreApiSrvInfoObj core_api_acc2_account_to_srv_info(CoreAcc2Account *account);

CORE_API_END_DECLS

#endif /* CORE_API_ACC_ACCOUNT_ADVANCE_H_ */

/**
 * @}
 */
