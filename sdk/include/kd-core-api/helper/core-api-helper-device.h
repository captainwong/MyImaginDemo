
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperDevice header file.
 *
 * Definitions of KdCoreApiHelperDevice class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-6-19 laizuobin@imagintech.com.cn create.
 *
 */




#ifndef CORE_API_HELPER_DEVICE_H_
#define CORE_API_HELPER_DEVICE_H_

#include "device/core-api-device.h"

#include "helper/camera/core-api-helper-camera-enumerator.h"
#include "helper/network/core-api-helper-network-enumerator.h"
//#include "helper/sip/core-api-helper-subs-alarm-event.h"
#include "helper/sys/core-api-helper-activate.h"
#include "helper/sys/core-api-helper-datetime.h"
#include "helper/sys/core-api-helper-reboot.h"
#include "helper/sys/core-api-helper-devinfo.h"
#include "helper/sys/core-api-helper-locale.h"
#include "helper/camera/core-api-helper-power-freq.h"

#include "helper/alarm/core-api-helper-event-count.h"
#include "helper/alarm/core-api-helper-list-all-event-ids.h"
#include "helper/alarm/core-api-helper-oper-all-event.h"
#include "helper/alarm/core-api-helper-oper-event-by-id.h"
#include "helper/alarm/core-api-helper-oper-event-by-ids.h"





CORE_API_BEGIN_DECLS


//CORE_API_EXPORT CoreApiHelperSubsAlarmEventObj core_api_device_create_subs_alarm_event(CoreApiDeviceObj device);


CORE_API_EXPORT CoreApiHelperCameraEnumeratorObj core_api_device_create_camera_enumerator(CoreApiDeviceObj device);


CORE_API_EXPORT CoreApiHelperNetworkEnumeratorObj core_api_device_create_network_enumerator(CoreApiDeviceObj device);




CORE_API_EXPORT CoreApiHelperActivateObj core_api_device_create_activate(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperDateTimeObj core_api_device_create_datetime(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperRebootObj core_api_device_create_reboot(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperDevInfoObj core_api_device_create_devinfo(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperLocaleObj core_api_device_create_locale(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperPowerFreqObj core_api_device_create_power_freq(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperEventCountObj core_api_device_create_event_count(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperListAllEventIdsObj core_api_device_create_list_all_event_ids(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperOperAllEventObj core_api_device_create_oper_all_event(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperOperEventByIdObj core_api_device_create_oper_event_by_id(CoreApiDeviceObj device);

CORE_API_EXPORT CoreApiHelperOperEventByIdsObj core_api_device_create_oper_event_by_ids(CoreApiDeviceObj device);

CORE_API_END_DECLS

#endif /* CORE_API_HELPER_DEVICE_H_ */

/**
 * @}
 */
