
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
 * -# 2014-9-15 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_ACC_DEV_DB_H_
#define CORE_API_ACC_DEV_DB_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"

#include "acc/core-api-acc-dev.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiAccDevDbObj;





CORE_API_EXPORT CoreApiAccDevDbObj core_api_acc_dev_db_ref(CoreApiAccDevDbObj db);
CORE_API_EXPORT void core_api_acc_dev_db_unref(CoreApiAccDevDbObj db);


CORE_API_EXPORT void core_api_acc_dev_db_add_dev(CoreApiAccDevDbObj db, CoreApiAccDevObj dev, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_acc_dev_db_del_dev_by_sn(CoreApiAccDevDbObj db, const char *sn, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_acc_dev_db_del_dev_by_uid(CoreApiAccDevDbObj db, const char *uid, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * only dev name will be update
 */
CORE_API_EXPORT void core_api_acc_dev_db_update_dev_info(CoreApiAccDevDbObj db, CoreApiAccDevObj dev, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * username and password will be update
 */
CORE_API_EXPORT void core_api_acc_dev_db_update_dev_auth(CoreApiAccDevDbObj db, CoreApiAccDevObj dev, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);


CORE_API_END_DECLS

#endif /* CORE_API_ACC_DEV_DB_H_ */

/**
 * @}
 */
