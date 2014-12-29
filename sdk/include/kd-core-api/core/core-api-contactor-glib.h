
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiContactorGLib header file.
 *
 * Definitions of CoreApiContactorGLib class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-9-18 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_CONTACTOR_GLIB_H_
#define CORE_API_CONTACTOR_GLIB_H_

#include "glib-object.h"

#include "core/core-api-global.h"

#include "core/core-contactor.h"

G_BEGIN_DECLS

#define CORE_API_TYPE_CONTACTOR_GLIB              (core_api_contactor_glib_get_type())
#define CORE_API_CONTACTOR_GLIB(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj),  CORE_API_TYPE_CONTACTOR_GLIB, CoreApiContactorGLib))
#define CORE_API_CONTACTOR_GLIB_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),   CORE_API_TYPE_CONTACTOR_GLIB, CoreApiContactorGLibClass))
#define CORE_API_IS_CONTACTOR_GLIB(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj),  CORE_API_TYPE_CONTACTOR_GLIB))
#define CORE_API_IS_CONTACTOR_GLIB_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),   CORE_API_TYPE_CONTACTOR_GLIB))
#define CORE_API_CONTACTOR_GLIB_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),   CORE_API_TYPE_CONTACTOR_GLIB, CoreApiContactorGLibClass))


typedef struct _CoreApiContactorGLibPrivate  CoreApiContactorGLibPrivate;
typedef struct _CoreApiContactorGLibClass CoreApiContactorGLibClass;
typedef struct _CoreApiContactorGLib CoreApiContactorGLib;


struct _CoreApiContactorGLibClass
{
    GObjectClass                    parent_inst;

    /** purge virtual methods, you MUST implement them */
    CoreContactor *                 (*to_contactor)(CoreApiContactorGLib *self);
};

struct _CoreApiContactorGLib
{
    GObject                         parent_inst;

    /** private member */
    CoreApiContactorGLibPrivate *   priv;
};


CORE_API_EXPORT CoreContactor * core_api_contactor_glib_to_contactor(CoreApiContactorGLib *self);


CORE_API_EXPORT GType core_api_contactor_glib_get_type(void);


G_END_DECLS

#endif /* CORE_API_CONTACTOR_GLIB_H_ */

/**
 * @}
 */
