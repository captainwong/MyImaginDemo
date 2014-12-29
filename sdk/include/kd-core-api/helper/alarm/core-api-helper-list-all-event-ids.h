/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperListAllEvent header file.
 *
 * Definitions of CoreApiHelperListAllEvent class.
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
#ifndef CORE_API_HELPER_LIST_ALL_EVENT_IDS_H_
#define CORE_API_HELPER_LIST_ALL_EVENT_IDS_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"


CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperListAllEventIdsObj;



/**
 *  CoreApiHelperListAllEventIds
 * {
 *
 * }
 */
CORE_API_EXPORT CoreApiHelperListAllEventIdsObj core_api_helper_list_all_event_ids_ref(CoreApiHelperListAllEventIdsObj eventids);
CORE_API_EXPORT void core_api_helper_list_all_event_ids_unref_later(CoreApiHelperListAllEventIdsObj eventids);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_list_all_event_ids_do_list(CoreApiHelperListAllEventIdsObj eventids, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view/edit
 */
CORE_API_EXPORT int32_t core_api_helper_list_all_event_ids_view_count(CoreApiHelperListAllEventIdsObj eventids);
CORE_API_EXPORT char* core_api_helper_list_all_event_ids_get_id_ref(CoreApiHelperListAllEventIdsObj eventids, int32_t index);

CORE_API_END_DECLS



#endif /* CORE_API_HELPER_LIST_ALL_EVENT_IDS_H_ */

/**
 * @}
 */
