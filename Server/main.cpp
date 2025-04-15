#include <iostream>
#include"Servers/RPC/RPCCoins.h"
int main(){
	std::unique_ptr<RPCServer> server=std::make_unique<RPCCoins>();
	server->init(8080);
	server->bindFunctions();
	server->run();
}