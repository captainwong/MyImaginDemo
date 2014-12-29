
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiUPnPContactor header file.
 *
 * Definitions of KdCoreApiUPnPContactor class.
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


#ifndef CORE_API_UPNP_CONTACTOR_H_
#define CORE_API_UPNP_CONTACTOR_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "upnp/core-api-upnp-discoverer.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiUPnPContactorObj;





CORE_API_EXPORT CoreApiUPnPContactorObj core_api_upnp_contactor_ref(CoreApiUPnPContactorObj contactor);
CORE_API_EXPORT void core_api_upnp_contactor_unref(CoreApiUPnPContactorObj contactor);





/** upnp discoverer*/
CORE_API_EXPORT CoreApiUPnPDiscovererObj core_api_upnp_contactor_get_discoverer_ref(CoreApiUPnPContactorObj contactor);



CORE_API_END_DECLS

#endif /* CORE_API_UPNP_CONTACTOR_H_ */

/**
 * @}
 */
