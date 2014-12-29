
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiAsyncCaller header file.
 *
 * Definitions of KdCoreApiAsyncCaller class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-19 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_ASYNC_CALLER_H_
#define CORE_API_ASYNC_CALLER_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-result.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiAsyncCallerObj;

typedef struct
{
    void *              udata;

    void                (*on_result)(void *udata, CoreApiObj obj, CoreApiAsyncCallerObj caller, CoreApiResultObj result);
}CoreApiAsyncCallerCb;



CORE_API_EXPORT CoreApiAsyncCallerObj core_api_async_caller_ref(CoreApiAsyncCallerObj caller);
CORE_API_EXPORT void core_api_async_caller_unref_later(CoreApiAsyncCallerObj caller);
/**
 * cancel a async call
 *
 * @remark   The call be canceled, but it NOT be released, you MUST do it explicit.
 */
CORE_API_EXPORT void core_api_async_caller_cancel(CoreApiAsyncCallerObj caller);

CORE_API_END_DECLS

#endif /* CORE_API_ASYNC_CALLER_H_ */

/**
 * @}
 */
