#pragma once
#include<Coin.h>
#include<iostream>
#include<Collection.h>
#include<vector>
class ICoinStorage
{
public:
    virtual int importCoins(std::vector<CoinPtr> additionalCoins) =0;
    virtual CoinPtr getCoinById(size_t id)const = 0;
    virtual CoinPtr saveCoin(CoinPtr coin) = 0;
    virtual std::vector<CoinPtr> getCoins(const Coin& coin)const = 0;
    virtual ~ICoinStorage() = default; // Virtual destructor 
    virtual std::vector<Collection> getCollections(std::string_view country)const = 0;
    virtual std::vector<std::string> getCountries()const=0;
};