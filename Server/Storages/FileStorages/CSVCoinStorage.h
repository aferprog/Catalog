#pragma once
#include"csv.hpp"
#include"Storages/FileStorages/FileCoinStorage.h"
class CSVCoinStorage:public FileCoinStorage
{
	csv::CSVFormat format;
public:
	CSVCoinStorage(std::string path);
protected:
	std::vector<CoinPtr> getAllCoins()const override;
	size_t writeCoins(std::vector<CoinPtr>& coins) override;
};

