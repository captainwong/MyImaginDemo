
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   the CoreApiHelperActivate class header file
 *
 * file details
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-8-1 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_HELPER_ACTIVATE_H_
#define CORE_API_HELPER_ACTIVATE_H_

#include "stdint.h"

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperActivateObj;



/**
 *  CoreApiHelperActivate
 * {
 * }
 */
CORE_API_EXPORT CoreApiHelperActivateObj core_api_helper_activate_ref(CoreApiHelperActivateObj activate);
CORE_API_EXPORT void core_api_helper_activate_unref_later(CoreApiHelperActivateObj activate);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_activate_active(CoreApiHelperActivateObj activate, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_activate_deactive(CoreApiHelperActivateObj activate, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view/edit
 */
CORE_API_EXPORT void core_api_helper_activate_edit_oname(CoreApiHelperActivateObj activate, const char *oname);

CORE_API_EXPORT void core_api_helper_activate_edit_uname(CoreApiHelperActivateObj activate, const char *uname);

CORE_API_EXPORT void core_api_helper_activate_edit_upwd(CoreApiHelperActivateObj activate, const char *upwd);

CORE_API_EXPORT void core_api_helper_activate_edit_shost(CoreApiHelperActivateObj activate, const char *shost);

CORE_API_EXPORT void core_api_helper_activate_edit_sport(CoreApiHelperActivateObj activate, uint32_t sport);


CORE_API_END_DECLS

#endif /* CORE_API_HELPER_ACTIVATE_H_ */

/**
 * @}
 */
