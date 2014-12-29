/**
 * @defgroup    KdCoreApi The KdCoreApi
 * @author      laizuobin@imagintech.com.cn
 * @version     1.0.0
 *
 * Details of KdCoreApi.
 */

/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApi header file.
 *
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-18 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef KD_CORE_API_H_
#define KD_CORE_API_H_

/** acc headers */
#include "acc/core-api-acc-contactor.h"
#include "acc/core-api-acc-dev.h"
#include "acc/core-api-acc-dev-db.h"
#include "acc/core-api-acc-discoverer.h"
#include "acc/core-api-acc-stack.h"
#include "acc/core-api-acc-user.h"
#include "acc/core-api-acc-user-db.h"
#include "acc/core-api-acc-user-manager.h"

/** core headers */
#include "core/core-api-async-caller.h"
#include "core/core-api-cred.h"
#include "core/core-api-dev.h"
#include "core/core-api-dev-info.h"
#include "core/core-api-dev-manager.h"
#include "core/core-api-dev-wifi-task.h"
#include "core/core-api-global.h"
#include "core/core-api-logger.h"
#include "core/core-api-network.h"
#include "core/core-api-obj.h"
#include "core/core-api-result.h"
#include "core/core-api-srv-info.h"
#include "core/core-api-transport.h"
#include "core/core-api-wifi-ap.h"
#include "core/core-api-wifi-cred.h"
#include "core/core-api-av-codec.h"
#include "core/core-api-language.h"
#include "core/core-api-alarm-info.h"

/** device headers */
#include "device/core-api-device.h"
#include "device/core-api-device-alarm-event.h"
#include "device/core-api-device-alarm-event-args.h"
#include "device/core-api-device-camera.h"
#include "device/core-api-device-media.h"
#include "device/core-api-device-network.h"
#include "device/core-api-device-ptz.h"
#include "device/core-api-device-wifi.h"

/** dms headers */
#include "dms/core-api-dms-contactor.h"
#include "dms/core-api-dms-discoverer.h"
#include "dms/core-api-dms-stack.h"

/** event headers */
#include "event/core-api-event-enums.h"
#include "event/core-api-event-kd-gpio-args.h"

/** helper headers */
#include "helper/core-api-helper-device.h"

#include "helper/alarm/core-api-helper-event-count.h"
#include "helper/alarm/core-api-helper-list-all-event-ids.h"
#include "helper/alarm/core-api-helper-oper-all-event.h"
#include "helper/alarm/core-api-helper-oper-event-by-id.h"
#include "helper/alarm/core-api-helper-oper-event-by-ids.h"

#include "helper/camera/core-api-helper-camera-enumerator.h"
#include "helper/camera/core-api-helper-ptz-enumerator.h"
#include "helper/camera/core-api-helper-sensor.h"
#include "helper/camera/core-api-helper-stream.h"
#include "helper/camera/core-api-helper-stream-enumerator.h"
#include "helper/camera/core-api-helper-rt-sensor.h"
#include "helper/camera/core-api-helper-sensor.h"
#include "helper/camera/core-api-helper-power-freq.h"

#include "helper/network/core-api-helper-network.h"
#include "helper/network/core-api-helper-network-ipv4.h"
#include "helper/network/core-api-helper-network-enumerator.h"
#include "helper/network/core-api-helper-wifi-ap-enumerator.h"
#include "helper/network/core-api-helper-wifi-alt-ap-enumerator.h"
#include "helper/network/core-api-helper-wifi-scan.h"
#include "helper/network/core-api-helper-wifi-wps.h"
#include "helper/network/core-api-helper-wifi-current-ap.h"
#include "helper/network/core-api-helper-wifi-add-alt-ap.h"
#include "helper/network/core-api-helper-wifi-del-alt-ap.h"

#include "helper/rtp/core-api-helper-rtp-crypto.h"

#include "helper/sip/core-api-helper-subs-alarm-event.h"

#include "helper/sys/core-api-helper-activate.h"
#include "helper/sys/core-api-helper-datetime.h"
#include "helper/sys/core-api-helper-reboot.h"
#include "helper/sys/core-api-helper-devinfo.h"
#include "helper/sys/core-api-helper-locale.h"

/** ihms headers */
#include "ihms/core-api-ihms-tiny-server.h"

/** sip headers */
#include "sip/core-api-sip-contactor.h"
#include "sip/core-api-sip-discoverer.h"
#include "sip/core-api-sip-stack.h"


/** upnp headers */
#include "upnp/core-api-upnp-contactor.h"
#include "upnp/core-api-upnp-discoverer.h"
#include "upnp/core-api-upnp-stack.h"

CORE_API_BEGIN_DECLS

typedef struct _CoreApiSDKLog
{
    CoreApiLoggerLevel          level;
    CoreApiLoggerCallback       cb;
    void *                      udata;
}CoreApiSDKLog;


/**
 * initialize KdCoreApi
 *
 * @param [in,out]      argc        program argument count.
 * @param [in,out]      argv        program argument array.
 *
 * @return      0 success, others failure.
 */
CORE_API_EXPORT int core_api_init(int *argc, char ***argv);
CORE_API_EXPORT int core_api_init_with_log(const CoreApiSDKLog *log, int *argc, char ***argv);

/**
 * cleanup KdCoreApi
 *
 * cleanup before program exit.
 */
CORE_API_EXPORT void core_api_cleanup(void);







/**
 * you can add as much category as possible.
 *
 * @param [in]          category    string such as "namespace" or "namespace.class"
 * @param [in]          level       log level
 *
 * @see core_api_init_with_log()
 */
CORE_API_EXPORT void core_api_log_add_category(const char *category, CoreApiLoggerLevel level);






/**
 * run event loop until quit_event_loop().
 */
CORE_API_EXPORT void core_api_run_event_loop(void);
/**
 * stop event loop.
 */
CORE_API_EXPORT void core_api_quit_event_loop(void);



/**
 * just process the pending event and then return
 */
CORE_API_EXPORT void core_api_process_event_loop(void);


CORE_API_END_DECLS

#endif /* KD_CORE_API_H_ */

/**
 * @}
 */
