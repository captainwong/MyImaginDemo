/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperPowerFreq header file.
 *
 * Definitions of CoreApiHelperPowerFreq class.
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-01-04 zhuangzhida@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_POWER_FREQ_H_
#define CORE_API_HELPER_POWER_FREQ_H_

#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiHelperPowerFreqObj;

CORE_API_EXPORT CoreApiHelperPowerFreqObj core_api_helper_power_freq_ref(CoreApiHelperPowerFreqObj power_freq);
CORE_API_EXPORT void core_api_helper_power_freq_unref(CoreApiHelperPowerFreqObj power_freq);

CORE_API_EXPORT void core_api_helper_power_freq_set(CoreApiHelperPowerFreqObj power_freq, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_power_freq_get(CoreApiHelperPowerFreqObj power_freq, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

CORE_API_EXPORT double core_api_helper_power_freq_view_freq(CoreApiHelperPowerFreqObj power_freq);
CORE_API_EXPORT void core_api_helper_power_freq_edit_freq(CoreApiHelperPowerFreqObj power_freq, double freq);

CORE_API_END_DECLS


#endif /* CORE_API_HELPER_POWER_FREQ_H_ */

/**
 * @}
 */
