/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperOperAllEvent header file.
 *
 * Definitions of CoreApiHelperOperAllEvent class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-4-18 zhuangzhida@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_HELPER_OPER_ALL_EVENT_H_
#define CORE_API_HELPER_OPER_ALL_EVENT_H_



#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-alarm-info.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperOperAllEventObj;



/**
 *  CoreApiHelperOperAllEvent
 * {
 *
 * }
 */
CORE_API_EXPORT CoreApiHelperOperAllEventObj core_api_helper_oper_all_event_ref(CoreApiHelperOperAllEventObj allevent);
CORE_API_EXPORT void core_api_helper_oper_all_event_unref_later(CoreApiHelperOperAllEventObj allevent);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_oper_all_event_do_get(CoreApiHelperOperAllEventObj allevent, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_oper_all_event_do_drop(CoreApiHelperOperAllEventObj allevent, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * view/edit
 */
CORE_API_EXPORT int32_t core_api_helper_oper_all_event_view_count(CoreApiHelperOperAllEventObj allevent);
CORE_API_EXPORT CoreApiAlarmInfoObj core_api_helper_oper_all_event_get_alarm_ref(CoreApiHelperOperAllEventObj allevent, int32_t index);

CORE_API_END_DECLS



#endif /* CORE_API_HELPER_OPER_ALL_EVENT_H_ */

/**
 * @}
 */
