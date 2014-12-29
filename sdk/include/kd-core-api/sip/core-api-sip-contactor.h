
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiSipContactor header file.
 *
 * Definitions of KdCoreApiSipContactor class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-20 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_SIP_CONTACTOR_H_
#define CORE_API_SIP_CONTACTOR_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-result.h"

#include "sip/core-api-sip-discoverer.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiSipContactorObj;



/** sip contactor */
CORE_API_EXPORT CoreApiSipContactorObj core_api_sip_contactor_ref(CoreApiSipContactorObj contactor);
CORE_API_EXPORT void core_api_sip_contactor_unref(CoreApiSipContactorObj contactor);

/**
 * login or logout
 * async operation, wait for result.
 */
CORE_API_EXPORT void core_api_sip_contactor_login( CoreApiSipContactorObj contactor, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_sip_contactor_logout(CoreApiSipContactorObj contactor, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);





/** sip discoverer*/
CORE_API_EXPORT CoreApiSipDiscovererObj core_api_sip_contactor_get_discoverer_ref(CoreApiSipContactorObj contactor);



CORE_API_END_DECLS

#endif /* CORE_API_SIP_CONTACTOR_H_ */

/**
 * @}
 */
