/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiAVCodec header file.
 *
 * Definitions of KdCoreApiAVCodec class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-01-04 zhuangzhida@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_AV_CODEC_H_
#define CORE_API_AV_CODEC_H_


#include "core/core-api-global.h"
#include "core/core-api-obj.h"

#include "stdint.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiH264InfoObj;
typedef CoreApiObj CoreApiMjpegInfoObj;

typedef enum
{
    CORE_API_VCODEC_H264,
    CORE_API_VCODEC_MJPEG
}CoreApiVCodec;

typedef enum
{
    CORE_API_ACODEC_PCMA,
    CORE_API_ACODEC_PCMU,
    CORE_API_ACODEC_AAC
}CoreApiACodec;

typedef enum
{
    CORE_API_VSIZE_CIF,
    CORE_API_VSIZE_HD1,
    CORE_API_VSIZE_D1,
    CORE_API_VSIZE_QVGA,
    CORE_API_VSIZE_VGA,
    CORE_API_VSIZE_480P = CORE_API_VSIZE_VGA,
    CORE_API_VSIZE_720P,
    CORE_API_VSIZE_1080P,
    CORE_API_VSIZE_4K
}CoreApiVSize;

typedef enum
{
    CORE_API_VRCTRL_CBR,
    CORE_API_VRCTRL_VBR
}CoreApiVRCtrl;

typedef enum
{
    CORE_API_STREAM_TYPE_MAIN  = 0,
    CORE_API_STREAM_TYPE_MOBILE= 1,
    CORE_API_STREAM_TYPE_IMAGE = 2,
}CoreApiStreamType;

CORE_API_EXPORT CoreApiH264InfoObj core_api_h264_info_new(void);
CORE_API_EXPORT CoreApiH264InfoObj core_api_h264_info_ref(CoreApiH264InfoObj obj);
CORE_API_EXPORT void core_api_h264_info_unref(CoreApiH264InfoObj obj);
CORE_API_EXPORT int32_t core_api_h264_info_get_fps(CoreApiH264InfoObj obj);
CORE_API_EXPORT int32_t core_api_h264_info_get_bps(CoreApiH264InfoObj obj);
CORE_API_EXPORT double core_api_h264_info_get_ift(CoreApiH264InfoObj obj);
CORE_API_EXPORT CoreApiVRCtrl core_api_h264_info_get_vr_ctrl(CoreApiH264InfoObj obj);

CORE_API_EXPORT void core_api_h264_info_set_fps(CoreApiH264InfoObj obj, int32_t fps);
CORE_API_EXPORT void core_api_h264_info_set_bps(CoreApiH264InfoObj obj, int32_t bps);
CORE_API_EXPORT void core_api_h264_info_set_ift(CoreApiH264InfoObj obj, double ifs);
CORE_API_EXPORT void core_api_h264_info_set_vr_ctrl(CoreApiH264InfoObj obj, CoreApiVRCtrl vrctrl);

CORE_API_EXPORT CoreApiMjpegInfoObj core_api_mjpeg_info_new(void);
CORE_API_EXPORT CoreApiMjpegInfoObj core_api_mjpeg_info_ref(CoreApiMjpegInfoObj obj);
CORE_API_EXPORT void core_api_mjpeg_info_unref(CoreApiMjpegInfoObj obj);
CORE_API_EXPORT int32_t core_api_mjpeg_info_get_fps(CoreApiMjpegInfoObj obj);
CORE_API_EXPORT void core_api_mjpeg_info_set_fps(CoreApiMjpegInfoObj obj, int32_t fps);



CORE_API_END_DECLS


#endif /* CORE_API_AV_CODEC_H_ */
