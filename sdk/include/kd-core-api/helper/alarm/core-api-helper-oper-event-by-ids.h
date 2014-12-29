/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperOperEventByIds header file.
 *
 * Definitions of CoreApiHelperOperEventByIds class.
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

#ifndef CORE_API_HELPER_OPER_EVENT_BY_IDS_H_
#define CORE_API_HELPER_OPER_EVENT_BY_IDS_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-alarm-info.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperOperEventByIdsObj;



/**
 *  CoreApiHelperOperEventByIds
 * {
 *
 * }
 */
CORE_API_EXPORT CoreApiHelperOperEventByIdsObj core_api_helper_oper_event_by_ids_ref(CoreApiHelperOperEventByIdsObj allevent);
CORE_API_EXPORT void core_api_helper_oper_event_by_ids_unref_later(CoreApiHelperOperEventByIdsObj allevent);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_oper_event_by_ids_do_get(CoreApiHelperOperEventByIdsObj allevent, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_oper_event_by_ids_do_drop(CoreApiHelperOperEventByIdsObj allevent, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * view/edit
 */
CORE_API_EXPORT void core_api_helper_oper_event_by_ids_edit_ids(CoreApiHelperOperEventByIdsObj allevent, const char** id, int32_t count);
CORE_API_EXPORT CoreApiAlarmInfoObj core_api_helper_oper_event_by_ids_view_alarm_ref(CoreApiHelperOperEventByIdsObj allevent, int32_t index);

CORE_API_END_DECLS


#endif /* CORE_API_HELPER_OPER_EVENT_BY_IDS_H_ */

/**
 * @}
 */
