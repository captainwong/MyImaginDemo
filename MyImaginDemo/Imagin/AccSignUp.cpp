#include "stdafx.h"
#include "AccSignUp.h"
#include "AccStack.h"
#include "ServerInfo.h"

namespace Imagin {

DECLARE_CALLBACK_IMAGIN(signup_on_result, AccSignUp, SignupOnResult)
DECLARE_CALLBACK_IMAGIN(get_code_on_result, AccSignUp, GetCodeOnResult)
DECLARE_CALLBACK_IMAGIN(get_fogot_code_on_result, AccSignUp, GetFogotCodeOnResult)
DECLARE_CALLBACK_IMAGIN(get_reset_code_on_result, AccSignUp, GetResetCodeOnResult)

AccSignUp::AccSignUp(const char* domain,
					unsigned short port,
					AsyncCallerCb signupResultCb,
					AsyncCallerCb getVcodeResultCb,
					AsyncCallerCb getForgotVcodeResultCb,
					AsyncCallerCb resetResultCb,
					EmailExistsResultCB emailExistsResultCb,
					void* udata)
	: _callerObj(CORE_API_INVALID_OBJ)
	, _userObj(CORE_API_INVALID_OBJ)
	, _signupResultCb(signupResultCb)
	, _getCodeResultCb(getVcodeResultCb)
	, _getForgotCodeResultCb(getForgotVcodeResultCb)
	, _emailExistsResultCb(emailExistsResultCb)
	, _getResetCodeResultCb(resetResultCb)
	, _udata(udata)
{
	_callerCb.on_result = signup_on_result;
	_callerCb.udata = this;

	_getCodeCb.on_result = get_code_on_result;
	_getCodeCb.udata = this;

	_getForgotCodeCb.on_result = get_fogot_code_on_result;
	_getForgotCodeCb.udata = this;

	_getResetCodeCb.on_result = get_reset_code_on_result;
	_getResetCodeCb.udata = this;

	_isEmailExistsCb.on_result = is_email_exists_on_result;
	_isEmailExistsCb.udata = this;

	_accStack = new AccStack(); assert(_accStack);
	_accStack->CreateStack();

	ServerInfo srvInfo;
	srvInfo.Create(domain, port);
	_userManagerObj = core_api_acc_stack_create_user_manager(*_accStack, srvInfo);
}


AccSignUp::~AccSignUp()
{
	if (core_api_obj_is_valid(_userManagerObj)) {
		core_api_acc_user_manager_unref(_userManagerObj);
		_userManagerObj = CORE_API_INVALID_OBJ;
	}

	if (_accStack != NULL) {
		delete _accStack;
		_accStack = NULL;
	}
}


// staic callback funcions
//void AccSignUp::signup_on_result(void* udata, 
//								 CoreApiObj, 
//								 CoreApiAsyncCallerObj, 
//								 CoreApiResultObj result)
//{
//	AccSignUp* accSignup = reinterpret_cast<AccSignUp*>(udata); assert(accSignup);
//	accSignup->SignupOnResult(result);
//}
//
//
//void AccSignUp::get_code_on_result(void * udata,
//								   CoreApiObj,
//								   CoreApiAsyncCallerObj,
//								   CoreApiResultObj result)
//{
//	AccSignUp* accSignup = reinterpret_cast<AccSignUp*>(udata); assert(accSignup);
//	accSignup->GetCodeOnResult(result);
//}
//
//void AccSignUp::get_fogot_code_on_result(void* udata,
//										 CoreApiObj,
//										 CoreApiAsyncCallerObj,
//										 CoreApiResultObj result)
//{
//	AccSignUp* accSignup = reinterpret_cast<AccSignUp*>(udata); assert(accSignup);
//	accSignup->GetFogotCodeOnResult(result);
//}


void AccSignUp::is_email_exists_on_result(void* udata,
										  CoreApiObj,
										  CoreApiAsyncCallerObj,
										  CoreApiResultObj result,
										  int exists)
{
	AccSignUp* accSignup = reinterpret_cast<AccSignUp*>(udata); assert(accSignup);
	accSignup->IsMailExistsOnResult(result, exists ? true : false);
}


//void AccSignUp::get_reset_code_on_result(void* udata,
//										 CoreApiObj,
//										 CoreApiAsyncCallerObj,
//										 CoreApiResultObj result)
//{
//	AccSignUp* accSignup = reinterpret_cast<AccSignUp*>(udata); assert(accSignup);
//	accSignup->GetResetCodeOnResult(result);
//}
// called by those callback functions
void AccSignUp::SignupOnResult(CoreApiResultObj result)
{
	const char* phrase = core_api_result_get_phrase(result);
	int code = core_api_result_get_code(result);

	bool success = CORE_API_RESULT_OK->code == code;
	async_caller_unref_later(_callerObj);

	if (_signupResultCb != NULL) {
		_signupResultCb(this, success, code, phrase, _udata);
	}
}


void AccSignUp::GetCodeOnResult(CoreApiResultObj result)
{
	const char* phrase = core_api_result_get_phrase(result);
	int code = core_api_result_get_code(result);

	bool success = CORE_API_RESULT_OK->code == code;
	async_caller_unref_later(_callerObj);

	if (_getCodeResultCb != NULL) {
		_getCodeResultCb(this, success, code, phrase, _udata);
	}
}


void AccSignUp::GetFogotCodeOnResult(CoreApiResultObj result)
{
	const char* phrase = core_api_result_get_phrase(result);
	int code = core_api_result_get_code(result);

	bool success = CORE_API_RESULT_OK->code == code;
	async_caller_unref_later(_callerObj);

	if (_getForgotCodeResultCb != NULL) {
		_getForgotCodeResultCb(this, success, code, phrase, _udata);
	}
}


void AccSignUp::IsMailExistsOnResult(CoreApiResultObj result, bool exists)
{
	const char* phrase = core_api_result_get_phrase(result);
	int code = core_api_result_get_code(result);

	bool success = CORE_API_RESULT_OK->code == code;
	async_caller_unref_later(_callerObj);

	if (_emailExistsResultCb != NULL) {
		_emailExistsResultCb(this, success, code, phrase, exists, _udata);
	}
}


void AccSignUp::GetResetCodeOnResult(CoreApiResultObj result)
{
	const char* phrase = core_api_result_get_phrase(result);
	int code = core_api_result_get_code(result);

	bool success = CORE_API_RESULT_OK->code == code;
	async_caller_unref_later(_callerObj);

	if (_getResetCodeResultCb != NULL) {
		_getResetCodeResultCb(this, success, code, phrase, _udata);
	}
}



NAMESPACE_END
