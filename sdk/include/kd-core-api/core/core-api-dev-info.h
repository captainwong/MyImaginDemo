
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDevInfo header file.
 *
 * Definitions of KdCoreApiDevInfo class.
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




#ifndef CORE_API_DEV_INFO_H_
#define CORE_API_DEV_INFO_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDevInfoObj;



CORE_API_EXPORT CoreApiDevInfoObj core_api_dev_info_ref(CoreApiDevInfoObj info);
CORE_API_EXPORT void core_api_dev_info_unref(CoreApiDevInfoObj info);

CORE_API_EXPORT const char * core_api_dev_info_get_sn(CoreApiDevInfoObj info);

CORE_API_EXPORT const char * core_api_dev_info_get_uid(CoreApiDevInfoObj info);

CORE_API_EXPORT const char * core_api_dev_info_get_product_name(CoreApiDevInfoObj info);
CORE_API_EXPORT const char * core_api_dev_info_get_product_desc(CoreApiDevInfoObj info);

/**
 * @remark only for local device
 */
CORE_API_EXPORT const char * core_api_dev_info_get_dev_name(CoreApiDevInfoObj info);

/**
 * @remark only for cloud device
 */
CORE_API_EXPORT const char * core_api_dev_info_get_alias_name(CoreApiDevInfoObj info);


/**
 * is device been actived
 * @retval boolean.
 */
CORE_API_EXPORT int core_api_dev_info_is_actived(CoreApiDevInfoObj info);

CORE_API_END_DECLS

#endif /* CORE_API_DEV_INFO_H_ */

/**
 * @}
 */
