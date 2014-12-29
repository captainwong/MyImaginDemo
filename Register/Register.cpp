// Register.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//#include "unistd.h"
#include "../sdk/include/kd-core-api/kd-core-api.h"
#pragma comment(lib, "../sdk/lib/win32/Debug/KdCoreApi.lib")


CoreApiAccStackObj g_accStack = CORE_API_INVALID_OBJ;
CoreApiAccUserManagerObj g_accUmng = CORE_API_INVALID_OBJ;
CoreApiAccUserObj g_user = CORE_API_INVALID_OBJ;
int g_is_continue = 1;

static void acc_register_on_result(void* udata,
								   CoreApiObj obj,
								   CoreApiAsyncCallerObj caller,
								   CoreApiResultObj result)
{
	if (core_api_result_get_code(result) == 200) {
		printf("register succeed\n");
	} else {
		printf("register failed:%d, %s\n", core_api_result_get_code(result),
			   core_api_result_get_phrase(result));
	}
	g_is_continue = 0;
}



int main(int argc, char* argv[])
{
	if (argc != 6) {
		printf("usage: process email mphone username password vcode\n");
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

	g_user = core_api_acc_user_new();
	core_api_acc_user_set_email(g_user, argv[1]);
	core_api_acc_user_set_mphone(g_user, argv[2]);
	core_api_acc_user_set_username(g_user, argv[3]);
	core_api_acc_user_set_password(g_user, argv[4]);

	CoreApiAsyncCallerCb cb;
	memset(&cb, 0, sizeof(cb));
	cb.on_result = acc_register_on_result;
	core_api_acc_user_manager_register_user(g_accUmng, g_user, argv[5], &cb, NULL);

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

