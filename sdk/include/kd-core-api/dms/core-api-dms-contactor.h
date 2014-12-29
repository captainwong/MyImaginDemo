
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

#ifndef CORE_API_DMS_CONTACTOR_H_
#define CORE_API_DMS_CONTACTOR_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
//#include "core/core-api-async-caller.h"
//#include "core/core-api-result.h"

#include "dms/core-api-dms-discoverer.h"

CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiDmsContactorObj;



/** dms contactor */
CORE_API_EXPORT CoreApiDmsContactorObj core_api_dms_contactor_ref(CoreApiDmsContactorObj contactor);
CORE_API_EXPORT void core_api_dms_contactor_unref(CoreApiDmsContactorObj contactor);





/** dms discoverer*/
CORE_API_EXPORT CoreApiDmsDiscovererObj core_api_dms_contactor_get_discoverer_ref(CoreApiDmsContactorObj contactor);



CORE_API_END_DECLS

#endif /* CORE_API_DMS_CONTACTOR_H_ */

/**
 * @}
 */
