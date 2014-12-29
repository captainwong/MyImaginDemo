
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperEnumeratorCallerGLib header file.
 *
 * Definitions of CoreApiHelperEnumeratorCallerGLib class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-9-23 laizuobin@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_ENUMERATOR_CALLER_GLIB_H_
#define CORE_API_HELPER_ENUMERATOR_CALLER_GLIB_H_


#include "core/core-api-async-caller-glib.h"
#include "core/core-api-async-caller.h"

#include "helper/core-helper-enumerator.h"


G_BEGIN_DECLS

#define CORE_API_HELPER_TYPE_ENUMERATOR_CALLER_GLIB              (core_api_helper_enumerator_caller_glib_get_type())
#define CORE_API_HELPER_ENUMERATOR_CALLER_GLIB(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj),  CORE_API_HELPER_TYPE_ENUMERATOR_CALLER_GLIB, CoreApiHelperEnumeratorCallerGLib))
#define CORE_API_HELPER_ENUMERATOR_CALLER_GLIB_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),   CORE_API_HELPER_TYPE_ENUMERATOR_CALLER_GLIB, CoreApiHelperEnumeratorCallerGLibClass))
#define CORE_API_HELPER_IS_ENUMERATOR_CALLER_GLIB(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj),  CORE_API_HELPER_TYPE_ENUMERATOR_CALLER_GLIB))
#define CORE_API_HELPER_IS_ENUMERATOR_CALLER_GLIB_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),   CORE_API_HELPER_TYPE_ENUMERATOR_CALLER_GLIB))
#define CORE_API_HELPER_ENUMERATOR_CALLER_GLIB_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),   CORE_API_HELPER_TYPE_ENUMERATOR_CALLER_GLIB, CoreApiHelperEnumeratorCallerGLibClass))


typedef struct _CoreApiHelperEnumeratorCallerGLibPrivate  CoreApiHelperEnumeratorCallerGLibPrivate;
typedef struct _CoreApiHelperEnumeratorCallerGLibClass CoreApiHelperEnumeratorCallerGLibClass;
typedef struct _CoreApiHelperEnumeratorCallerGLib CoreApiHelperEnumeratorCallerGLib;



struct _CoreApiHelperEnumeratorCallerGLibClass
{
    CoreApiAsyncCallerGLibClass     parent_inst;

};

struct _CoreApiHelperEnumeratorCallerGLib
{
    CoreApiAsyncCallerGLib          parent_inst;

    /** private member */
    CoreApiHelperEnumeratorCallerGLibPrivate *priv;
};


CoreApiHelperEnumeratorCallerGLib * core_api_helper_enumerator_caller_glib_new(CoreHelperEnumerator *enumerator, CoreApiObj obj, const CoreApiAsyncCallerCb *cb);


GType core_api_helper_enumerator_caller_glib_get_type(void);


G_END_DECLS

#endif /* CORE_API_HELPER_ENUMERATOR_CALLER_GLIB_H_ */

/**
 * @}
 */
