#pragma once
#include"Storages/FileStorages/CSVCoinStorage.h"
#include"Storages/FileStorages/CSVUserStorage.h"
#include"Storages/ICoinStorage.h"
#include"Storages/IUserStorage.h"
#include"../General/IController.h"
class Controller :public IController
{
	std::unique_ptr<IUserStorage> userStorage;
	std::unique_ptr<ICoinStorage> coinStorage;
public:
	bool addCollection(size_t userId, std::string_view collectioName)override;
	bool registration(const std::string& username, const std::string& password)override;
	size_t logIn(const std::string& username, const std::string& password)override;
	std::vector<CoinPtr> search(size_t userId, CoreCollection collection) override;
	bool toggleMark(size_t userId,size_t id)override;
	int increment(size_t userId,size_t id)override;
	int decrement(size_t userId,size_t id)override;
    std::vector<std::string> getAllCountries(size_t userId)override;
	std::vector<CoreCollection> getCollections(size_t userId,std::string_view country)override;
	Controller();
	~Controller();
};

