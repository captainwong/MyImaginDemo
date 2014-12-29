
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperDateTime header file.
 *
 * Definitions of CoreApiHelperDateTime class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-11-29 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_DATETIME_H_
#define CORE_API_HELPER_DATETIME_H_

#include "time.h"
#if defined(_MSC_VER)
#include "WinSock2.h"  //" struct timeval
#else
#include "sys/time.h"
#endif



#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperDateTimeObj;



/**
 *  CoreApiHelperDateTime
 * {
 *      struct timeval  tv;
 * }
 */
CORE_API_EXPORT CoreApiHelperDateTimeObj core_api_helper_datetime_ref(CoreApiHelperDateTimeObj datetime);
CORE_API_EXPORT void core_api_helper_datetime_unref_later(CoreApiHelperDateTimeObj datetime);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_datetime_get(CoreApiHelperDateTimeObj datetime, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_datetime_set(CoreApiHelperDateTimeObj datetime, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view/edit
 */
// UTC timeval
CORE_API_EXPORT const struct timeval * core_api_helper_datetime_view_tv(CoreApiHelperDateTimeObj datetime);
// NULL means to set current.
CORE_API_EXPORT void core_api_helper_datetime_edit_tv(CoreApiHelperDateTimeObj datetime, const struct timeval *tv);




CORE_API_END_DECLS

#endif /* CORE_API_HELPER_DATETIME_H_ */

/**
 * @}
 */
