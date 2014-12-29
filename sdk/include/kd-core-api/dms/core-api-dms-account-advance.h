
/**
 * @addtogroup KdCoreApi package
 * @{
 */

/**
 * @brief    file description
 *
 *  file details
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-9-9 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_DMS_ACCOUNT_ADVANCE_H_
#define CORE_API_DMS_ACCOUNT_ADVANCE_H_

#include "core/core-api-global.h"

#include "core/core-api-srv-info.h"
#include "dms/core-dms-account.h"

CORE_API_BEGIN_DECLS


CORE_API_EXPORT CoreDmsAccount *  core_api_srv_info_to_dms_account(CoreApiSrvInfoObj srvinfo);
CORE_API_EXPORT CoreApiSrvInfoObj core_api_dms_account_to_srv_info(CoreDmsAccount *account);

CORE_API_END_DECLS

#endif /* CORE_API_DMS_ACCOUNT_ADVANCE_H_ */

/**
 * @}
 */
