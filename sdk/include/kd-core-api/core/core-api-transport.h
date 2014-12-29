
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiTransport header file.
 *
 * Definitions of KdCoreApiTransport class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-18 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_TRANSPORT_H_
#define CORE_API_TRANSPORT_H_

#include "core/core-api-global.h"


CORE_API_BEGIN_DECLS

typedef enum
{
    CORE_API_TRANSPORT_NULL     = 0x01<<0,
    CORE_API_TRANSPORT_UDP      = 0x01<<1,
    CORE_API_TRANSPORT_TCP      = 0x01<<2,
    CORE_API_TRANSPORT_TLS      = 0x01<<3,
}CoreApiTransport;

CORE_API_END_DECLS

#endif /* CORE_API_TRANSPORT_H_ */

/**
 * @}
 */
