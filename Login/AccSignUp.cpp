#include "AccSignUp.h"

NAMESPACE_BEGIN(Imagin)

AccSignUp::AccSignUp(const char* domain, unsigned short port)
	: _callerObj(CORE_API_INVALID_OBJ)
	, _userObj(CORE_API_INVALID_OBJ)
	, _signupResultCb(CORE_API_INVALID_OBJ)
	, _sendCodeResultCb(CORE_API_INVALID_OBJ)
	, _forgotCodeResultCb(CORE_API_INVALID_OBJ)
	, _emailExistsCb(NULL)
	, _resetResultCb(NULL)
	, _udata(NULL)
{

}


AccSignUp::~AccSignUp()
{}
















NAMESPACE_END
