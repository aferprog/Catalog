#pragma once
#include"RPCCountries.h"
class RPCCollections:public RPCCountries
{
public:
	void bindFunctions()override {
		RPCCountries::bindFunctions();
		server->bind("getCollections", [this](size_t userId,const std::string& country) {
			return controller->getCollections(userId,country);
		});
		puts("collections binded");
	}
};

