#include "Controller.h"
#include<iostream>

bool Controller::addCollection(size_t userId, std::string_view collectioName)
{
	return false;
}

bool Controller::registration(const std::string& username,const std::string& password)
{
	userStorage->addUser(username, password);
	return true;
}

size_t Controller::logIn(const std::string& username, const std::string& password)
{
	User u;
	u.password = password;
	u.username = username;
	User user=userStorage->getUserData(u);
	if (user.id == 0)
		return 0;
	return user.id;
}

std::vector<CoreCoin> Controller::search(size_t userId, CoreCollection collection)
{
	Coin a;
	a.collection = collection.getName();
	std::vector<Coin> coins = coinStorage->getCoins(a);
	std::vector<CoreCoin> result(0);
	result.reserve(coins.size());
	for (Coin& coin : coins)
		result.push_back(coin);
	return result;
}

bool Controller::toggleMark(size_t userId,size_t id)
{
	Coin coin = coinStorage->getCoinById(id);
	coin.IsFavorite=!coin.IsFavorite;
	coinStorage->saveCoin(coin);
	return coin.IsFavorite;
}
int Controller::increment(size_t userId,size_t id)
{
	Coin coin = coinStorage->getCoinById(id);
	coin.quantity++;
	coinStorage->saveCoin(coin);
	return coin.quantity;
}
int Controller::decrement(size_t userId,size_t id)
{
	Coin coin = coinStorage->getCoinById(id);
	coin.quantity--;
	coinStorage->saveCoin(coin);
	return coin.quantity;
}
std::vector<std::string> Controller::getAllCountries(size_t userId)
{
	return coinStorage->getCountries();
}
std::vector<CoreCollection> Controller::getCollections(size_t userId,std::string_view country)
{
	std::vector<Collection> collections = coinStorage->getCollections(country);
	std::vector<CoreCollection> result(0);
	result.reserve(collections.size());
	for (const Collection& collection: collections)
		result.push_back(std::move(collection));

	return result;

}
Controller::Controller()
{
	userStorage = std::make_unique<CSVUserStorage>("D:/projects/C++/Catalog/Catalog/Users.csv");
	if (!userStorage)
		std::cerr << "can't create a storage";
	coinStorage = std::make_unique<CSVCoinStorage>("D:/projects/C++/Catalog/Catalog/TestCSVData.csv");
	if (!coinStorage)
		std::cerr << "can't create a storage";
}

Controller::~Controller()
{
	
}
