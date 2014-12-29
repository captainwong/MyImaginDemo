
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiUPnPDiscoverer header file.
 *
 * Definitions of CoreApiUPnPDiscoverer class.
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


#ifndef CORE_API_UPNP_DISCOVERER_H_
#define CORE_API_UPNP_DISCOVERER_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "upnp/core-api-upnp-discoverer.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiUPnPDiscovererObj;





CORE_API_EXPORT CoreApiUPnPDiscovererObj core_api_upnp_discoverer_ref(CoreApiUPnPDiscovererObj discoverer);
CORE_API_EXPORT void core_api_upnp_discoverer_unref(CoreApiUPnPDiscovererObj discoverer);






CORE_API_END_DECLS

#endif /* CORE_API_UPNP_DISCOVERER_H_ */

/**
 * @}
 */
