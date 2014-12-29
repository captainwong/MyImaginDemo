
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The CoreApiDevManager header file.
 *
 * Definitions of CoreApiDevManager class.
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




#ifndef CORE_API_DEV_MANAGER_H_
#define CORE_API_DEV_MANAGER_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-cred.h"
#include "core/core-api-dev.h"
#include "core/core-api-srv-info.h"

#include "device/core-api-device.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDevManagerObj;



typedef struct
{
    void *          udata;

    void            (*dev_add)(     void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
    void            (*dev_del)(     void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
    void            (*dev_online)(  void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
    void            (*dev_offline)( void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
    void            (*dev_usable)(  void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
    void            (*dev_unusable)(void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
    void            (*dev_discoverer_changed)(void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);

    void            (*reserver_0)(void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
    void            (*reserver_1)(void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);

    /**
     * get dev credential
     *
     * after credential be used, core_api_cred_unref() will be called.
     * @return CORE_API_INVALID_OBJ means no credential.
     */
    CoreApiCredObj  (*dev_get_cred_ref)(void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);


    void            (*reserver_10)(void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
    void            (*reserver_11)(void *udata, CoreApiDevManagerObj manager, CoreApiDevObj dev);
}CoreApiDevManagerCb;


CORE_API_EXPORT CoreApiDevManagerObj core_api_dev_manager_new(void);
CORE_API_EXPORT CoreApiDevManagerObj core_api_dev_manager_new_for_cb(const CoreApiDevManagerCb *cb);
CORE_API_EXPORT CoreApiDevManagerObj core_api_dev_manager_ref(CoreApiDevManagerObj manager);
CORE_API_EXPORT void core_api_dev_manager_unref(CoreApiDevManagerObj manager);

CORE_API_EXPORT void core_api_dev_manager_add_cb(CoreApiDevManagerObj manager, const CoreApiDevManagerCb *cb);
CORE_API_EXPORT void core_api_dev_manager_del_cb(CoreApiDevManagerObj manager, const CoreApiDevManagerCb *cb);


CORE_API_EXPORT void core_api_dev_manager_set_nickname(CoreApiDevManagerObj manager, const char *utf8_nickname);


CORE_API_EXPORT void core_api_dev_manager_add_stun_srvs(CoreApiDevManagerObj manager, CoreApiSrvInfoObj stunsrvs[]);
CORE_API_EXPORT void core_api_dev_manager_add_turn_srvs(CoreApiDevManagerObj manager, CoreApiSrvInfoObj turnsrvs[]);




CORE_API_EXPORT void core_api_dev_manager_add_stack(CoreApiDevManagerObj manager, CoreApiObj stack);
CORE_API_EXPORT void core_api_dev_manager_del_stack(CoreApiDevManagerObj manager, CoreApiObj stack);

CORE_API_EXPORT void core_api_dev_manager_add_contactor(CoreApiDevManagerObj manager, CoreApiObj contactor);
CORE_API_EXPORT void core_api_dev_manager_del_contactor(CoreApiDevManagerObj manager, CoreApiObj contactor);

CORE_API_EXPORT void core_api_dev_manager_add_discoverer(CoreApiDevManagerObj manager, CoreApiObj discoverer);
CORE_API_EXPORT void core_api_dev_manager_del_discoverer(CoreApiDevManagerObj manager, CoreApiObj discoverer);

/**
 * refresh device list.
 * do it after you modify discoverer list(add_discoverer()/del_discoverer())
 */
CORE_API_EXPORT void core_api_dev_manager_refresh(CoreApiDevManagerObj manager);

/**
 * create device from device manager.
 *
 * call core_api_device_unref() while destroy this device.
 */
CORE_API_EXPORT CoreApiDeviceObj core_api_dev_manager_create_device(CoreApiDevManagerObj manager, CoreApiDevObj dev, const CoreApiDeviceCb *cb);


CORE_API_END_DECLS

#endif /* CORE_API_DEV_MANAGER_H_ */

/**
 * @}
 */
