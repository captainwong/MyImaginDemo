#pragma once

#include "global.h"
namespace Imagin {

class AccStack;
class AccSignUp
{
	DECLARE_UNCOPYABLE(AccSignUp)
public:
	AccSignUp(const char* domain, unsigned short port);
	~AccSignUp();
protected:
	// static callback functions
	static void signup_on_result(void* udata, 
								 CoreApiObj, 
								 CoreApiAsyncCallerObj, 
								 CoreApiResultObj result);

	static void get_code_on_result(void * udata,
								   CoreApiObj,
								   CoreApiAsyncCallerObj,
								   CoreApiResultObj result);
protected:
	// called by those callback functions
	void SignupOnResult(CoreApiResultObj result);
	void GetCodeOnResult(CoreApiResultObj result);
private:
	AccSignUp() {}
	CoreApiAsyncCallerObj                   _callerObj;
	CoreApiAsyncCallerCb                    _callerCb;
	CoreApiAsyncCallerCb                    _getCodeCallerCb;
	CoreApiAsyncCallerCb                    _getForgotCodeCallerCb;
	CoreApiAsyncCallerCb                    _resetCallerCb;
	CoreApiAccUserObj                       _userObj;
	CoreApiAccUserManagerObj                _userManagerObj;

	CoreApiAccUserManagerIsEmailExistsCb	_isEmailExistsCb;

	AsyncCallerCb							_signupResultCb;
	AsyncCallerCb							_getCodeResultCb;
	AsyncCallerCb							_forgotCodeResultCb;
	AsyncCallerCb							_resetResultCb;
	EmailExistsResultCB						_emailExistsCb;

	void*									_udata;
	AccStack*								_accStack;
};

NAMESPACE_END
