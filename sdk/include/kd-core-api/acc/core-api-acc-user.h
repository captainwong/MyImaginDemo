
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

#ifndef CORE_API_ACC_USER_H_
#define CORE_API_ACC_USER_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiAccUserObj;


CORE_API_EXPORT CoreApiAccUserObj core_api_acc_user_new(void);
CORE_API_EXPORT CoreApiAccUserObj core_api_acc_user_new_full(const char *username, const char *password, const char *email, const char *mphone);
CORE_API_EXPORT CoreApiAccUserObj core_api_acc_user_ref(CoreApiAccUserObj user);
CORE_API_EXPORT void core_api_acc_user_unref(CoreApiAccUserObj user);



CORE_API_EXPORT const char * core_api_acc_user_get_username(CoreApiAccUserObj user);
CORE_API_EXPORT void core_api_acc_user_set_username(CoreApiAccUserObj user, const char *username);

CORE_API_EXPORT const char * core_api_acc_user_get_password(CoreApiAccUserObj user);
CORE_API_EXPORT void core_api_acc_user_set_password(CoreApiAccUserObj user, const char *password);

CORE_API_EXPORT const char * core_api_acc_user_get_email(CoreApiAccUserObj user);
CORE_API_EXPORT void core_api_acc_user_set_email(CoreApiAccUserObj user, const char *email);

CORE_API_EXPORT const char * core_api_acc_user_get_mphone(CoreApiAccUserObj user);
CORE_API_EXPORT void core_api_acc_user_set_mphone(CoreApiAccUserObj user, const char *mphone);

CORE_API_END_DECLS

#endif /* CORE_API_ACC_USER_H_ */

/**
 * @}
 */
