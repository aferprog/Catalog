#pragma once
#include<rpc/server.h>
#include"Controller.h"
#include<memory>
class RPCServer
{
protected:
	std::unique_ptr<rpc::server> server = nullptr;
	std::unique_ptr<Controller> controller = nullptr;
public:
	inline void run() {
		server->run();
	}
	virtual void bindFunctions() {}
	void init(uint16_t port) {
		server = std::make_unique<rpc::server>(port);
		controller = std::make_unique<Controller>();
	}
	virtual ~RPCServer(){}
};

