#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../sdk/include/kd-core-api/kd-core-api.h"
#pragma comment(lib, "../sdk/lib/win32/Debug/KdCoreApi.lib")

//#include "C:/Global/UnicodeTool.h"

CoreApiAccStackObj g_accStack = CORE_API_INVALID_OBJ;
CoreApiAccUserManagerObj g_accUmng = CORE_API_INVALID_OBJ;
int g_is_continue = 1;

static void is_email_exists_on_result(void* udata,
							   CoreApiAccUserManagerObj accUmng,
							   CoreApiAsyncCallerObj caller,
							   CoreApiResultObj result,
							   int exists)
{
	const char* phrase = core_api_result_get_phrase(result);
	int code = core_api_result_get_code(result);

	if (CORE_API_RESULT_OK->code == code) {
		if (exists) {
			printf("mail already exists, use another\n");
		} else {
			printf("mail not exists\n");
		}
	} else {
		printf("failed : code %d, phrase %s\n", code, phrase);
	}
	g_is_continue = 0;
}

static void send_vcode_on_result(void* udata, 
								 CoreApiObj obj, 
								 CoreApiAsyncCallerObj caller,
								 CoreApiResultObj result)
{
	const char* phrase = core_api_result_get_phrase(result);
	int code = core_api_result_get_code(result);

	if (CORE_API_RESULT_OK->code == code) {
		printf("already send a vcode to your mail.\n");
	} else {
		printf("send vcode failed : code %d, phrase %s\n", code, phrase);
	}
	g_is_continue = 0;
}


int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("usage: process email\n");
		goto QUIT;
	}

	if (0 != core_api_init(NULL, NULL)) {
		printf("sorry, core_api_init failed\n");
		goto QUIT;
	}

	g_accStack = core_api_acc_stack_new();
	if (0 != core_api_acc_stack_start(g_accStack)) {
		printf("accStack start failed, please try again later\n");
		goto QUIT;
	}

	CoreApiSrvInfoObj srvInfo = core_api_srv_info_new();
	core_api_srv_info_set_domain(srvInfo, "sip.imagin.cn");
	core_api_srv_info_set_port(srvInfo, 18080);
	core_api_srv_info_set_transport(srvInfo, CORE_API_TRANSPORT_TCP);

	g_accUmng = core_api_acc_stack_create_user_manager(g_accStack, srvInfo);
	core_api_srv_info_unref(srvInfo);
	srvInfo = CORE_API_INVALID_OBJ;

	CoreApiAccUserManagerIsEmailExistsCb cb;
	memset(&cb, 0, sizeof(cb));
	cb.on_result = is_email_exists_on_result;
	core_api_acc_user_manager_is_email_exists(g_accUmng, argv[1], &cb, NULL);

	while (g_is_continue) {
		core_api_process_event_loop();
		Sleep(10);
	}

	printf("now send vcode for register\n");
	CoreApiAsyncCallerCb cbAsync;
	memset(&cbAsync, 0, sizeof(cbAsync));
	cbAsync.on_result = send_vcode_on_result;
	core_api_acc_user_manager_send_vcode_for_register(g_accUmng, argv[1], &cbAsync, NULL);

	g_is_continue = 1;
	while (g_is_continue) {
		core_api_process_event_loop();
		Sleep(10);
	}
	

QUIT:
	if (g_accUmng != CORE_API_INVALID_OBJ) {
		core_api_acc_user_manager_unref(g_accUmng);
		g_accUmng = CORE_API_INVALID_OBJ;
	}

	if (g_accStack != CORE_API_INVALID_OBJ) {
		core_api_acc_stack_stop(g_accStack);
		core_api_acc_stack_unref(g_accStack);
		g_accStack = CORE_API_INVALID_OBJ;
	}
	return 0;
}