
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The event enum advance header file.
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


#ifndef CORE_API_EVENT_ENUMS_ADVANCE_H_
#define CORE_API_EVENT_ENUMS_ADVANCE_H_

#include "event/core-event-enums.h"
#include "event/core-api-event-enums.h"

CORE_API_BEGIN_DECLS

CORE_API_EXPORT CoreApiEventAction core_event_action_to_api_event_action(CoreEventAction act);
CORE_API_EXPORT CoreEventAction core_api_event_action_to_api_event_action(CoreApiEventAction act);

CORE_API_EXPORT CoreApiEventTrigger core_event_trig_to_api_event_trig(CoreEventTrigger trig);
CORE_API_EXPORT CoreEventTrigger core_api_event_trig_to_event_trig(CoreApiEventTrigger trig);

CORE_API_END_DECLS

#endif /* CORE_API_EVENT_ENUMS_ADVANCE_H_ */

/**
 * @}
 */
