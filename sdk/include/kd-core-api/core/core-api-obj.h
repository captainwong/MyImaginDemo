
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiObj header file.
 *
 * Definitions of KdCoreApiObj class.
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




#ifndef CORE_API_OBJ_H_
#define CORE_API_OBJ_H_

#include "stdio.h"                  //" NULL
#include "core/core-api-global.h"


CORE_API_BEGIN_DECLS


#define POINTER_TO_OBJ(p)              ((long)(p))
#define OBJ_TO_POINTER(l)              ((void *)(l))


/**
 * core api object.
 *
 * @see CORE_API_INVALID_OBJ
 * @see core_api_obj_is_valid()
 */
typedef long CoreApiObj;

/**
 * invalid object
 */
#ifdef  __cplusplus
#define CORE_API_INVALID_OBJ             (0L)
#else
#define CORE_API_INVALID_OBJ             (POINTER_TO_OBJ(NULL))
#endif  /* __cplusplus */
/**
 * macro function to verify object is valid
 */
#define core_api_obj_is_valid(obj)       (CORE_API_INVALID_OBJ != (obj))


CORE_API_END_DECLS

#endif /* CORE_API_OBJ_H_ */

/**
 * @}
 */
