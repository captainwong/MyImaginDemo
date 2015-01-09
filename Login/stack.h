#pragma once

#include "global.h"
NAMESPACE_BEGIN(Imagin)

class Stack
{
	DECLARE_UNCOPYABLE(Stack)
public:
	Stack() : _stackObj(CORE_API_INVALID_OBJ) {}
	virtual ~Stack() {}
	virtual bool CreateStack() = 0;
	virtual const CoreApiObj GetStack() const { return _stackObj; }
protected:
	CoreApiObj _stackObj;
};

NAMESPACE_END
