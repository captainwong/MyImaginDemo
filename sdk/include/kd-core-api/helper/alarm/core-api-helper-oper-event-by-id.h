/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperOperEventById header file.
 *
 * Definitions of CoreApiHelperOperEventById class.
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

#ifndef CORE_API_HELPER_OPER_EVENT_BY_ID_H_
#define CORE_API_HELPER_OPER_EVENT_BY_ID_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-alarm-info.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperOperEventByIdObj;



/**
 *  CoreApiHelperOperEventById
 * {
 *
 * }
 */
CORE_API_EXPORT CoreApiHelperOperEventByIdObj core_api_helper_oper_event_by_id_ref(CoreApiHelperOperEventByIdObj allevent);
CORE_API_EXPORT void core_api_helper_oper_event_by_id_unref_later(CoreApiHelperOperEventByIdObj allevent);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_oper_event_by_id_do_get(CoreApiHelperOperEventByIdObj allevent, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_oper_event_by_id_do_drop(CoreApiHelperOperEventByIdObj allevent, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * view/edit
 */
CORE_API_EXPORT void core_api_helper_oper_event_by_id_edit_id(CoreApiHelperOperEventByIdObj allevent, const char* id);
CORE_API_EXPORT CoreApiAlarmInfoObj core_api_helper_oper_event_by_id_view_alarm(CoreApiHelperOperEventByIdObj allevent);

CORE_API_END_DECLS



#endif /* CORE_API_HELPER_OPER_EVENT_BY_ID_H_ */

/**
 * @}
 */
