/**
 * @addtogroup d510
 * @{
 */

/**
 * @brief   The D510HbApiEnums header file.
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision:$
 * $Date:$
 * $Id:$
 *
 * Modify Logs:
 * -# 2014-9-28 zhangquan@imagintech.com.cn create.
 *
 */

#ifndef D510HB_API_ENUMS_H_
#define D510HB_API_ENUMS_H_

#include <core/core-api-global.h>

CORE_API_BEGIN_DECLS

typedef enum {
    D510_HB_API_SERVERA,
    D510_HB_API_SERVERB,
}D510HbApiServerName;

typedef enum {
    D510_HB_API_SERVER_PRIMARY,
    D510_Hb_API_SERVER_SLAVE,
}D510HbApiServerType;


CORE_API_END_DECLS

#endif /* D510HB_API_ENUMS_H_ */

/**
 * @}
 */
