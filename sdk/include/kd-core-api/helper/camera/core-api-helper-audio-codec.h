
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApiHelperAudioCodec header file.
 *
 * Definitions of KdCoreApiHelperAudioCodec class.
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

#ifndef CORE_API_HELPER_AUDIO_CODEC_H_
#define CORE_API_HELPER_AUDIO_CODEC_H_

#include "stdint.h"                 //" uint32_t

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"
#include "core/core-api-av-codec.h"

CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiHelperAudioCodecObj;

CORE_API_EXPORT CoreApiHelperAudioCodecObj core_api_helper_audio_codec_ref(CoreApiHelperAudioCodecObj acodec);
CORE_API_EXPORT void core_api_helper_audio_codec_unref(CoreApiHelperAudioCodecObj acodec);

CORE_API_EXPORT void core_api_helper_audio_codec_set(CoreApiHelperAudioCodecObj acodec, CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_audio_codec_get(CoreApiHelperAudioCodecObj acodec, CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);


CORE_API_EXPORT CoreApiACodec core_api_helper_audio_codec_view_codec(CoreApiHelperAudioCodecObj acodec);
CORE_API_EXPORT void core_api_helper_audio_codec_edit_codec(CoreApiHelperAudioCodecObj acodec, CoreApiACodec codec);
CORE_API_EXPORT double core_api_helper_audio_codec_view_samplerate(CoreApiHelperAudioCodecObj acodec);
CORE_API_EXPORT void core_api_helper_audio_codec_edit_samplerate(CoreApiHelperAudioCodecObj acodec, double samplerate);

CORE_API_END_DECLS


#endif /* CORE_API_HELPER_AUDIO_CODEC_H_ */
