
/**
 * @addtogroup KdCoreApi package
 * @{
 */

/**
 * @brief    file description
 *
 *  file details
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-9-15 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_ACC_DEV_H_
#define CORE_API_ACC_DEV_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiAccDevObj;


CORE_API_EXPORT CoreApiAccDevObj core_api_acc_dev_new(void);
CORE_API_EXPORT CoreApiAccDevObj core_api_acc_dev_new_full(const char *sn, const char *uid, const char *product_name, const char *product_desc, const char *username, const char *password);
CORE_API_EXPORT CoreApiAccDevObj core_api_acc_dev_ref(CoreApiAccDevObj dev);
CORE_API_EXPORT void core_api_acc_dev_unref(CoreApiAccDevObj dev);



CORE_API_EXPORT const char * core_api_acc_dev_get_sn(CoreApiAccDevObj dev);
CORE_API_EXPORT void core_api_acc_dev_set_sn(CoreApiAccDevObj dev, const char *sn);

CORE_API_EXPORT const char * core_api_acc_dev_get_uid(CoreApiAccDevObj dev);
CORE_API_EXPORT void core_api_acc_dev_set_uid(CoreApiAccDevObj dev, const char *uid);

CORE_API_EXPORT const char * core_api_acc_dev_get_product_name(CoreApiAccDevObj dev);
CORE_API_EXPORT void core_api_acc_dev_set_product_name(CoreApiAccDevObj dev, const char *name);

CORE_API_EXPORT const char * core_api_acc_dev_get_product_desc(CoreApiAccDevObj dev);
CORE_API_EXPORT void core_api_acc_dev_set_product_desc(CoreApiAccDevObj dev, const char *desc);

CORE_API_EXPORT const char * core_api_acc_dev_get_alias_name(CoreApiAccDevObj dev);
CORE_API_EXPORT void core_api_acc_dev_set_alias_name(CoreApiAccDevObj dev, const char *name);

CORE_API_EXPORT const char * core_api_acc_dev_get_username(CoreApiAccDevObj dev);
CORE_API_EXPORT void core_api_acc_dev_set_username(CoreApiAccDevObj dev, const char *username);

CORE_API_EXPORT const char * core_api_acc_dev_get_password(CoreApiAccDevObj dev);
CORE_API_EXPORT void core_api_acc_dev_set_password(CoreApiAccDevObj dev, const char *password);


CORE_API_END_DECLS

#endif /* CORE_API_ACC_DEV_H_ */

/**
 * @}
 */
