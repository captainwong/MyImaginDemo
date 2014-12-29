
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperGetterCallerGLib header file.
 *
 * Definitions of CoreApiHelperGetterCallerGLib class.
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


#ifndef CORE_API_HELPER_GETTER_CALLER_GLIB_H_
#define CORE_API_HELPER_GETTER_CALLER_GLIB_H_

#include "core/core-api-async-caller-glib.h"
#include "core/core-api-async-caller.h"

#include "helper/core-helper-getter.h"


G_BEGIN_DECLS

#define CORE_API_HELPER_TYPE_GETTER_CALLER_GLIB              (core_api_helper_getter_caller_glib_get_type())
#define CORE_API_HELPER_GETTER_CALLER_GLIB(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj),  CORE_API_HELPER_TYPE_GETTER_CALLER_GLIB, CoreApiHelperGetterCallerGLib))
#define CORE_API_HELPER_GETTER_CALLER_GLIB_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),   CORE_API_HELPER_TYPE_GETTER_CALLER_GLIB, CoreApiHelperGetterCallerGLibClass))
#define CORE_API_HELPER_IS_GETTER_CALLER_GLIB(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj),  CORE_API_HELPER_TYPE_GETTER_CALLER_GLIB))
#define CORE_API_HELPER_IS_GETTER_CALLER_GLIB_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),   CORE_API_HELPER_TYPE_GETTER_CALLER_GLIB))
#define CORE_API_HELPER_GETTER_CALLER_GLIB_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),   CORE_API_HELPER_TYPE_GETTER_CALLER_GLIB, CoreApiHelperGetterCallerGLibClass))


typedef struct _CoreApiHelperGetterCallerGLibPrivate  CoreApiHelperGetterCallerGLibPrivate;
typedef struct _CoreApiHelperGetterCallerGLibClass CoreApiHelperGetterCallerGLibClass;
typedef struct _CoreApiHelperGetterCallerGLib CoreApiHelperGetterCallerGLib;



struct _CoreApiHelperGetterCallerGLibClass
{
    CoreApiAsyncCallerGLibClass     parent_inst;

};

struct _CoreApiHelperGetterCallerGLib
{
    CoreApiAsyncCallerGLib          parent_inst;

    /** private member */
    CoreApiHelperGetterCallerGLibPrivate *priv;
};


CoreApiHelperGetterCallerGLib * core_api_helper_getter_caller_glib_new(CoreHelperGetter *getter, CoreApiObj obj, const CoreApiAsyncCallerCb *cb);


GType core_api_helper_getter_caller_glib_get_type(void);


G_END_DECLS

#endif /* CORE_API_HELPER_GETTER_CALLER_GLIB_H_ */

/**
 * @}
 */
