
/**
 * @addtogroup KdCoreApi
 * @{
 */

/**
 * @brief   CoreApiHelperRtpCrypto header file
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
 * -# 2014-8-2 laizuobin@imagintech.com.cn create.
 *
 */

#ifndef CORE_API_HELPER_RTP_CRYPTO_H_
#define CORE_API_HELPER_RTP_CRYPTO_H_

#include "stdint.h"

#include "core/core-api-global.h"
#include "core/core-api-obj.h"
#include "core/core-api-async-caller.h"




CORE_API_BEGIN_DECLS



typedef CoreApiObj CoreApiHelperRtpCryptoObj;



/**
 *  CoreApiHelperRtpCrypto
 * {
 * }
 */
CORE_API_EXPORT CoreApiHelperRtpCryptoObj core_api_helper_rtp_crypto_ref(CoreApiHelperRtpCryptoObj crypto);
CORE_API_EXPORT void core_api_helper_rtp_crypto_unref_later(CoreApiHelperRtpCryptoObj crypto);
/**
 * async operation
 */
CORE_API_EXPORT void core_api_helper_rtp_crypto_is_crypto(CoreApiHelperRtpCryptoObj crypto, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);
CORE_API_EXPORT void core_api_helper_rtp_crypto_update_crypto(CoreApiHelperRtpCryptoObj crypto, const CoreApiAsyncCallerCb *cb, CoreApiAsyncCallerObj *caller);

/**
 * view/edit
 */
CORE_API_EXPORT int32_t core_api_helper_rtp_crypto_view_crypto(CoreApiHelperRtpCryptoObj crypto);  // return boolean
CORE_API_EXPORT void core_api_helper_rtp_crypto_edit_crypto(CoreApiHelperRtpCryptoObj crypto, const char *password);


CORE_API_END_DECLS

#endif /* CORE_API_HELPER_RTP_CRYPTO_H_ */

/**
 * @}
 */
