
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDev header file.
 *
 * Definitions of KdCoreApiDev class.
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




#ifndef CORE_API_DEV_H_
#define CORE_API_DEV_H_

#include "stdint.h"         //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-dev-info.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDevObj;


CORE_API_EXPORT CoreApiDevObj core_api_dev_ref(CoreApiDevObj dev);
CORE_API_EXPORT void core_api_dev_unref(CoreApiDevObj dev);

CORE_API_EXPORT CoreApiDevInfoObj core_api_dev_get_info_ref(CoreApiDevObj dev);

CORE_API_EXPORT CORE_API_DEPRECATED CoreApiObj core_api_dev_get_discoverer(CoreApiDevObj dev);

/**
 * list all discoverers to dev
 *
 *@param [out]      discoverers     array of discoverers to dev
 *@param [in,out]   count           array size for input, discoverers count for output.
 */
CORE_API_EXPORT void core_api_dev_list_discoverers(CoreApiDevObj dev, CoreApiObj discoverers[], uint32_t *count);

CORE_API_END_DECLS

#endif /* CORE_API_DEV_H_ */

/**
 * @}
 */
