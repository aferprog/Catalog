#pragma once
#include<any>
#include"../Controller.h"
enum Modules
{
	Countries,
	Collections,
	Coins,
	CoinDetails,
	Exit
};
class Module
{
protected:
	ControllerPtr controller;
	Module(ControllerPtr c) { controller = c; }
public:
	virtual Modules activate(std::any &context)=0;
};