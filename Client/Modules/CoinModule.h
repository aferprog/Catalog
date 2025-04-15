#pragma once
#include "Module.h"
class CoinModule :public Module
{
	Collection collection;
public:
	CoinModule(ControllerPtr c) :Module(c) {};
	Modules activate(std::any& context)override;
};

