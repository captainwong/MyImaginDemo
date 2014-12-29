
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiTransport advance header file.
 *
 * Definitions of CoreApiTransport class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-9-18 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_TRANSPORT_ADVANCE_H_
#define CORE_API_TRANSPORT_ADVANCE_H_

#include "core/core-api-transport.h"

#include "core/core-transport.h"

CORE_API_BEGIN_DECLS

CORE_API_EXPORT CoreTransport    core_api_transport_to_transport(CoreApiTransport apits);
CORE_API_EXPORT CoreApiTransport core_api_transport_from_transport(CoreTransport ts);

CORE_API_END_DECLS

#endif /* CORE_API_TRANSPORT_ADVANCE_H_ */

/**
 * @}
 */
