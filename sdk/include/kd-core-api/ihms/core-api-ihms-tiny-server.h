
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
 * -# 2014-9-10 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_IHMS_TINY_SERVER_H_
#define CORE_API_IHMS_TINY_SERVER_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-srv-info.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiIhmsTinyServerObj;




/**
 * stunsrvs/turnsrvs, CORE_API_INVALID_OBJ terminated array
 *
 * @param [in]      sipsrv      sip server with credential
 * @param [in]      stunsrvs    stun servers WITHOUT credential
 * @param [in]      turnsrvs    turn servers with credential
 */
CORE_API_EXPORT CoreApiIhmsTinyServerObj core_api_ihms_tiny_server_new(CoreApiSrvInfoObj sipsrv, CoreApiSrvInfoObj stunsrvs[], CoreApiSrvInfoObj turnsrvs[]);
CORE_API_EXPORT CoreApiIhmsTinyServerObj core_api_ihms_tiny_server_ref(CoreApiIhmsTinyServerObj server);
CORE_API_EXPORT void core_api_ihms_tiny_server_unref(CoreApiIhmsTinyServerObj server);



/**
 * @retval 0 successs, others failed.
 */
CORE_API_EXPORT int core_api_ihms_tiny_server_start(CoreApiIhmsTinyServerObj server);
CORE_API_EXPORT void core_api_ihms_tiny_server_stop(CoreApiIhmsTinyServerObj server);



/**
 * @pre server start success.
 */
CORE_API_EXPORT CoreApiSrvInfoObj core_api_ihms_tiny_server_get_acc_ref(CoreApiIhmsTinyServerObj server);
CORE_API_EXPORT CoreApiSrvInfoObj core_api_ihms_tiny_server_get_dms_ref(CoreApiIhmsTinyServerObj server);


CORE_API_END_DECLS

#endif /* CORE_API_IHMS_TINY_SERVER_H_ */

/**
 * @}
 */
