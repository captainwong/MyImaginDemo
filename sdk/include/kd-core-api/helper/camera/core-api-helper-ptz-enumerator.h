
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperPtzEnumerator header file.
 *
 * Definitions of KdCoreApiHelperPtzEnumerator class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-20 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_HELPER_PTZ_ENUMERATOR_H_
#define CORE_API_HELPER_PTZ_ENUMERATOR_H_

#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"

#include "device/core-api-device-ptz.h"



CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperPtzEnumeratorObj;



/** CoreApiHelperPtzEnumerator */
CORE_API_EXPORT CoreApiHelperPtzEnumeratorObj core_api_helper_ptz_enumerator_ref(CoreApiHelperPtzEnumeratorObj ptzenum);
CORE_API_EXPORT void core_api_helper_ptz_enumerator_unref_later(CoreApiHelperPtzEnumeratorObj ptzenum);
/**
 * start enumerator
 * async operation.
 */
CORE_API_EXPORT void core_api_helper_ptz_enumerator_enum(CoreApiHelperPtzEnumeratorObj ptzenum, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * loop each CoreApiDevicePtz
 * @pre enum_result() with success.
 */
CORE_API_EXPORT uint32_t core_api_helper_ptz_enumerator_count(CoreApiHelperPtzEnumeratorObj ptzenum);
CORE_API_EXPORT CoreApiDevicePtzObj core_api_helper_ptz_enumerator_get_ptz_ref(CoreApiHelperPtzEnumeratorObj ptzenum, uint32_t index);





CORE_API_END_DECLS

#endif /* CORE_API_HELPER_PTZ_ENUMERATOR_H_ */

/**
 * @}
 */
