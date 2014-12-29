
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiAsyncCaller advance header file.
 *
 * Definitions of CoreApiAsyncCaller class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-9-22 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_ASYNC_CALLER_ADVANCE_H_
#define CORE_API_ASYNC_CALLER_ADVANCE_H_

#include "core/core-api-async-caller.h"

#include "core/core-api-async-caller-glib.h"

CORE_API_BEGIN_DECLS


CORE_API_EXPORT CoreApiAsyncCallerObj core_api_async_caller_new(CoreApiAsyncCallerGLib *caller);


CORE_API_END_DECLS

#endif /* CORE_API_ASYNC_CALLER_ADVANCE_H_ */

/**
 * @}
 */
