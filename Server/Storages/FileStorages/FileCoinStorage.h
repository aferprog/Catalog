#pragma once
#include<fstream>
#include"./Storages/ICoinStorage.h"
class FileCoinStorage:public ICoinStorage
{
public:
	FileCoinStorage(std::string_view path);
	CoinPtr getCoinById(size_t id)const override;
	CoinPtr saveCoin(CoinPtr coin)override;
	std::vector<CoinPtr> getCoins(const Coin& coin)const override;
	int importCoins(std::vector<CoinPtr> additionalCoins) override;
	std::vector<std::string> getCountries()const override;
	std::vector<Collection> getCollections(std::string_view country)const override;
protected:
	std::string filePath;
	virtual std::vector<CoinPtr> getAllCoins()const=0;
	virtual size_t writeCoins(std::vector<CoinPtr> &coins)  =0;
	size_t getNextId();
	void setNextId(size_t id);
};

