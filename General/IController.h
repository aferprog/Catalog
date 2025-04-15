#pragma once
#include<memory>
#include"./CoreCoin.h"
#include "./CoreCollection.h"

using CoinPtr = std::shared_ptr<CoreCoin>;

class IController
{

public:
	virtual bool addCollection(size_t userId,std::string_view collectioName)=0;
	virtual bool registration(const std::string& username, const std::string& password)=0;
	virtual size_t logIn(const std::string& username, const std::string& password) = 0;
	virtual std::vector<CoinPtr> search(size_t userId, CoreCollection collection)=0;
	virtual bool toggleMark(size_t userId,size_t coinId)=0;
	virtual int increment(size_t userId,size_t coinId)=0;
	virtual int decrement(size_t userId,size_t coinId)=0;
	virtual std::vector<std::string> getAllCountries(size_t userId)=0;
	virtual std::vector<CoreCollection> getCollections(size_t userId,std::string_view country)=0;
};

