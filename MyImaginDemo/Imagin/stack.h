#pragma once

#include "global.h"
namespace Imagin {

class Stack
{
public:
	Stack() : _stackObj(CORE_API_INVALID_OBJ) {}
	virtual ~Stack() {}
	virtual bool CreateStack() = 0;
	//virtual const CoreApiObj GetObject() const { return _stackObj; }
	operator const CoreApiObj() const { return _stackObj; }
protected:
	CoreApiObj _stackObj;
	DECLARE_UNCOPYABLE(Stack)
};

NAMESPACE_END
