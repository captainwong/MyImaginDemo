/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The coreapiacclogin header file.
 *
 * Definitions of CoreApiAccLogin class.
 *
 * Copyright (c) 2013 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2013-09-23 wanghongquan@imagintech.com.cn modify.
 *
 */
#ifndef DEC_H264_H
#define DEC_H264_H
#ifdef __cplusplus
extern "C" {
#endif
void *H264Decode_Creat();
int   H264Decode_Decode(void *handle,unsigned char*inbuf, unsigned char*outbuf, int inlen, int *outlen,int *width, int *height);
void  H264Decode_Destroy( void *handle );

#ifdef __cplusplus
}
#endif

#endif /* FFMPEG_AVCODEC_H */

/**
 * @}
 */