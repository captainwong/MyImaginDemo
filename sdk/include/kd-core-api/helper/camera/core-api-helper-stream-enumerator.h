
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperStreamEnumerator header file.
 *
 * Definitions of KdCoreApiHelperStreamEnumerator class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
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




#ifndef CORE_API_HELPER_STREAM_ENUMERATOR_H_
#define CORE_API_HELPER_STREAM_ENUMERATOR_H_

#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"

#include "device/core-api-device-stream.h"


CORE_API_BEGIN_DECLS


typedef CoreApiObj CoreApiHelperStreamEnumeratorObj;





/** CoreApiHelperVideoCapsEnumerator */
CORE_API_EXPORT CoreApiHelperStreamEnumeratorObj core_api_helper_stream_enumerator_ref(CoreApiHelperStreamEnumeratorObj streamenum);
CORE_API_EXPORT void core_api_helper_stream_enumerator_unref_later(CoreApiHelperStreamEnumeratorObj streamenum);
/**
 * start enumerator
 * async operation.
 */
CORE_API_EXPORT void core_api_helper_stream_enumerator_enum(CoreApiHelperStreamEnumeratorObj streamenum, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
/**
 * loop each CoreApiDeviceStreamObj
 * @pre enum_result() with success.
 */
CORE_API_EXPORT uint32_t core_api_helper_stream_enumerator_count(CoreApiHelperStreamEnumeratorObj streamenum);
CORE_API_EXPORT CoreApiDeviceStreamObj core_api_helper_stream_enumerator_get_stream_ref(CoreApiHelperStreamEnumeratorObj streamenum, uint32_t index);







CORE_API_END_DECLS

#endif /* CORE_API_HELPER_STREAM_ENUMERATOR_H_ */

/**
 * @}
 */
