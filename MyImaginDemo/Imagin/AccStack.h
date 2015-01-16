#pragma once
#include "global.h"
#include "stack.h"

namespace Imagin
{


class AccStack : public Stack
{
	DECLARE_UNCOPYABLE(AccStack)
public:
	AccStack();
	~AccStack();
	virtual bool CreateStack();

};

NAMESPACE_END
