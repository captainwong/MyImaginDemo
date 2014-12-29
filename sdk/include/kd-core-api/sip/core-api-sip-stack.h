
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiSipStack header file.
 *
 * Definitions of KdCoreApiSipStack class.
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




#ifndef CORE_API_SIP_STACK_H_
#define CORE_API_SIP_STACK_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-transport.h"
#include "core/core-api-srv-info.h"

#include "sip/core-api-sip-contactor.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiSipStackObj;



typedef struct
{
    CoreApiTransport    transport;
    uint16_t            port;           //" 0 means any port; mostly, protocol default port would be used.
}CoreApiSipListeningPoint;

typedef struct
{
    uint16_t            start;
    uint16_t            stop;
}CoreApiSipPortRange;



/** sip stack */
CORE_API_EXPORT CoreApiSipStackObj core_api_sip_stack_new(const CoreApiSipListeningPoint *lp, const CoreApiSipPortRange *range);
CORE_API_EXPORT CoreApiSipStackObj core_api_sip_stack_ref(CoreApiSipStackObj stack);
CORE_API_EXPORT void core_api_sip_stack_unref(CoreApiSipStackObj stack);
/**
 * start/stop stack
 * @return      0 means success, others failure.
 */
CORE_API_EXPORT int core_api_sip_stack_start(CoreApiSipStackObj stack);
CORE_API_EXPORT int core_api_sip_stack_stop(CoreApiSipStackObj stack);

/** sip contactor */
CORE_API_EXPORT CoreApiSipContactorObj core_api_sip_stack_create_contactor(CoreApiSipStackObj stack, CoreApiSrvInfoObj srvinfo);


CORE_API_END_DECLS

#endif /* CORE_API_SIP_STACK_H_ */

/**
 * @}
 */
