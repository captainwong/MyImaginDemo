
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The event enum header file.
 *
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-6-12 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_EVENT_ENUMS_H_
#define CORE_API_EVENT_ENUMS_H_

#include "core/core-api-global.h"

CORE_API_BEGIN_DECLS

typedef enum
{
    CORE_API_EVT_ACT_STOP       = 0,
    CORE_API_EVT_ACT_START      = 1,
}CoreApiEventAction;


typedef enum
{
    CPRE_API_EVT_TRIG_HW        = 0,
    CPRE_API_EVT_TRIG_SW        = 0,
}CoreApiEventTrigger;

CORE_API_END_DECLS

#endif /* CORE_API_EVENT_ENUMS_H_ */

/**
 * @}
 */
