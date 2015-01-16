#include "stdafx.h"
#include "ServerInfo.h"

namespace Imagin
{

ServerInfo::ServerInfo()
	: _srvInfoObj(CORE_API_INVALID_OBJ)

{
	_credCb.destroy_udata = destroy_udata;
	_credCb.get_digest = get_digest;
	_credCb.get_password = get_password;
	_credCb.get_username = get_username;
}


ServerInfo::~ServerInfo()
{
	if (core_api_obj_is_valid(_srvInfoObj)) {
		core_api_srv_info_unref(_srvInfoObj);
		_srvInfoObj = CORE_API_INVALID_OBJ;
	}
}


void ServerInfo::SetSrvInfoObj(CoreApiSrvInfoObj srvInfoObj)
{
	if (core_api_obj_is_valid(_srvInfoObj)) {
		core_api_srv_info_unref(_srvInfoObj);
		_srvInfoObj = CORE_API_INVALID_OBJ;
	}

	assert(core_api_obj_is_valid(srvInfoObj));

	_srvInfoObj = core_api_srv_info_ref(srvInfoObj);
}


bool ServerInfo::Create(const char* domain, uint16_t port, CoreApiTransport type)
{
	if (core_api_obj_is_valid(_srvInfoObj)) {
		core_api_srv_info_unref(_srvInfoObj);
		_srvInfoObj = CORE_API_INVALID_OBJ;
	}

	_srvInfoObj = core_api_srv_info_new_full(type, domain, port);
	if (!core_api_obj_is_valid(_srvInfoObj)) {
		return false;
	}

	return true;
}


bool ServerInfo::CreateWithUserInfo(const char* username,
									const char* password,
									const char* domain,
									uint16_t port,
									CoreApiTransport type)
{
	if (!Create(domain, port, type)) {
		return false;
	}

	assert(core_api_obj_is_valid(_srvInfoObj));
	core_api_srv_info_set_username(_srvInfoObj, username);

	UserInfo* uInfo = new UserInfo;
	uInfo->username = _strdup(username);
	uInfo->password = _strdup(password);
	_credCb.udata = (void*)uInfo;

	CoreApiCredObj  sipCredObj = core_api_cred_new(&_credCb);
	if (!core_api_obj_is_valid(sipCredObj)) {
		return false;
	}

	core_api_srv_info_set_cred(_srvInfoObj, sipCredObj);
	core_api_cred_unref(sipCredObj);

	return true;
}













};
