
/**
 * @addtogroup KdCore package
 * @{
 */

/**
 * @brief   file description
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

#ifndef CORE_API_LOGGER_ADVANCE_H_
#define CORE_API_LOGGER_ADVANCE_H_

#include "core/core-logger.h"
#include "core/core-api-global.h"
#include "core/core-api-logger.h"

CORE_API_BEGIN_DECLS

CORE_API_EXPORT CoreLoggerLevel core_api_logger_level_to_level(CoreApiLoggerLevel level);
CORE_API_EXPORT CoreApiLoggerLevel core_logger_level_to_api_level(CoreLoggerLevel level);

CORE_API_END_DECLS

#endif /* CORE_API_LOGGER_ADVANCE_H_ */

/**
 * @}
 */
