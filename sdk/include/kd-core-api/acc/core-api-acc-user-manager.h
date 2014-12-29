
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

#ifndef CORE_API_ACC_USER_MANAGER_H_
#define CORE_API_ACC_USER_MANAGER_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"

#include "acc/core-api-acc-user.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiAccUserManagerObj;

typedef struct
{
    void *              udata;

    /**
     * exists is a boolean,
     * but check result-"code first
     */
    void                (*on_result)(void *udata, CoreApiAccUserManagerObj db, CoreApiAsyncCallerObj caller, CoreApiResultObj result, int exists);
}CoreApiAccUserManagerIsEmailExistsCb;


CORE_API_EXPORT CoreApiAccUserManagerObj core_api_acc_user_manager_ref(CoreApiAccUserManagerObj manager);
CORE_API_EXPORT void core_api_acc_user_manager_unref(CoreApiAccUserManagerObj manager);

CORE_API_EXPORT void core_api_acc_user_manager_is_email_exists(CoreApiAccUserManagerObj manager, const char *email, const CoreApiAccUserManagerIsEmailExistsCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_EXPORT void core_api_acc_user_manager_send_vcode_for_register(CoreApiAccUserManagerObj manager, const char *email, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_acc_user_manager_register_user(CoreApiAccUserManagerObj manager, CoreApiAccUserObj user, const char *vcode, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_EXPORT void core_api_acc_user_manager_send_vcode_for_reset_pwd(CoreApiAccUserManagerObj manager, const char *email, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_acc_user_manager_reset_pwd(CoreApiAccUserManagerObj manager, const char *email, const char *newpwd, const char *vcode, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_END_DECLS

#endif /* CORE_API_ACC_USER_MANAGER_H_ */

/**
 * @}
 */
