
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The XXX header file.
 *
 * Definitions of XXX class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-9-17 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_UPNP_STACK_H_
#define CORE_API_UPNP_STACK_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"

#include "upnp/core-api-upnp-contactor.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiUPnPStackObj;




/** upnp stack */
CORE_API_EXPORT CoreApiUPnPStackObj core_api_upnp_stack_new(void);
CORE_API_EXPORT CoreApiUPnPStackObj core_api_upnp_stack_ref(CoreApiUPnPStackObj stack);
CORE_API_EXPORT void core_api_upnp_stack_unref(CoreApiUPnPStackObj stack);
/**
 * start/stop stack
 * @return      0 means success, others failure.
 */
CORE_API_EXPORT int core_api_upnp_stack_start(CoreApiUPnPStackObj stack);
CORE_API_EXPORT int core_api_upnp_stack_stop(CoreApiUPnPStackObj stack);


/** upnp contactor */
CORE_API_EXPORT CoreApiUPnPContactorObj core_api_upnp_stack_create_contactor(CoreApiUPnPStackObj stack);


CORE_API_END_DECLS

#endif /* CORE_API_UPNP_STACK_H_ */

/**
 * @}
 */
