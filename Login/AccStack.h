#pragma once
#include "global.h"
#include "stack.h"

NAMESPACE_BEGIN(Imagin)

class AccStack : public Stack
{
	DECLARE_UNCOPYABLE(AccStack)
public:
	AccStack();
	~AccStack();
	virtual bool CreateStack();
};

NAMESPACE_END
