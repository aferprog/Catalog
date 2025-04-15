#pragma once
#include "Module.h"
class CountriesModule :public Module
{
public:
	CountriesModule(ControllerPtr c) :Module(c) {};
	Modules activate(std::any& context)override;
};

