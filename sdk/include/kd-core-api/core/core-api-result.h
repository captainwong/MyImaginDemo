
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiResult header file.
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
 * -# 2013-6-18 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_RESULT_H_
#define CORE_API_RESULT_H_

#include "stdint.h"         //" int32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiResultObj;


CORE_API_EXPORT CoreApiResultObj core_api_result_ref(CoreApiResultObj result);
CORE_API_EXPORT void core_api_result_unref(CoreApiResultObj result);


CORE_API_EXPORT int32_t core_api_result_get_code(CoreApiResultObj result);
CORE_API_EXPORT const char * core_api_result_get_phrase(CoreApiResultObj result);




typedef struct _CoreApiResult
{
    int32_t             code;
    const char *        phrase;
}CoreApiResult;


CORE_API_VAR const CoreApiResult * CORE_API_RESULT_CONTINUE;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_SWITCHING;

CORE_API_VAR const CoreApiResult * CORE_API_RESULT_OK;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_CREATED;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_ACCEPT;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_NO_CONTENT;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_RESET_CONTENT;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_PARITAL_CONTENT;

CORE_API_VAR const CoreApiResult * CORE_API_RESULT_MULTIPLE_CHOICES;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_MOVED_PERMANENTLY;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_FOUND;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_SEE_OTHER;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_NOT_MODIFIED;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_TEMPORARY_REDIRECT;

CORE_API_VAR const CoreApiResult * CORE_API_RESULT_BAD_REQUEST;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_UNAUTHORIZED;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_PAYMENT_REQUIRED;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_FORBIDDEN;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_NOT_FOUND;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_METHOD_NOT_ALLOWED;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_NOT_ACCEPTABLE;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_3RD_AUTHENTICATION;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_REQUEST_TIMEOUT;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_CONFLICT;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_GONE;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_LENGTH_REQUIRED;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_PRECONDITION_FAILED;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_ENTITY_TOO_LARGE;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_URI_TOO_LONG;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_UNSUPPORTED_MEDIA_TYPE;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_RANGE_NOT_SATISFIABLE;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_EXPECTATION_FAILED;

CORE_API_VAR const CoreApiResult * CORE_API_RESULT_INTERNAL_SERVER_ERROR;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_NOT_IMPLEMENTED;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_BAD_GATEWAY;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_SERVICE_UNAVAILABLE;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_GATEWAY_TIMEOUT;
CORE_API_VAR const CoreApiResult * CORE_API_RESULT_VERSION_NOT_SUPPORT;

CORE_API_END_DECLS

#endif /* CORE_API_RESULT_H_ */

/**
 * @}
 */
