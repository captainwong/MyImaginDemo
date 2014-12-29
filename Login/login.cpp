// Register.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

#include "ImaginUtil.h"

#define system(a) 

enum DeviceState
{
	DEVICE_STATE_ADD,
	DEVICE_STATE_ONLINE,
	DEVICE_STATE_OFFLINE,
	DEVICE_STATE_USEABLE,
	DEVICE_STATE_UNUSABLE,
};

//CoreApiAccStackObj		accStack		= CORE_API_INVALID_OBJ;
//CoreApiAccContactorObj	g_accContactor	= CORE_API_INVALID_OBJ;
//CoreApiSrvInfoObj		g_srvInfo		= CORE_API_INVALID_OBJ;
//CoreApiDevManagerObj	g_devMngr		= CORE_API_INVALID_OBJ;
//CoreApiDmsStackObj		g_dmsStack		= CORE_API_INVALID_OBJ;
//CoreApiDmsContactorObj	g_dmsContactor	= CORE_API_INVALID_OBJ;
//CoreApiDmsDiscovererObj g_dmsDiscoverer = CORE_API_INVALID_OBJ;

std::list<CoreApiSrvInfoObj> g_stunSrvInfoObjList;
std::list<CoreApiSrvInfoObj> g_turnSrvInfoObjList;
std::list<CoreApiSrvInfoObj> g_sipSrvInfoObjList;
std::list<CoreApiSrvInfoObj>::iterator g_iter;

std::list<CoreApiDevObj> g_devObjList;
std::list<CoreApiDevObj>::iterator g_devIter;

template <typename T>
bool myfind(std::list<T>& list, T const& value)
{
	std::list<T>::iterator iter;
	for (iter = list.begin(); iter != list.end(); iter++) {
		if (*iter == value) {
			return true;
		}
	}
	return false;
}

int g_is_continue = 1;

void wait(int ms)
{
	while (g_is_continue) {
		core_api_process_event_loop();
		Sleep(ms);
	}
	system("pause");
	g_is_continue = 1;
}

char USER[1024] = { 0 };
char PASSWD[1024] = { 0 };

char * cred_get_digest(void *udata, CoreApiCredObj cred, CoreApiDigestType type, const char *username, const char *realm)
{
	return PASSWD;
}

const char * cred_get_username(void *udata, CoreApiCredObj cred)
{
	return USER;
}

const char * cred_get_password(void *udata, CoreApiCredObj cred)
{
	return PASSWD;
}

static void acc_login_on_result(void* udata,
								CoreApiObj obj,
								CoreApiAsyncCallerObj caller,
								CoreApiResultObj result)
{
	if (core_api_result_get_code(result) == 200) {
		printf("login succeed\n");
	} else {
		printf("login failed:%d, %s\n", core_api_result_get_code(result),
			   core_api_result_get_phrase(result));
	}
	g_is_continue = 0;
}

static void devmngcb_dev_add(void* udata,
							 CoreApiDevManagerObj manager,
							 CoreApiDevObj devObj)
{
	printf("device add\n");
	CoreApiDevInfoObj devInfo = CORE_API_INVALID_OBJ;
	if (!myfind(g_devObjList, devObj)) {
		CoreApiDevObj dev = core_api_dev_ref(devObj);
		g_devObjList.push_back(dev);
		devInfo = core_api_dev_get_info_ref(dev);
		printf("new device added:\n\
\tuid: %s\n\
\tsn: %s\n\
\tname: %s\n\
\talias name: %s\n\
\tproduct name: %s\n\
\tproduct desc: %s\n\
	",
			   core_api_dev_info_get_uid(devInfo),
			   core_api_dev_info_get_sn(devInfo),
			   core_api_dev_info_get_dev_name(devInfo),
			   core_api_dev_info_get_alias_name(devInfo),
			   core_api_dev_info_get_product_name(devInfo),
			   core_api_dev_info_get_product_desc(devInfo)
			   );
	} else {
		devInfo = core_api_dev_get_info_ref(devObj);
		printf("device already exists, uid %s\n", core_api_dev_info_get_uid(devInfo));
	}
	if (core_api_obj_is_valid(devInfo))
		core_api_dev_info_unref(devInfo);
}

static void devmngcb_dev_del(void* udata,
							 CoreApiDevManagerObj manager,
							 CoreApiDevObj dev)
{
	printf("device del\n");
}

static void devmngcb_dev_online(void* udata,
								CoreApiDevManagerObj manager,
								CoreApiDevObj dev)
{
	printf("device online\n");
}

static void devmngcb_dev_offline(void* udata,
								 CoreApiDevManagerObj manager,
								 CoreApiDevObj dev)
{
	printf("device offline\n");
}

static void enum_camera_on_result(void* udata,
								  CoreApiObj,
								  CoreApiAsyncCallerObj,
								  CoreApiResultObj result)
{
	//CoreApiDevInfoObj devInfo = core_api_dev_get_info_ref(devObj);
	int code = core_api_result_get_code(result);
	if (code == CORE_API_RESULT_OK->code) {

	} else if (100 < code && code < CORE_API_RESULT_OK->code) {
		//printf("continue enum camera %d %s\n", 
		//	   )
	} else {

	}

}

static void devmngcb_dev_usable(void* udata,
								CoreApiDevManagerObj manager,
								CoreApiDevObj dev)
{
	printf("device usable\n");
	CoreApiHelperCameraEnumeratorObj helper = core_api_device_create_camera_enumerator(dev);

}

static void devmngcb_dev_unusable(void* udata,
								  CoreApiDevManagerObj manager,
								  CoreApiDevObj dev)
{
	printf("device unusable\n");
}

static void stun_info_on_result(void* udata,
								CoreApiAccUserDbObj db,
								CoreApiAsyncCallerObj caller,
								CoreApiResultObj result,
								CoreApiSrvInfoObj srvs[])
{
	if (CORE_API_RESULT_OK->code == core_api_result_get_code(result)) {
		printf("stun info succeed:\n");
		int i = 0;
		while (srvs[i] != CORE_API_INVALID_OBJ) {
			CoreApiSrvInfoObj srv_ref = core_api_srv_info_ref(srvs[i++]);
			g_stunSrvInfoObjList.push_back(srv_ref);
			printf("%s %d\n", core_api_srv_info_get_domain(srv_ref),
				   core_api_srv_info_get_port(srv_ref));
		}
	} else {
		printf("stun info failed, code %d, phrase %s\n",
			   core_api_result_get_code(result),
			   core_api_result_get_phrase(result));
	}
	g_is_continue = 0;
}

static void turn_info_on_result(void* udata,
								CoreApiAccUserDbObj db,
								CoreApiAsyncCallerObj caller,
								CoreApiResultObj result,
								CoreApiSrvInfoObj srvs[])
{
	if (CORE_API_RESULT_OK->code == core_api_result_get_code(result)) {
		printf("turn info succeed:\n");
		int i = 0;
		while (srvs[i] != CORE_API_INVALID_OBJ) {
			CoreApiSrvInfoObj srv_ref = core_api_srv_info_ref(srvs[i++]);
			g_turnSrvInfoObjList.push_back(srv_ref);
			printf("%s %d\n", core_api_srv_info_get_domain(srv_ref),
				   core_api_srv_info_get_port(srv_ref));
		}
	} else {
		printf("turn info failed, code %d, phrase %s\n",
			   core_api_result_get_code(result),
			   core_api_result_get_phrase(result));
	}
	g_is_continue = 0;
}

static void sip_info_on_result(void* data,
							   CoreApiAccUserDbObj db,
							   CoreApiAsyncCallerObj caller,
							   CoreApiResultObj result,
							   CoreApiSrvInfoObj srvs[])
{
	if (CORE_API_RESULT_OK->code == core_api_result_get_code(result)) {
		printf("sip info succeed:\n");
		int i = 0;
		while (srvs[i] != CORE_API_INVALID_OBJ) {
			CoreApiSrvInfoObj srv_ref = core_api_srv_info_ref(srvs[i++]);
			g_sipSrvInfoObjList.push_back(srv_ref);
			printf("%s %d\n", core_api_srv_info_get_domain(srv_ref),
				   core_api_srv_info_get_port(srv_ref));
		}
	} else {
		printf("sip info failed, code %d, phrase %s\n",
			   core_api_result_get_code(result),
			   core_api_result_get_phrase(result));
	}
	g_is_continue = 0;
}

void add_stun_info_2_dev_mngr(CoreApiDevManagerObj devMngr)
{
	printf("add stun info to device manager\n");
	CoreApiSrvInfoObj *stun_srv_objs = new CoreApiSrvInfoObj[g_stunSrvInfoObjList.size() + 1];
	int nStunSrv = 0;
	for (g_iter = g_stunSrvInfoObjList.begin(); g_iter != g_stunSrvInfoObjList.end(); g_iter++) {
		stun_srv_objs[nStunSrv++] = *g_iter;
	}
	g_stunSrvInfoObjList.clear();
	stun_srv_objs[nStunSrv] = CORE_API_INVALID_OBJ;
	core_api_dev_manager_add_stun_srvs(devMngr, stun_srv_objs);
	for (int i = 0; i < nStunSrv; i++) {
		core_api_srv_info_unref(stun_srv_objs[i]);
	}
}

void add_turn_info_2_dev_mngr(CoreApiDevManagerObj devMngr)
{
	printf("add turn info to device manager\n");
	CoreApiSrvInfoObj *turn_srv_objs = new CoreApiSrvInfoObj[g_turnSrvInfoObjList.size() + 1];
	int nTurnSrv = 0;
	for (g_iter = g_turnSrvInfoObjList.begin(); g_iter != g_turnSrvInfoObjList.end(); g_iter++) {
		turn_srv_objs[nTurnSrv++] = *g_iter;
	}
	g_turnSrvInfoObjList.clear();
	turn_srv_objs[nTurnSrv] = CORE_API_INVALID_OBJ;
	core_api_dev_manager_add_turn_srvs(devMngr, turn_srv_objs);
	for (int i = 0; i < nTurnSrv; i++) {
		core_api_srv_info_unref(turn_srv_objs[i]);
	}
}

static void sip_login_on_result(void* udata,
								CoreApiObj obj,
								CoreApiAsyncCallerObj caller,
								CoreApiResultObj result)
{
	if (CORE_API_RESULT_OK->code == core_api_result_get_code(result)) {
		printf("sip login succeed\n");
	} else if (100 == core_api_result_get_code(result)) {
		printf("sip logging in...\n");
	} else {
		printf("sip login failed, code %d, phrase %s\n",
			   core_api_result_get_code(result),
			   core_api_result_get_phrase(result));
	}
	g_is_continue = 0;
}

int main(int argc, char* argv[])
{
	if (argc != 3) {
		printf("usage: process email password\n");
		goto QUIT;
	}

	strcpy_s(USER, argv[1]);
	strcpy_s(PASSWD, argv[2]);

	// init
	if (0 != core_api_init(NULL, NULL)) {
		printf("sorry, core_api_init failed\n");
		goto QUIT;
	}

	// create acc stack and start
	CoreApiAccStackObj accStack = core_api_acc_stack_new();
	if (0 != core_api_acc_stack_start(accStack)) {
		printf("accStack start failed, please try again later\n");
		goto QUIT;
	}

	// create srv info, set srv info and user info
	CoreApiCredCb credCb;
	memset(&credCb, 0, sizeof(credCb));
	credCb.get_username = cred_get_username;
	credCb.get_password = cred_get_password;
	credCb.get_digest = cred_get_digest;
	CoreApiCredObj cred = core_api_cred_new(&credCb);
	CoreApiSrvInfoObj accLoginSrvInfo = core_api_srv_info_new();
	core_api_srv_info_set_domain(accLoginSrvInfo, "sip.imagin.cn");
	core_api_srv_info_set_port(accLoginSrvInfo, 18080);
	core_api_srv_info_set_transport(accLoginSrvInfo, CORE_API_TRANSPORT_TCP);
	core_api_srv_info_set_cred(accLoginSrvInfo, cred);

	// create acc contactor
	CoreApiAccContactorObj accContactor = core_api_acc_stack_create_contactor(accStack, accLoginSrvInfo);

	// create acc discoverer
	CoreApiAccDiscovererObj accDiscoverer = core_api_acc_contactor_get_discoverer_ref(accContactor);

	// acc login
	CoreApiAsyncCallerCb loginCb;
	memset(&loginCb, 0, sizeof(loginCb));
	loginCb.on_result = acc_login_on_result;
	printf("now loging in\n");
	core_api_acc_contactor_login(accContactor, &loginCb, NULL);
	wait(10);

	// create dms(include stack, contactor, discoverer)
	printf("create dms(include stack, contactor, discoverer)\n");
	CoreApiDmsStackObj dmsStack = core_api_dms_stack_new();
	if (0 != core_api_dms_stack_start(dmsStack)) {
		printf("dms stack start failed\n");
		goto QUIT;
	}
	CoreApiDmsContactorObj dmsContactor = core_api_dms_stack_create_contactor(dmsStack, accLoginSrvInfo);
	CoreApiDmsDiscovererObj dmsDiscoverer = core_api_dms_contactor_get_discoverer_ref(dmsContactor);

	// create device manager
	printf("create device manager\n");
	CoreApiDevManagerCb devMngCb;
	devMngCb.dev_add = devmngcb_dev_add;
	devMngCb.dev_del = devmngcb_dev_del;
	devMngCb.dev_online = devmngcb_dev_online;
	devMngCb.dev_offline = devmngcb_dev_offline;
	devMngCb.dev_usable = devmngcb_dev_usable;
	devMngCb.dev_unusable = devmngcb_dev_unusable;
	CoreApiDevManagerObj devMngr = core_api_dev_manager_new_for_cb(&devMngCb);

	// add acc stack contactor discovere to devMngr
	core_api_dev_manager_add_stack(devMngr, accStack);
	core_api_dev_manager_add_contactor(devMngr, accContactor);
	core_api_dev_manager_add_discoverer(devMngr, accDiscoverer);

	// add dms to device manager
	printf("add dms to device manager\n");
	core_api_dev_manager_add_stack(devMngr, dmsStack);
	core_api_dev_manager_add_contactor(devMngr, dmsContactor);
	core_api_dev_manager_add_discoverer(devMngr, dmsDiscoverer);

	// get acc user db
	printf("get acc user db\n");
	CoreApiAccUserDbObj accUserDbObj = core_api_acc_contactor_get_user_db_ref(accContactor);

	// get stun server info
	printf("get stun server info\n");
	CoreApiAccUserDbGetStunSrvInfoCb stunCb;
	stunCb.on_result = stun_info_on_result;
	stunCb.udata = NULL;
	core_api_acc_user_db_get_stun_srv_info(accUserDbObj, &stunCb, NULL);
	wait(10);
	add_stun_info_2_dev_mngr(devMngr);

	// get turn server info
	printf("get turn server info\n");
	CoreApiAccUserDbGetTurnSrvInfoCb turnCb;
	turnCb.on_result = turn_info_on_result;
	turnCb.udata = NULL;
	core_api_acc_user_db_get_turn_srv_info(accUserDbObj, &turnCb, NULL);
	wait(10);
	add_turn_info_2_dev_mngr(devMngr);

	// get sip server info
	printf("get sip server info\n");
	CoreApiAccUserDbGetSipSrvInfoCb sipCb;
	sipCb.on_result = sip_info_on_result;
	sipCb.udata = NULL;
	core_api_acc_user_db_get_sip_srv_info(accUserDbObj, &sipCb, NULL);
	wait(10);

	// create sip stack and start
	printf("create sip stack and start\n");
	CoreApiSipListeningPoint lp;
	lp.port = 0;
	lp.transport = CORE_API_TRANSPORT_TCP;
	CoreApiSipPortRange range;
	range.start = 20000;
	range.stop = 30000;
	CoreApiSipStackObj sipStack = core_api_sip_stack_new(&lp, &range);
	if (0 != core_api_sip_stack_start(sipStack)) {
		printf("start sip stack failed\n");
		goto QUIT;
	}
	CoreApiSrvInfoObj firstSipSrvInfoObj = g_sipSrvInfoObjList.front();

	// create sip contactor
	CoreApiSipContactorObj sipContactor = core_api_sip_stack_create_contactor(sipStack, firstSipSrvInfoObj);
	
	// use sip contactor to login
	CoreApiAsyncCallerCb sipLoginCb;
	sipLoginCb.on_result = sip_login_on_result;
	sipLoginCb.udata = NULL;
	core_api_sip_contactor_login(sipContactor, &sipLoginCb, NULL);
	wait(10);
	
	// get sip discoverer from sip contactor
	CoreApiSipDiscovererObj sipDiscoverer = core_api_sip_contactor_get_discoverer_ref(sipContactor);

	// add sip to device manager
	core_api_dev_manager_add_stack(devMngr, sipStack);
	core_api_dev_manager_add_contactor(devMngr, sipContactor);
	core_api_dev_manager_add_discoverer(devMngr, sipDiscoverer);

	// refresh device manager
	core_api_dev_manager_refresh(devMngr);
	wait(10);

	wait(10);
QUIT:

	if (core_api_obj_is_valid(accLoginSrvInfo)) {
		core_api_srv_info_unref(accLoginSrvInfo);
		accLoginSrvInfo = CORE_API_INVALID_OBJ;
	}

	/*if (g_accContactor != CORE_API_INVALID_OBJ) {
		core_api_acc_contactor_unref(g_accContactor);
		g_accContactor = CORE_API_INVALID_OBJ;
	}

	if (accStack != CORE_API_INVALID_OBJ) {
		core_api_acc_stack_stop(accStack);
		core_api_acc_stack_unref(accStack);
		accStack = CORE_API_INVALID_OBJ;
	}

	if (g_dmsStack != CORE_API_INVALID_OBJ) {
		core_api_dms_stack_stop(g_dmsStack);
		core_api_dms_stack_unref(g_dmsStack);
		g_dmsStack = CORE_API_INVALID_OBJ;
	}

	if (core_api_obj_is_valid(g_dmsContactor)) {
		core_api_dms_contactor_unref(g_dmsContactor);
		g_dmsContactor = CORE_API_INVALID_OBJ;
	}

	if (core_api_obj_is_valid(g_dmsDiscoverer)) {
		core_api_dms_discoverer_unref(g_dmsDiscoverer);
		g_dmsDiscoverer = CORE_API_INVALID_OBJ;
	}
*/
	return 0;
}

