
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiCred advance header file.
 *
 * Definitions of CoreApiCred class.
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


#ifndef CORE_API_CRED_ADVANCE_H_
#define CORE_API_CRED_ADVANCE_H_

#include "core/core-api-cred.h"

#include "core/core-credential-manager.h"
#include "core/core-digest-credential.h"
#include "core/core-text-credential.h"


CORE_API_BEGIN_DECLS


CORE_API_EXPORT CoreDigestCredential * core_api_cred_to_digest_credential(CoreApiCredObj cred);
CORE_API_EXPORT CoreTextCredential * core_api_cred_to_text_credential(CoreApiCredObj cred);



CORE_API_EXPORT CoreApiCredObj core_api_cred_new_for_cred(CoreCredentialManager *manager);

CORE_API_END_DECLS

#endif /* CORE_API_CRED_ADVANCE_H_ */

/**
 * @}
 */
