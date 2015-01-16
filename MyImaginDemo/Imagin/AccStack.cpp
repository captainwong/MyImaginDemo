#include "stdafx.h"
#include "AccStack.h"

NAMESPACE_BEGIN(Imagin)

AccStack::AccStack() : Stack()
{}


AccStack::~AccStack()
{
	if (core_api_obj_is_valid(_stackObj)) {
		core_api_acc_stack_stop((CoreApiAccStackObj)_stackObj);
		core_api_acc_stack_unref((CoreApiAccStackObj)_stackObj);
		_stackObj = CORE_API_INVALID_OBJ;
	}
}


bool AccStack::CreateStack()
{
	if (core_api_obj_is_valid(_stackObj)) {
		core_api_acc_stack_stop((CoreApiAccStackObj)_stackObj);
		core_api_acc_stack_unref((CoreApiAccStackObj)_stackObj);
		_stackObj = CORE_API_INVALID_OBJ;
	}

	_stackObj = (CoreApiObj)core_api_acc_stack_new();
	if (!core_api_obj_is_valid(_stackObj))
		return false;

	if (core_api_acc_stack_start(_stackObj))  {
		core_api_acc_stack_unref((CoreApiAccStackObj)_stackObj);
		return false;
	}

	return true;
}

NAMESPACE_END
