
/**
 * @addtogroup D510
 * @{
 */

/**
 * @brief   The D510HbApiHelperAlarmServer header file.
 *
 * Definitions of D510HbApiHelperAlarmServer class.
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

#ifndef D510HB_API_HELPER_ALARM_SERVER_H_
#define D510HB_API_HELPER_ALARM_SERVER_H_

#include <stdint.h>

#include <kd-core-api.h>
#include <d510hb-api-enums.h>

CORE_API_BEGIN_DECLS

typedef CoreApiObj D510HbApiHelperAlarmServerObj;


CORE_API_EXPORT D510HbApiHelperAlarmServerObj d510hb_api_helper_alarm_server_ref(D510HbApiHelperAlarmServerObj as);
CORE_API_EXPORT void d510hb_api_helper_alarm_server_unref_later(D510HbApiHelperAlarmServerObj as);

/** async operation */
CORE_API_EXPORT void d510hb_api_helper_alarm_server_do_get(D510HbApiHelperAlarmServerObj as, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void d510hb_api_helper_alarm_server_do_set(D510HbApiHelperAlarmServerObj as, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);


/**
 * view/edit
 */
CORE_API_EXPORT const char * d510hb_api_helper_alarm_server_view_host(D510HbApiHelperAlarmServerObj as, D510HbApiServerName sname, D510HbApiServerType stype);
CORE_API_EXPORT void d510hb_api_helper_alarm_server_edit_host(D510HbApiHelperAlarmServerObj as, D510HbApiServerName sname, D510HbApiServerType stype, const char *host);

CORE_API_EXPORT uint16_t d510hb_api_helper_alarm_server_view_port(D510HbApiHelperAlarmServerObj as, D510HbApiServerName sname, D510HbApiServerType stype);
CORE_API_EXPORT void d510hb_api_helper_alarm_server_edit_port(D510HbApiHelperAlarmServerObj as, D510HbApiServerName sname, D510HbApiServerType stype, uint16_t port);



CORE_API_END_DECLS

#endif /* D510HB_API_HELPER_ALARM_SERVER_H_ */

/**
 * @}
 */
