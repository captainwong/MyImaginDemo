
/**
 * @addtogroup KdCoreApi
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
 * -# 2014-9-22 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_DEVICE_ADVANCE_H_
#define CORE_API_DEVICE_ADVANCE_H_

#include "device/core-api-device.h"
#include "device/core-api-device-glib.h"

CORE_API_BEGIN_DECLS


/** not ref */
CORE_API_EXPORT CoreApiDeviceGLib * core_api_device_obj_to_device_glib(CoreApiDeviceObj device);


CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_ADVANCE_H_ */

/**
 * @}
 */
