#pragma once
#include<rpc/client.h>
#include "../General/IController.h"
using namespace gen;
class Controller :public IController
{
	std::vector<CoinPtr> coinsToPointer(const std::vector<Coin> &a);
	std::unique_ptr<rpc::client>client=nullptr;
public:
	std::vector<CoinPtr> search(size_t userId, Collection collection)override;
	bool toggleMark(size_t userId, size_t id)override;
	int increment(size_t userId, size_t id)override;
	int decrement(size_t userId, size_t id)override;
	std::vector<std::string> getAllCountries(size_t userId)override;
	std::vector<Collection> getCollections(size_t userId, std::string_view country)override;
	Controller();
	~Controller()=default;
};
using ControllerPtr = std::shared_ptr<Controller>;