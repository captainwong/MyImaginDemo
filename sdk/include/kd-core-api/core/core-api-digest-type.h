
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiDigestType header file.
 *
 * Definitions of CoreApiDigestType class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-9-18 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_DIGEST_TYPE_H_
#define CORE_API_DIGEST_TYPE_H_

#include "core/core-api-global.h"


CORE_API_BEGIN_DECLS

typedef enum
{
    CORE_API_DIGEST_MD5     = 1,
    CORE_API_DIGEST_SHA1    = 2,
    CORE_API_DIGEST_SHA256  = 4,
}CoreApiDigestType;

CORE_API_EXPORT char * core_api_digest(CoreApiDigestType type, const char *username, const char *domain, const char *password);

CORE_API_EXPORT void core_api_free_digest(char *string);

CORE_API_END_DECLS

#endif /* CORE_API_DIGEST_TYPE_H_ */

/**
 * @}
 */
