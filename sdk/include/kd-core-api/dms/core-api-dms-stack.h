
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
 * -# 2014-9-9 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_DMS_STACK_H_
#define CORE_API_DMS_STACK_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-transport.h"
#include "core/core-api-srv-info.h"

#include "dms/core-api-dms-contactor.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiDmsStackObj;




/** dms stack */
CORE_API_EXPORT CoreApiDmsStackObj core_api_dms_stack_new(void);
CORE_API_EXPORT CoreApiDmsStackObj core_api_dms_stack_ref(CoreApiDmsStackObj stack);
CORE_API_EXPORT void core_api_dms_stack_unref(CoreApiDmsStackObj stack);
/**
 * start/stop stack
 * @return      0 means success, others failure.
 */
CORE_API_EXPORT int core_api_dms_stack_start(CoreApiDmsStackObj stack);
CORE_API_EXPORT int core_api_dms_stack_stop(CoreApiDmsStackObj stack);

/** dms contactor */
CORE_API_EXPORT CoreApiDmsContactorObj core_api_dms_stack_create_contactor(CoreApiDmsStackObj stack, CoreApiSrvInfoObj srvinfo);


CORE_API_END_DECLS

#endif /* CORE_API_DMS_STACK_H_ */

/**
 * @}
 */
