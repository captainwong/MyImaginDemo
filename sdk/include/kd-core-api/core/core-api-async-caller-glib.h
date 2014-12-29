
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiAsyncCallerGLib header file.
 *
 * Definitions of CoreApiAsyncCallerGLib class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-7-17 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_ASYNC_CALLER_GLIB_H_
#define CORE_API_ASYNC_CALLER_GLIB_H_


#include "glib-object.h"

#include "core/core-api-global.h"
#include "core/core-api-async-caller.h"

G_BEGIN_DECLS

#define CORE_API_TYPE_ASYNC_CALLER_GLIB              (core_api_async_caller_glib_get_type())
#define CORE_API_ASYNC_CALLER_GLIB(obj)              (G_TYPE_CHECK_INSTANCE_CAST((obj),  CORE_API_TYPE_ASYNC_CALLER_GLIB, CoreApiAsyncCallerGLib))
#define CORE_API_ASYNC_CALLER_GLIB_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST((klass),   CORE_API_TYPE_ASYNC_CALLER_GLIB, CoreApiAsyncCallerGLibClass))
#define CORE_API_IS_ASYNC_CALLER_GLIB(obj)           (G_TYPE_CHECK_INSTANCE_TYPE((obj),  CORE_API_TYPE_ASYNC_CALLER_GLIB))
#define CORE_API_IS_ASYNC_CALLER_GLIB_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),   CORE_API_TYPE_ASYNC_CALLER_GLIB))
#define CORE_API_ASYNC_CALLER_GLIB_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS((obj),   CORE_API_TYPE_ASYNC_CALLER_GLIB, CoreApiAsyncCallerGLibClass))


typedef struct _CoreApiAsyncCallerGLibPrivate  CoreApiAsyncCallerGLibPrivate;
typedef struct _CoreApiAsyncCallerGLibClass CoreApiAsyncCallerGLibClass;
typedef struct _CoreApiAsyncCallerGLib CoreApiAsyncCallerGLib;



struct _CoreApiAsyncCallerGLibClass
{
    GObjectClass                    parent_inst;

    /** virtual methods, you COULD override them */
    void                            (*result)(CoreApiAsyncCallerGLib *self, CoreApiResultObj result);
    void                            (*cancel)(CoreApiAsyncCallerGLib *self);
    gboolean                        (*is_canceled)(CoreApiAsyncCallerGLib *self);
};

struct _CoreApiAsyncCallerGLib
{
    GObject                         parent_inst;

    /** private member */
    CoreApiAsyncCallerGLibPrivate * priv;

    /** protected member */
    gulong                          handler;
};


CORE_API_EXPORT CoreApiAsyncCallerGLib * core_api_async_caller_glib_new(CoreApiObj obj, const CoreApiAsyncCallerCb *cb);
CORE_API_EXPORT void core_api_async_caller_glib_unref_later(CoreApiAsyncCallerGLib *self);


CORE_API_EXPORT gboolean core_api_async_caller_glib_is_unref_later(CoreApiAsyncCallerGLib *self);


CORE_API_EXPORT void core_api_async_caller_glib_result(CoreApiAsyncCallerGLib *self, CoreApiResultObj result);
CORE_API_EXPORT void core_api_async_caller_glib_cancel(CoreApiAsyncCallerGLib *self);

/** protected methods */
CORE_API_EXPORT CoreApiObj core_api_async_caller_glib_get_obj(CoreApiAsyncCallerGLib *self);
CORE_API_EXPORT void core_api_async_caller_glib_set_obj(CoreApiAsyncCallerGLib *self, CoreApiObj obj);

CORE_API_EXPORT const CoreApiAsyncCallerCb * core_api_async_caller_glib_get_cb(CoreApiAsyncCallerGLib *self);
CORE_API_EXPORT void core_api_async_caller_glib_set_cb(CoreApiAsyncCallerGLib *self, const CoreApiAsyncCallerCb *cb);

CORE_API_EXPORT gboolean core_api_async_caller_glib_is_canceled(CoreApiAsyncCallerGLib *self);


CORE_API_EXPORT GType core_api_async_caller_glib_get_type(void);


G_END_DECLS

#endif /* CORE_API_ASYNC_CALLER_GLIB_H_ */

/**
 * @}
 */
