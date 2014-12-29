
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiSipDiscoverer header file.
 *
 * Definitions of KdCoreApiSipDiscoverer class.
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




#ifndef CORE_API_SIP_DISCOVERER_H_
#define CORE_API_SIP_DISCOVERER_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiSipDiscovererObj;



/** sip discoverer*/
CORE_API_EXPORT CoreApiSipDiscovererObj core_api_sip_discoverer_ref(CoreApiSipDiscovererObj discoverer);
CORE_API_EXPORT void core_api_sip_discoverer_unref(CoreApiSipDiscovererObj discoverer);



CORE_API_END_DECLS

#endif /* CORE_API_SIP_DISCOVERER_H_ */

/**
 * @}
 */
