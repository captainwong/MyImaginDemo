
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

#ifndef CORE_API_ACC_USER_DB_H_
#define CORE_API_ACC_USER_DB_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-result.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-srv-info.h"

#include "acc/core-api-acc-user.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiAccUserDbObj;



typedef struct
{
    void *              udata;

    /**
     * return invalid obj terminated server array if success, else NULL array
     */
    void                (*on_result)(void *udata, CoreApiAccUserDbObj db, CoreApiAsyncCallerObj caller, CoreApiResultObj result, CoreApiSrvInfoObj srvs[]);
}CoreApiAccUserDbGetSipSrvInfoCb;


typedef CoreApiAccUserDbGetSipSrvInfoCb CoreApiAccUserDbGetStunSrvInfoCb;
typedef CoreApiAccUserDbGetSipSrvInfoCb CoreApiAccUserDbGetTurnSrvInfoCb;

typedef struct
{
    void *              udata;
    void                (*on_result)(void *udata, CoreApiAccUserDbObj db, CoreApiAsyncCallerObj caller, CoreApiResultObj result, CoreApiAccUserObj userinfo);
}CoreApiAccUserDbGetUserInfoCb;


CORE_API_EXPORT CoreApiAccUserDbObj core_api_acc_user_db_ref(CoreApiAccUserDbObj db);
CORE_API_EXPORT void core_api_acc_user_db_unref(CoreApiAccUserDbObj db);

/**
 * get sip srv info
 * async operation, wait callback for result.
 * you can use the sip server info to create a sip contactor.
 */
CORE_API_EXPORT void core_api_acc_user_db_get_sip_srv_info(CoreApiAccUserDbObj db, const CoreApiAccUserDbGetSipSrvInfoCb *cb, CoreApiAsyncCallerObj *caller);



/**
 * get stun/turn srv info
 * async operation, wait callback for result.
 * you can add those servers to dev-manager.
 */
CORE_API_EXPORT void core_api_acc_user_db_get_stun_srv_info(CoreApiAccUserDbObj db, const CoreApiAccUserDbGetStunSrvInfoCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_acc_user_db_get_turn_srv_info(CoreApiAccUserDbObj db, const CoreApiAccUserDbGetTurnSrvInfoCb *cb, CoreApiAsyncCallerObj *caller);



/**
 * password could not be fetched.
 */
CORE_API_EXPORT void core_api_acc_user_db_get_user_info(CoreApiAccUserDbObj db, const CoreApiAccUserDbGetUserInfoCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * only username, email, mphone will be update
 */
CORE_API_EXPORT void core_api_acc_user_db_update_user_info(CoreApiAccUserDbObj db, CoreApiAccUserObj user, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * only password will be update
 */
CORE_API_EXPORT void core_api_acc_user_db_update_user_auth(CoreApiAccUserDbObj db, CoreApiAccUserObj user, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);


CORE_API_END_DECLS

#endif /* CORE_API_ACC_USER_DB_H_ */

/**
 * @}
 */
