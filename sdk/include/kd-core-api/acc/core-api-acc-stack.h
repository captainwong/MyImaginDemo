
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiAccStack header file.
 *
 * Definitions of KdCoreApiAccStack class.
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




#ifndef CORE_API_ACC_STACK_H_
#define CORE_API_ACC_STACK_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-srv-info.h"

#include "acc/core-api-acc-contactor.h"
#include "acc/core-api-acc-user-manager.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiAccStackObj;




/** acc stack */
CORE_API_EXPORT CoreApiAccStackObj core_api_acc_stack_new(void);
CORE_API_EXPORT CoreApiAccStackObj core_api_acc_stack_ref(CoreApiAccStackObj stack);
CORE_API_EXPORT void core_api_acc_stack_unref(CoreApiAccStackObj stack);
/**
 * start/stop stack
 * @return      0 means success, others failure.
 */
CORE_API_EXPORT int core_api_acc_stack_start(CoreApiAccStackObj stack);
CORE_API_EXPORT int core_api_acc_stack_stop(CoreApiAccStackObj stack);


/** acc contactor */
/**
 * @param [in]  srv     @see core_api_srv_info_new_full() or core_api_ihms_tiny_server_get_acc_ref()
 */
CORE_API_EXPORT CoreApiAccContactorObj core_api_acc_stack_create_contactor(CoreApiAccStackObj stack, CoreApiSrvInfoObj srv);


/**
 * @param [in]  srv     acc server without credential.
 * @see core_api_srv_info_new_full()
 * @see core_api_ihms_tiny_server_get_acc_ref()
 */
CORE_API_EXPORT CoreApiAccUserManagerObj core_api_acc_stack_create_user_manager(CoreApiAccStackObj stack, CoreApiSrvInfoObj srv);



CORE_API_END_DECLS

#endif /* CORE_API_ACC_STACK_H_ */

/**
 * @}
 */
