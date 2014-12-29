/**
 * @brief   The CoreApiHelperDevInfo header file.
 *
 * Definitions of CoreApiHelperDevInfo class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-12-12 zhuangzhida@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_DEVINFO_H_
#define CORE_API_HELPER_DEVINFO_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperDevInfoObj;



/**
 *  CoreApiHelperDevInfo
 * {
 *
 * }
 */
CORE_API_EXPORT CoreApiHelperDevInfoObj core_api_helper_devinfo_ref(CoreApiHelperDevInfoObj devinfo);
CORE_API_EXPORT void core_api_helper_devinfo_unref_later(CoreApiHelperDevInfoObj devinfo);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_devinfo_get(CoreApiHelperDevInfoObj devinfo, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view/edit
 */
CORE_API_EXPORT const char * core_api_helper_devinfo_view_sn(CoreApiHelperDevInfoObj devinfo);

CORE_API_EXPORT const char * core_api_helper_devinfo_view_product(CoreApiHelperDevInfoObj devinfo);

CORE_API_EXPORT const char * core_api_helper_devinfo_view_fmver(CoreApiHelperDevInfoObj devinfo);

CORE_API_EXPORT const char * core_api_helper_devinfo_view_hwver(CoreApiHelperDevInfoObj devinfo);


CORE_API_END_DECLS


#endif /* CORE_API_HELPER_DEVINFO_H_ */

/**
 * @}
 */
