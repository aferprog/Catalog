#pragma once
#include"Module.h"
class CoinDetailsModule:public Module
{
	void MakeFavorite(CoinPtr coin);
public:
	CoinDetailsModule(ControllerPtr c) :Module(c) {};
	Modules activate(std::any& context)override;
};

