
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

#ifndef CORE_API_DEVICE_GLIB_H_
#define CORE_API_DEVICE_GLIB_H_

#include "glib-object.h"

#include "device/core-device.h"
#include "core/core-api-global.h"


CORE_API_BEGIN_DECLS

#define CORE_API_TYPE_DEVICE_GLIB              (core_api_device_glib_get_type())
#define CORE_API_DEVICE_GLIB(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj),  CORE_API_TYPE_DEVICE_GLIB, CoreApiDeviceGLib))
#define CORE_API_DEVICE_GLIB_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),   CORE_API_TYPE_DEVICE_GLIB, CoreApiDeviceGLibClass))
#define CORE_API_IS_DEVICE_GLIB(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj),  CORE_API_TYPE_DEVICE_GLIB))
#define CORE_API_IS_DEVICE_GLIB_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),   CORE_API_TYPE_DEVICE_GLIB))
#define CORE_API_DEVICE_GLIB_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),   CORE_API_TYPE_DEVICE_GLIB, CoreApiDeviceGLibClass))


typedef struct _CoreApiDeviceGLibPrivate  CoreApiDeviceGLibPrivate;
typedef struct _CoreApiDeviceGLibClass CoreApiDeviceGLibClass;
typedef struct _CoreApiDeviceGLib CoreApiDeviceGLib;



struct _CoreApiDeviceGLibClass
{
    GObjectClass                    parent_inst;
};

struct _CoreApiDeviceGLib
{
    GObject                         parent_inst;

    /** private member */
    CoreApiDeviceGLibPrivate *      priv;
};



/** not ref */
CORE_API_EXPORT CoreDevice * core_api_device_glib_get_device(CoreApiDeviceGLib *self);



CORE_API_EXPORT GType core_api_device_glib_get_type(void);

CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_GLIB_H_ */

/**
 * @}
 */
