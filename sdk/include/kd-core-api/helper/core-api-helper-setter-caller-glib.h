
/**
 * @addtogroup KdCore
 * @{
 */

/**
 * @brief   The CoreApiHelperSetterCallerGLib header file.
 *
 * Definitions of CoreApiHelperSetterCallerGLib class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-11-29 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_SETTER_CALLER_GLIB_H_
#define CORE_API_HELPER_SETTER_CALLER_GLIB_H_

#include "core/core-api-async-caller-glib.h"
#include "core/core-api-async-caller.h"

#include "helper/core-helper-setter.h"


G_BEGIN_DECLS

#define CORE_API_HELPER_TYPE_SETTER_CALLER_GLIB              (core_api_helper_setter_caller_glib_get_type())
#define CORE_API_HELPER_SETTER_CALLER_GLIB(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj),  CORE_API_HELPER_TYPE_SETTER_CALLER_GLIB, CoreApiHelperSetterCallerGLib))
#define CORE_API_HELPER_SETTER_CALLER_GLIB_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),   CORE_API_HELPER_TYPE_SETTER_CALLER_GLIB, CoreApiHelperSetterCallerGLibClass))
#define CORE_API_HELPER_IS_SETTER_CALLER_GLIB(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj),  CORE_API_HELPER_TYPE_SETTER_CALLER_GLIB))
#define CORE_API_HELPER_IS_SETTER_CALLER_GLIB_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),   CORE_API_HELPER_TYPE_SETTER_CALLER_GLIB))
#define CORE_API_HELPER_SETTER_CALLER_GLIB_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),   CORE_API_HELPER_TYPE_SETTER_CALLER_GLIB, CoreApiHelperSetterCallerGLibClass))


typedef struct _CoreApiHelperSetterCallerGLibPrivate  CoreApiHelperSetterCallerGLibPrivate;
typedef struct _CoreApiHelperSetterCallerGLibClass CoreApiHelperSetterCallerGLibClass;
typedef struct _CoreApiHelperSetterCallerGLib CoreApiHelperSetterCallerGLib;



struct _CoreApiHelperSetterCallerGLibClass
{
    CoreApiAsyncCallerGLibClass     parent_inst;

};

struct _CoreApiHelperSetterCallerGLib
{
    CoreApiAsyncCallerGLib          parent_inst;

    /** private member */
    CoreApiHelperSetterCallerGLibPrivate *priv;
};


CoreApiHelperSetterCallerGLib * core_api_helper_setter_caller_glib_new(CoreHelperSetter *setter, CoreApiObj obj, const CoreApiAsyncCallerCb *cb);


GType core_api_helper_setter_caller_glib_get_type(void);


G_END_DECLS

#endif /* CORE_API_HELPER_SETTER_CALLER_GLIB_H_ */

/**
 * @}
 */
