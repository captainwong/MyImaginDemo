
/**
 * @addtogroup KdCore
 * @{
 */

/**
 * @brief   The CoreApiHelperObjectGLib header file.
 *
 * Definitions of CoreApiHelperObjectGLib class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-12-7 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_OBJECT_GLIB_H_
#define CORE_API_HELPER_OBJECT_GLIB_H_

#include "glib-object.h"

#include "core/core-api-global.h"

G_BEGIN_DECLS

#define CORE_API_HELPER_TYPE_OBJECT_GLIB              (core_api_helper_object_glib_get_type())
#define CORE_API_HELPER_OBJECT_GLIB(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj),  CORE_API_HELPER_TYPE_OBJECT_GLIB, CoreApiHelperObjectGLib))
#define CORE_API_HELPER_OBJECT_GLIB_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),   CORE_API_HELPER_TYPE_OBJECT_GLIB, CoreApiHelperObjectGLibClass))
#define CORE_API_HELPER_IS_OBJECT_GLIB(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj),  CORE_API_HELPER_TYPE_OBJECT_GLIB))
#define CORE_API_HELPER_IS_OBJECT_GLIB_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),   CORE_API_HELPER_TYPE_OBJECT_GLIB))
#define CORE_API_HELPER_OBJECT_GLIB_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),   CORE_API_HELPER_TYPE_OBJECT_GLIB, CoreApiHelperObjectGLibClass))


typedef struct _CoreApiHelperObjectGLibPrivate  CoreApiHelperObjectGLibPrivate;
typedef struct _CoreApiHelperObjectGLibClass CoreApiHelperObjectGLibClass;
typedef struct _CoreApiHelperObjectGLib CoreApiHelperObjectGLib;



struct _CoreApiHelperObjectGLibClass
{
    GObjectClass                    parent_inst;
};

struct _CoreApiHelperObjectGLib
{
    GObject                         parent_inst;

    /** private member */
    CoreApiHelperObjectGLibPrivate *priv;
};



CORE_API_EXPORT void core_api_helper_object_glib_unref_later(CoreApiHelperObjectGLib *self);


CORE_API_EXPORT GType core_api_helper_object_glib_get_type(void);


G_END_DECLS

#endif /* CORE_API_HELPER_OBJECT_GLIB_H_ */

/**
 * @}
 */
