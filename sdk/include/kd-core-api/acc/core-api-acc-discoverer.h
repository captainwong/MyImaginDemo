
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiAccDiscoverer header file.
 *
 * Definitions of KdCoreApiAccDiscoverer class.
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




#ifndef CORE_API_ACC_DISCOVERER_H_
#define CORE_API_ACC_DISCOVERER_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-result.h"
#include "core/core-api-async-caller.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiAccDiscovererObj;



CORE_API_EXPORT CoreApiAccDiscovererObj core_api_acc_discoverer_ref(CoreApiAccDiscovererObj discoverer);
CORE_API_EXPORT void core_api_acc_discoverer_unref(CoreApiAccDiscovererObj discoverer);



CORE_API_END_DECLS

#endif /* CORE_API_ACC_DISCOVERER_H_ */

/**
 * @}
 */
