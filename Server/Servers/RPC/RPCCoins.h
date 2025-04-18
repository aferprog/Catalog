#pragma once
#include"RPCCollections.h"
class RPCCoins:public RPCCollections
{
public:
	void bindFunctions()override {
		RPCCollections::bindFunctions();
		server->bind("search", [this](size_t userId,const Collection& col) {
			return controller->search(userId, col);
		});
		server->bind("toggleMark", [this](size_t userId,size_t id) {
			return controller->toggleMark(userId, id);
			});
		server->bind("increment", [this](size_t userId,size_t id) {
			return controller->increment(userId,id);
			});
		server->bind("decrement", [this](size_t userId,size_t id) {
			return controller->decrement(userId, id);
		});
		puts("coins functions binded");
	}
};

