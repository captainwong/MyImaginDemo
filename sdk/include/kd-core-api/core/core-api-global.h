
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   The KdCoreApi global header file.
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




#ifndef CORE_API_GLOBAL_H_
#define CORE_API_GLOBAL_H_



/* Guard C code in headers, while including them from C++ */
#ifdef  __cplusplus
#   define CORE_API_BEGIN_DECLS  extern "C" {
#   define CORE_API_END_DECLS    }
#else
#   define CORE_API_BEGIN_DECLS
#   define CORE_API_END_DECLS
#endif

/* Export API as .dll/.so */
#if defined(_MSC_VER)
#   if defined(KdCoreApi_EXPORTS)
#       define CORE_API_EXPORT  __declspec(dllexport)
#       define CORE_API_VAR     __declspec(dllexport) extern
#   else
#       define CORE_API_EXPORT  __declspec(dllimport)
#       define CORE_API_VAR     __declspec(dllimport) extern
#   endif


#   define CORE_API_GNUC_PRINTF( format_idx, arg_idx )
#else
#   define CORE_API_EXPORT
#   define CORE_API_VAR         extern


#   define CORE_API_GNUC_PRINTF( format_idx, arg_idx )    \
        __attribute__((__format__ (__printf__, format_idx, arg_idx)))
#endif




#if    __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1)
#define CORE_API_DEPRECATED __attribute__((__deprecated__))
#elif defined(_MSC_VER) && (_MSC_VER >= 1300)
#define CORE_API_DEPRECATED __declspec(deprecated)
#else
#define CORE_API_DEPRECATED
#endif


/** logger category */
#define CORE_API_LOGGER_CATEGORY_PREFIX         "coreapi"
#define CORE_API_LOGGER_CATEGORY_ACC            CORE_API_LOGGER_CATEGORY_PREFIX ".acc"
#define CORE_API_LOGGER_CATEGORY_CORE           CORE_API_LOGGER_CATEGORY_PREFIX ".core"
#define CORE_API_LOGGER_CATEGORY_DEVICE         CORE_API_LOGGER_CATEGORY_PREFIX ".device"
#define CORE_API_LOGGER_CATEGORY_HELPER         CORE_API_LOGGER_CATEGORY_PREFIX ".helper"
#define CORE_API_LOGGER_CATEGORY_HTTP           CORE_API_LOGGER_CATEGORY_PREFIX ".http"
#define CORE_API_LOGGER_CATEGORY_MAN            CORE_API_LOGGER_CATEGORY_PREFIX ".manual"
#define CORE_API_LOGGER_CATEGORY_RPC            CORE_API_LOGGER_CATEGORY_PREFIX ".rpc"
#define CORE_API_LOGGER_CATEGORY_SIP            CORE_API_LOGGER_CATEGORY_PREFIX ".sip"
#define CORE_API_LOGGER_CATEGORY_UPNP           CORE_API_LOGGER_CATEGORY_PREFIX ".upnp"
#define CORE_API_LOGGER_CATEGORY_UTILS          CORE_API_LOGGER_CATEGORY_PREFIX ".utils"
#define CORE_API_LOGGER_CATEGORY_WS             CORE_API_LOGGER_CATEGORY_PREFIX ".ws"


#endif /* CORE_API_GLOBAL_H_ */

/**
 * @}
 */
