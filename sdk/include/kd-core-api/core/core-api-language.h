
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiLanguage header file.
 *
 * Definitions of KdCoreApiLanguage class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-02-08 zhuangzhida@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_LANGUAGE_H_
#define CORE_API_LANGUAGE_H_

#include "core/core-api-global.h"


CORE_API_BEGIN_DECLS

typedef enum
{
    CORE_API_LANGUAGE_en_US        = 0,
    CORE_API_LANGUAGE_zh_CN        = 1,
    CORE_API_LANGUAGE_zh_TW        = 2,
}CoreApiLanguage;

CORE_API_END_DECLS

#endif /* CORE_API_LANGUAGE_H_ */

/**
 * @}
 */
