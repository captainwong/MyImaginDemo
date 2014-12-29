
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiCred header file.
 *
 * Definitions of KdCoreApiCred class.
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




#ifndef CORE_API_CRED_H_
#define CORE_API_CRED_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-digest-type.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiCredObj;



typedef struct
{
    void *          udata;
    void            (*destroy_udata)(void *udata);

    /**
     * MD5 Digest callback.
     *
     * @see core_api_digest()
     * @see core_api_free_digest()
     *
     * @return digest string
     */
    char *          (*get_digest)(void *udata, CoreApiCredObj cred, CoreApiDigestType, const char *username, const char *realm);

    /**
     * Text callback
     *
     * @return string
     */
    const char *    (*get_username)(void *udata, CoreApiCredObj cred);
    const char *    (*get_password)(void *udata, CoreApiCredObj cred);
}CoreApiCredCb;





CORE_API_EXPORT CoreApiCredObj core_api_cred_new(const CoreApiCredCb *cb);
CORE_API_EXPORT CoreApiCredObj core_api_cred_ref(CoreApiCredObj cred);
CORE_API_EXPORT void core_api_cred_unref(CoreApiCredObj cred);


CORE_API_END_DECLS

#endif /* CORE_API_CRED_H_ */

/**
 * @}
 */
