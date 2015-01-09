#include "AccSignUp.h"

NAMESPACE_BEGIN(Imagin)

AccSignUp::AccSignUp(const char* domain, unsigned short port)
	: _callerObj(CORE_API_INVALID_OBJ)
	, _userObj(CORE_API_INVALID_OBJ)
	, _signupResultCb(NULL)
	, _getCodeResultCb(NULL)
	, _forgotCodeResultCb(NULL)
	, _emailExistsCb(NULL)
	, _resetResultCb(NULL)
	, _udata(NULL)
{
	_callerCb.on_result = signup_on_result;
	_callerCb.udata = this;

	_getCodeCallerCb.on_result = get_code_on_result;
	_getCodeCallerCb.udata = this;


}


AccSignUp::~AccSignUp()
{}


// staic callback funcions
void AccSignUp::signup_on_result(void* udata, 
								 CoreApiObj, 
								 CoreApiAsyncCallerObj, 
								 CoreApiResultObj result)
{
	AccSignUp* accSignup = reinterpret_cast<AccSignUp*>(udata); assert(accSignup);
	accSignup->SignupOnResult(result);
}


void AccSignUp::get_code_on_result(void * udata,
							   CoreApiObj,
							   CoreApiAsyncCallerObj,
							   CoreApiResultObj result)
{
	AccSignUp* accSignup = reinterpret_cast<AccSignUp*>(udata); assert(accSignup);
	accSignup->GetCodeOnResult(result);
}


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










NAMESPACE_END
