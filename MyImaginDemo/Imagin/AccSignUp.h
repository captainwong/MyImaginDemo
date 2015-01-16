#pragma once

#include "global.h"

namespace Imagin
{

class AccStack;

class AccSignUp
{
	
public:
	AccSignUp(const char* domain, 
			  unsigned short port, 
			  AsyncCallerCb signupResultCb,
			  AsyncCallerCb getVcodeResultCb,
			  AsyncCallerCb getForgotVcodeResultCb,
			  AsyncCallerCb getResetVcodeResultCb,
			  EmailExistsResultCB emailExistsResultCb,
			  void* udata);

	~AccSignUp();

	void GetVcode(const char* email) { 
		CancelLastOperation();  
		core_api_acc_user_manager_send_vcode_for_register(_userManagerObj, 
														  email, 
														  &_getCodeCb,
														  &_callerObj);
	}

	void CheckIfEmailExists(const char* email) {
		CancelLastOperation();
		core_api_acc_user_manager_is_email_exists(_userManagerObj,
												  email,
												  &_isEmailExistsCb,
												  &_callerObj);
	}


protected:
	void CancelLastOperation() { async_caller_cancel_and_unref_later(_callerObj); }

	
protected:
	// static callback functions
	/*static void signup_on_result(void* udata,
								 CoreApiObj,
								 CoreApiAsyncCallerObj,
								 CoreApiResultObj result);

	static void get_code_on_result(void* udata,
								   CoreApiObj,
								   CoreApiAsyncCallerObj,
								   CoreApiResultObj result);

	static void get_fogot_code_on_result(void* udata,
										 CoreApiObj,
										 CoreApiAsyncCallerObj,
										 CoreApiResultObj result);
*/
	static void is_email_exists_on_result(void* udata,
										  CoreApiObj,
										  CoreApiAsyncCallerObj,
										  CoreApiResultObj result,
										  int exists); 
	
	/*static void get_reset_code_on_result(void* udata,
										 CoreApiObj,
										 CoreApiAsyncCallerObj,
										 CoreApiResultObj result);*/
public:
	// called by those callback functions
	void SignupOnResult(CoreApiResultObj result);
	void GetCodeOnResult(CoreApiResultObj result);
	void GetFogotCodeOnResult(CoreApiResultObj result);
	void IsMailExistsOnResult(CoreApiResultObj result, bool exists); 
	void GetResetCodeOnResult(CoreApiResultObj result);
private:
	AccSignUp() {}
	DECLARE_UNCOPYABLE(AccSignUp)

	CoreApiAsyncCallerObj                   _callerObj;
	CoreApiAsyncCallerCb                    _callerCb;

	CoreApiAsyncCallerCb                    _getCodeCb;
	CoreApiAsyncCallerCb                    _getForgotCodeCb;
	CoreApiAsyncCallerCb                    _getResetCodeCb;

	CoreApiAccUserObj                       _userObj;
	CoreApiAccUserManagerObj                _userManagerObj;
	CoreApiAccUserManagerIsEmailExistsCb	_isEmailExistsCb;

	AsyncCallerCb							_signupResultCb;
	AsyncCallerCb							_getCodeResultCb;
	AsyncCallerCb							_getForgotCodeResultCb;
	AsyncCallerCb							_getResetCodeResultCb;
	EmailExistsResultCB						_emailExistsResultCb;

	void*									_udata;
	AccStack*								_accStack;
};

NAMESPACE_END
