#pragma once
#include"Module.h"
class CollectionModule :public Module
{
	std::string country;
public:
	CollectionModule(ControllerPtr c) :Module(c) {};
	Modules activate(std::any& context)override;
};

