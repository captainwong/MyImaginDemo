
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperSubsAlarmEvent header file.
 *
 * Definitions of CoreApiHelperSubsAlarmEvent class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-12-4 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_SUBS_ALARM_EVENT_H_
#define CORE_API_HELPER_SUBS_ALARM_EVENT_H_

#include "stdint.h"         //" int32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperSubsAlarmEventObj;



CORE_API_EXPORT CoreApiHelperSubsAlarmEventObj core_api_helper_subs_alarm_event_ref(CoreApiHelperSubsAlarmEventObj sae);
CORE_API_EXPORT void core_api_helper_subs_alarm_event_unref_later(CoreApiHelperSubsAlarmEventObj sae);



CORE_API_EXPORT void core_api_helper_subs_alarm_event_edit_expires(CoreApiHelperSubsAlarmEventObj sae, int32_t minutes);
CORE_API_EXPORT int32_t core_api_helper_subs_alarm_event_view_expires(CoreApiHelperSubsAlarmEventObj sae);


/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_subs_alarm_event_subscribe(CoreApiHelperSubsAlarmEventObj sae, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);




CORE_API_END_DECLS

#endif /* CORE_API_HELPER_SUBS_ALARM_EVENT_H_ */

/**
 * @}
 */
