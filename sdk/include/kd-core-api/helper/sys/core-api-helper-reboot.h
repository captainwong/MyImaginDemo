/**
 * @brief   The CoreApiHelperReboot header file.
 *
 * Definitions of CoreApiHelperReboot class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-12-11 zhuangzhida@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_HELPER_REBOOT_H_
#define CORE_API_HELPER_REBOOT_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperRebootObj;



/**
 *  CoreApiHelperReboot
 * {
 *     int     delay;
 *     boolean genteel;
 *     boolean forceupdt;
 * }
 */
CORE_API_EXPORT CoreApiHelperRebootObj core_api_helper_reboot_ref(CoreApiHelperRebootObj reboot);
CORE_API_EXPORT void core_api_helper_reboot_unref_later(CoreApiHelperRebootObj reboot);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_reboot_reboot(CoreApiHelperRebootObj reboot, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view/edit
 */
CORE_API_EXPORT void core_api_helper_reboot_edit_delay(CoreApiHelperRebootObj reboot, int32_t delay);

CORE_API_EXPORT void core_api_helper_reboot_edit_genteel(CoreApiHelperRebootObj reboot, int32_t genteel);

CORE_API_EXPORT void core_api_helper_reboot_edit_forceupdt(CoreApiHelperRebootObj reboot, int32_t forceupdt);



CORE_API_END_DECLS

#endif /* CORE_API_HELPER_REBOOT_H_ */
