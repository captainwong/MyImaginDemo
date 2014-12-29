
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiHelperLocale header file.
 *
 * Definitions of CoreApiHelperLocale class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-02-08 zhuangzhida@imagintech.com.cn create.
 *
 */


#ifndef CORE_API_HELPER_LOCALE_H_
#define CORE_API_HELPER_LOCALE_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-language.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperLocaleObj;



/**
 *  CoreApiHelperLocale
 * {
 *      CoreApiLanguage language;
 *      int timezone;
 * }
 */
CORE_API_EXPORT CoreApiHelperLocaleObj core_api_helper_locale_ref(CoreApiHelperLocaleObj locale);
CORE_API_EXPORT void core_api_helper_locale_unref_later(CoreApiHelperLocaleObj locale);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_locale_get(CoreApiHelperLocaleObj locale, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_locale_set(CoreApiHelperLocaleObj locale, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view/edit
 */
CORE_API_EXPORT CoreApiLanguage core_api_helper_locale_view_language(CoreApiHelperLocaleObj locale);
CORE_API_EXPORT void core_api_helper_locale_edit_language(CoreApiHelperLocaleObj locale, CoreApiLanguage language);

CORE_API_EXPORT int32_t core_api_helper_locale_view_timezone(CoreApiHelperLocaleObj locale);
CORE_API_EXPORT void core_api_helper_locale_edit_timezone(CoreApiHelperLocaleObj locale, int32_t timezone);


CORE_API_END_DECLS

#endif /* CORE_API_HELPER_LOCALE_H_ */

/**
 * @}
 */
