
/**
 * @addtogroup KdCoreApi package
 * @{
 */

/**
 * @brief   CoreApiLogger file description
 *
 * file details
 *
 * Copyright (c) 2014 Shenzhen Imagin Technology CO., LTD.
 * ALL rights reserved.
 *
 * $Revision$
 * $Date$
 * $Id$
 *
 * Modify Logs:
 * -# 2014-8-26 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_LOGGER_H_
#define CORE_API_LOGGER_H_

#include "time.h"
#if defined(_MSC_VER)
#include "WinSock2.h"  //" struct timeval
#else
#include "sys/time.h"
#endif

#include "stdarg.h"

#include "core/core-api-global.h"
#include "core/core-api-obj.h"


CORE_API_BEGIN_DECLS

typedef CoreApiObj CoreApiLoggerObj;

typedef enum _CoreApiLoggerLevel
{
    CORE_API_LOGGER_TRACE   = 800,
    CORE_API_LOGGER_DEBUG   = 700,
    CORE_API_LOGGER_INFO    = 600,
    CORE_API_LOGGER_NOTICE  = 500,
    CORE_API_LOGGER_WARN    = 400,
    CORE_API_LOGGER_ERROR   = 300,
    CORE_API_LOGGER_FATAL   = 000
}CoreApiLoggerLevel;

typedef struct _CoreApiLoggerLocation
{
    const char *            file;           //" __FILE__
    int                     line;           //" __LINE__
    const char *            func;           //" __FUNCTION__
}CoreApiLoggerLocation;
#define CORE_API_LOGGER_LOCATION_INITIALIZE()   \
{ \
    __FILE__,\
    __LINE__,\
    __FUNCTION__\
}









typedef struct _CoreApiLoggerLog
{
    const char *            category;       //" "namespace.class"
    CoreApiLoggerLevel      level;
    const char *            message;        //" "your log string"
    struct timeval          tv;
    CoreApiLoggerLocation   loc;            //" debug info
}CoreApiLoggerLog;
typedef void (*CoreApiLoggerCallback)(const CoreApiLoggerLog *log, void *udata);






CORE_API_EXPORT CoreApiLoggerObj core_api_logger_new(const char *namespace_str, const char *class_name);
CORE_API_EXPORT CoreApiLoggerObj core_api_logger_ref(CoreApiLoggerObj logger);
CORE_API_EXPORT void core_api_logger_unref(CoreApiLoggerObj logger);

#if defined(_MSC_VER)
#define core_api_logger_trace( self, fmt, ...)       _core_api_logger_log((self), CORE_API_LOGGER_TRACE, (fmt), __VA_ARGS__)
#define core_api_logger_debug( self, fmt, ...)       _core_api_logger_log((self), CORE_API_LOGGER_DEBUG, (fmt), __VA_ARGS__)
#define core_api_logger_info(  self, fmt, ...)       _core_api_logger_log((self), CORE_API_LOGGER_INFO,  (fmt), __VA_ARGS__)
#define core_api_logger_notice(self, fmt, ...)       _core_api_logger_log((self), CORE_API_LOGGER_NOTICE,(fmt), __VA_ARGS__)
#define core_api_logger_warn(  self, fmt, ...)       _core_api_logger_log((self), CORE_API_LOGGER_WARN,  (fmt), __VA_ARGS__)
#define core_api_logger_error( self, fmt, ...)       _core_api_logger_log((self), CORE_API_LOGGER_ERROR, (fmt), __VA_ARGS__)
#define core_api_logger_fatal( self, fmt, ...)       _core_api_logger_log((self), CORE_API_LOGGER_FATAL, (fmt), __VA_ARGS__)
#else
#define core_api_logger_trace( self, fmt, arg...)       _core_api_logger_log((self), CORE_API_LOGGER_TRACE, (fmt), ##arg)
#define core_api_logger_debug( self, fmt, arg...)       _core_api_logger_log((self), CORE_API_LOGGER_DEBUG, (fmt), ##arg)
#define core_api_logger_info(  self, fmt, arg...)       _core_api_logger_log((self), CORE_API_LOGGER_INFO,  (fmt), ##arg)
#define core_api_logger_notice(self, fmt, arg...)       _core_api_logger_log((self), CORE_API_LOGGER_NOTICE,(fmt), ##arg)
#define core_api_logger_warn(  self, fmt, arg...)       _core_api_logger_log((self), CORE_API_LOGGER_WARN,  (fmt), ##arg)
#define core_api_logger_error( self, fmt, arg...)       _core_api_logger_log((self), CORE_API_LOGGER_ERROR, (fmt), ##arg)
#define core_api_logger_fatal( self, fmt, arg...)       _core_api_logger_log((self), CORE_API_LOGGER_FATAL, (fmt), ##arg)
#endif



CORE_API_EXPORT int core_api_logger_is_level_enabled(CoreApiLoggerObj logger, CoreApiLoggerLevel level);

CORE_API_EXPORT const char * core_api_logger_get_category(CoreApiLoggerObj logger);











#if defined(_MSC_VER)
#define _core_api_logger_log(logger, level, fmt, ...) \
do \
{\
    if (core_api_logger_is_level_enabled((logger), (level))) {\
        CoreApiLoggerLocation ____location = CORE_API_LOGGER_LOCATION_INITIALIZE();\
        __core_api_logger_log((logger), (level), &____location, (fmt), __VA_ARGS__);\
    }\
} \
while(0)
#else
#define _core_api_logger_log(logger, level, fmt, arg...) \
do \
{\
    if (core_api_logger_is_level_enabled((logger), (level))) {\
        CoreApiLoggerLocation ____location = CORE_API_LOGGER_LOCATION_INITIALIZE();\
        __core_api_logger_log((logger), (level), &____location, (fmt), ##arg);\
    }\
} \
while(0)
#endif
CORE_API_EXPORT void __core_api_logger_log(CoreApiLoggerObj logger, CoreApiLoggerLevel level, const CoreApiLoggerLocation *location, const char *fmt, ...) CORE_API_GNUC_PRINTF(4, 5);
CORE_API_EXPORT void __core_api_logger_logv(CoreApiLoggerObj logger, CoreApiLoggerLevel level, const CoreApiLoggerLocation *location, const char *fmt, va_list args);


CORE_API_END_DECLS

#endif /* CORE_API_LOGGER_H_ */

/**
 * @}
 */
