#pragma once
#include"csv.hpp"
#include"Storages/FileStorages/FileCoinStorage.h"
class CSVCoinStorage:public FileCoinStorage
{
	csv::CSVFormat format;
public:
	CSVCoinStorage(std::string path);
protected:
	std::vector<Coin> getAllCoins()const override;
	size_t writeCoins(std::vector<Coin>& coins) override;
};

