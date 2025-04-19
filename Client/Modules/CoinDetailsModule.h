#pragma once
#include"Module.h"
class CoinDetailsModule:public Module
{
	void MakeFavorite(CoreCoin& coin);
public:
	CoinDetailsModule(ControllerPtr c) :Module(c) {};
	Modules activate(std::any& context)override;
};

