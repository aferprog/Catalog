#pragma once
#include"Modules/CountriesModule.h"
#include"Modules/Module.h"
#include"Controller.h"
class Application
{
	ControllerPtr controller;
	std::vector<std::unique_ptr<Module>> modules;
public:
	void run();
	Application();
};

