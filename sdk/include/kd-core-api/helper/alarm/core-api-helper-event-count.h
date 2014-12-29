/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperEventCount header file.
 *
 * Definitions of CoreApiHelperEventCount class.
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
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

#ifndef CORE_API_HELPER_EVENT_COUNT_H_
#define CORE_API_HELPER_EVENT_COUNT_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"



CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperEventCountObj;



/**
 *  CoreApiHelperEventCount
 * {
 *
 * }
 */
CORE_API_EXPORT CoreApiHelperEventCountObj core_api_helper_event_count_ref(CoreApiHelperEventCountObj event_count);
CORE_API_EXPORT void core_api_helper_event_count_unref_later(CoreApiHelperEventCountObj event_count);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_event_count_get(CoreApiHelperEventCountObj event_count, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view
 */
CORE_API_EXPORT int32_t core_api_helper_event_count_view_count(CoreApiHelperEventCountObj event_count);


CORE_API_END_DECLS




#endif /* CORE_API_HELPER_EVENT_COUNT_H_ */

/**
 * @}
 */
