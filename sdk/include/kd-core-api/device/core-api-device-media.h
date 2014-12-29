
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDeviceMedia header file.
 *
 * Definitions of KdCoreApiDeviceMedia class.
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




#ifndef CORE_API_DEVICE_MEDIA_H_
#define CORE_API_DEVICE_MEDIA_H_

#include "stdint.h"         //" uint8_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDeviceMediaObj;

typedef struct
{
    void *              udata;

    /**
     * @param [name]        codec name string, such as "H264", "PCMA", "PCMU"
     * @param [pt]          payload type within rtp packet.
     * @param [rtpmap]      details for pt, could be NULL for well known pt.
     * @param [fmtp]        codec parameter string list, NULL terminated.
     *
     * video codec parameters:
     * such as H264: fmtp="profile-level-id=42A01E; packetization-mode=1; sprop-parameter-sets=Z0IACpZTBYmI,aMljiA=="
     * paremeters were seperated by ';', you should get what you want by youself.
     *
     * @see http://blog.csdn.net/leesphone/article/details/5576247
     * @see RFC-3984 RFC-6184
     */
    void                (*on_video_codec)(void *udata, CoreApiDeviceMediaObj media, const char *name, int32_t pt, const char *rtpmap, const char **fmtp);
    void                (*on_audio_codec)(void *udata, CoreApiDeviceMediaObj media, const char *name, int32_t pt, const char *rtpmap, const char **fmtp);

    void                (*on_audio_rtp)( void *udata, CoreApiDeviceMediaObj media, const uint8_t *buf, uint32_t size);
    void                (*on_audio_rtcp)(void *udata, CoreApiDeviceMediaObj media, const uint8_t *buf, uint32_t size);
    void                (*on_video_rtp)( void *udata, CoreApiDeviceMediaObj media, const uint8_t *buf, uint32_t size);
    void                (*on_video_rtcp)(void *udata, CoreApiDeviceMediaObj media, const uint8_t *buf, uint32_t size);

    void                (*on_shutdown)(void *udata, CoreApiDeviceMediaObj media);   //" shutdown by peer
}CoreApiDeviceMediaCb;



CORE_API_EXPORT CoreApiDeviceMediaObj core_api_device_media_ref(CoreApiDeviceMediaObj media);
#if 0
CORE_API_EXPORT void core_api_device_media_unref(CoreApiDeviceMediaObj media);
#endif
CORE_API_EXPORT void core_api_device_media_unref_later(CoreApiDeviceMediaObj media);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_device_media_open(CoreApiDeviceMediaObj media, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_device_media_close(CoreApiDeviceMediaObj media, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);



/**
 * set single thread callback mode,
 * or multi-thread callback mode.
 *
 * !!!ONLY effect on rtp/rtcp callback.!!!!
 *
 * default is single thread callback mode.
 *
 * @param thread    [in]    boolean
 */
CORE_API_EXPORT int core_api_device_media_is_thread_data_mode(CoreApiDeviceMediaObj media);
CORE_API_EXPORT void core_api_device_media_set_thread_data_mode(CoreApiDeviceMediaObj media, int thread);




/**
 * enable/disable send Audio
 *
 * default is disable.
 *
 * @param [in]      send boolean.
 * @remark you can do it at any time.
 */
CORE_API_EXPORT int core_api_device_media_is_audio_send(CoreApiDeviceMediaObj media);
CORE_API_EXPORT void core_api_device_media_set_audio_send(CoreApiDeviceMediaObj media, int send);
CORE_API_EXPORT int core_api_device_media_is_video_send(CoreApiDeviceMediaObj media);
CORE_API_EXPORT void core_api_device_media_set_video_send(CoreApiDeviceMediaObj media, int send);

/**
 * enable/disable recv Audio
 *
 * default is disable.
 *
 * @param [in]      recv boolean.
 * @remark you can do it at any time.
 */
CORE_API_EXPORT int core_api_device_media_is_audio_recv(CoreApiDeviceMediaObj media);
CORE_API_EXPORT void core_api_device_media_set_audio_recv(CoreApiDeviceMediaObj media, int recv);
CORE_API_EXPORT int core_api_device_media_is_video_recv(CoreApiDeviceMediaObj media);
CORE_API_EXPORT void core_api_device_media_set_video_recv(CoreApiDeviceMediaObj media, int recv);


/**
 * enable/disable RTCP
 *
 * default is enabled.
 *
 * @param [in]      rtcp boolean.
 * @pre call it before open
 */
CORE_API_EXPORT int core_api_device_media_is_rtcp(CoreApiDeviceMediaObj media);
CORE_API_EXPORT void core_api_device_media_set_rtcp(CoreApiDeviceMediaObj media, int rtcp);



/**
 * send rtp/rtcp
 */
CORE_API_EXPORT void core_api_device_media_send_audio_rtp( CoreApiDeviceMediaObj media, const uint8_t *buf, uint32_t size);
CORE_API_EXPORT void core_api_device_media_send_audio_rtcp(CoreApiDeviceMediaObj media, const uint8_t *buf, uint32_t size);
CORE_API_EXPORT void core_api_device_media_send_video_rtp( CoreApiDeviceMediaObj media, const uint8_t *buf, uint32_t size);
CORE_API_EXPORT void core_api_device_media_send_video_rtcp(CoreApiDeviceMediaObj media, const uint8_t *buf, uint32_t size);









CORE_API_EXPORT int core_api_device_media_get_video_rtp_fd(CoreApiDeviceMediaObj media);
CORE_API_EXPORT int core_api_device_media_get_video_rtcp_fd(CoreApiDeviceMediaObj media);




CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_MEDIA_H_ */

/**
 * @}
 */
