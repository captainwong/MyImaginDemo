#pragma once

#include "global.h"

namespace Imagin {

class ServerInfo
{
public:
	ServerInfo();
	~ServerInfo();
	operator CoreApiSrvInfoObj() const { return _srvInfoObj; }
	const char* GetDomain() const { return (core_api_obj_is_valid(_srvInfoObj) ? core_api_srv_info_get_domain(_srvInfoObj) : ""); }
	uint16_t GetPort() const { return (core_api_obj_is_valid(_srvInfoObj) ? core_api_srv_info_get_port(_srvInfoObj) : 0); }
	void SetSrvInfoObj(CoreApiSrvInfoObj srvInfoObj);
	bool Create(const char* domain, uint16_t port, CoreApiTransport type = CORE_API_TRANSPORT_TCP);
	bool CreateWithUserInfo(const char* username,
							const char* password,
							const char* domain,
							uint16_t port,
							CoreApiTransport type = CORE_API_TRANSPORT_TCP);
protected:
	// static functions
	typedef struct UserInfo {
		char* username;
		char* password;
		UserInfo() : username(NULL), password(NULL) {}
		~UserInfo() { if (username) delete username; if (password) delete password; }
	}UserInfo;

	static char* get_digest(void *udata,
							CoreApiCredObj cred,
							CoreApiDigestType,
							const char* username,
							const char* realm)	{ return ""; }

	static void destroy_udata(void* udata) { 
		UserInfo* userinfo = reinterpret_cast<UserInfo*>(udata); 
		if (userinfo) delete userinfo; 
	}

	static const char* get_username(void* udata, CoreApiCredObj cred) {
		UserInfo* userinfo = reinterpret_cast<UserInfo*>(udata); assert(userinfo);
		return userinfo->username;
	}

	static const char* get_password(void* udata, CoreApiCredObj cred) {
		UserInfo* userinfo = reinterpret_cast<UserInfo*>(udata); assert(userinfo);
		return userinfo->password;
	}

private:
	CoreApiSrvInfoObj	_srvInfoObj;
	CoreApiCredCb		_credCb;
	
	DECLARE_UNCOPYABLE(ServerInfo)
};

NAMESPACE_END
