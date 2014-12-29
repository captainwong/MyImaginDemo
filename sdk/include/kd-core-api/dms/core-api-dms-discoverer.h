
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

#ifndef CORE_API_DMS_DISCOVERER_H_
#define CORE_API_DMS_DISCOVERER_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiDmsDiscovererObj;



/** dms discoverer*/
CORE_API_EXPORT CoreApiDmsDiscovererObj core_api_dms_discoverer_ref(CoreApiDmsDiscovererObj discoverer);
CORE_API_EXPORT void core_api_dms_discoverer_unref(CoreApiDmsDiscovererObj discoverer);



CORE_API_END_DECLS

#endif /* CORE_API_DMS_DISCOVERER_H_ */

/**
 * @}
 */
