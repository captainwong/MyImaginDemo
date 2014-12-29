
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiDigestType advance header file.
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


#ifndef CORE_API_DIGEST_TYPE_ADVANCE_H_
#define CORE_API_DIGEST_TYPE_ADVANCE_H_

#include "core/core-api-digest-type.h"

#include "core/core-digest-type.h"

G_BEGIN_DECLS


CORE_API_EXPORT CoreDigestType core_api_digest_type_to_type(CoreApiDigestType apitype);
CORE_API_EXPORT CoreApiDigestType core_digest_type_to_api_type(CoreDigestType type);


G_END_DECLS

#endif /* CORE_API_DIGEST_TYPE_ADVANCE_H_ */

/**
 * @}
 */
