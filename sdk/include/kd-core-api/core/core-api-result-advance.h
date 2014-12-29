
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiResult advance header file.
 *
 * Definitions of CoreApiResult class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-7-17 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_RESULT_ADVANCE_H_
#define CORE_API_RESULT_ADVANCE_H_

#include "core/core-result.h"

#include "core/core-api-result.h"
#include "core/core-api-global.h"


CORE_API_BEGIN_DECLS

CORE_API_EXPORT CoreApiResultObj core_api_result_new_full(int32_t code, const char *phrase);

CORE_API_EXPORT CoreApiResultObj core_api_result_new_with_result(CoreResult *rslt);

CORE_API_END_DECLS


#endif /* CORE_API_RESULT_ADVANCE_H_ */

/**
 * @}
 */
