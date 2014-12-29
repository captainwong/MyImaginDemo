
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiAccContactor header file.
 *
 * Definitions of KdCoreApiAccContactor class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-19 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_ACC_CONTACTOR_H_
#define CORE_API_ACC_CONTACTOR_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-result.h"
#include "core/core-api-async-caller.h"

#include "acc/core-api-acc-discoverer.h"
#include "acc/core-api-acc-dev-db.h"
#include "acc/core-api-acc-user-db.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiAccContactorObj;



CORE_API_EXPORT CoreApiAccContactorObj core_api_acc_contactor_ref(CoreApiAccContactorObj contactor);
CORE_API_EXPORT void core_api_acc_contactor_unref(CoreApiAccContactorObj contactor);
/**
 * login or logout
 * async operation, wait callback for result.
 */
CORE_API_EXPORT void core_api_acc_contactor_login(CoreApiAccContactorObj contactor, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_acc_contactor_logout(CoreApiAccContactorObj contactor, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);


/** acc discoverer*/
CORE_API_EXPORT CoreApiAccDiscovererObj core_api_acc_contactor_get_discoverer_ref(CoreApiAccContactorObj contactor);




/**
 * @pre login success
 */
CORE_API_EXPORT CoreApiAccDevDbObj core_api_acc_contactor_get_dev_db_ref(CoreApiAccContactorObj contactor);
CORE_API_EXPORT CoreApiAccUserDbObj core_api_acc_contactor_get_user_db_ref(CoreApiAccContactorObj contactor);


CORE_API_END_DECLS

#endif /* CORE_API_ACC_CONTACTOR_H_ */

/**
 * @}
 */
