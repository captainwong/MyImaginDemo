
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiDeviceCamera header file.
 *
 * Definitions of KdCoreApiDeviceCamera class.
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




#ifndef CORE_API_DEVICE_CAMERA_H_
#define CORE_API_DEVICE_CAMERA_H_

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


#include "helper/camera/core-api-helper-sensor.h"
#include "helper/camera/core-api-helper-rt-sensor.h"
#include "helper/camera/core-api-helper-audio-codec.h"
#include "helper/camera/core-api-helper-stream-enumerator.h"
#include "helper/camera/core-api-helper-ptz-enumerator.h"

#include "stdint.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiDeviceCameraObj;



CORE_API_EXPORT CoreApiDeviceCameraObj core_api_device_camera_ref(CoreApiDeviceCameraObj camera);
CORE_API_EXPORT void core_api_device_camera_unref(CoreApiDeviceCameraObj camera);


CORE_API_EXPORT CoreApiHelperSensorObj core_api_device_camera_create_sensor(CoreApiDeviceCameraObj camera);
CORE_API_EXPORT CoreApiHelperRtSensorObj core_api_device_camera_create_rt_sensor(CoreApiDeviceCameraObj camera);
CORE_API_EXPORT CoreApiHelperAudioCodecObj core_api_device_camera_create_audio_codec(CoreApiDeviceCameraObj camera);
CORE_API_EXPORT int32_t core_api_device_camera_get_video_size_count(CoreApiDeviceCameraObj camera);
CORE_API_EXPORT CoreApiVSize core_api_device_camera_get_video_size(CoreApiDeviceCameraObj camera, int32_t index);
CORE_API_EXPORT int32_t core_api_device_camera_get_video_codec_count(CoreApiDeviceCameraObj camera);
CORE_API_EXPORT CoreApiVCodec core_api_device_camera_get_video_codec(CoreApiDeviceCameraObj camera, int32_t index);
CORE_API_EXPORT int32_t core_api_device_camera_get_audio_codec_count(CoreApiDeviceCameraObj camera);
CORE_API_EXPORT CoreApiACodec core_api_device_camera_get_audio_codec(CoreApiDeviceCameraObj camera, int32_t index);
CORE_API_EXPORT int32_t core_api_device_camera_can_audio_dec(CoreApiDeviceCameraObj camera); //"[0,1]

/**
 * stream
 */
CORE_API_EXPORT CoreApiHelperStreamEnumeratorObj core_api_device_camera_create_stream_enumerator(CoreApiDeviceCameraObj camera);

/**
 * ptz
 */
CORE_API_EXPORT CoreApiHelperPtzEnumeratorObj core_api_device_camera_create_ptz_enumerator(CoreApiDeviceCameraObj camera);









CORE_API_END_DECLS

#endif /* CORE_API_DEVICE_CAMERA_H_ */

/**
 * @}
 */
