#include "FileCoinStorage.h"
#include<exception>
#include<set>
#include<map>


FileCoinStorage::FileCoinStorage(std::string_view path)
{
    filePath = path;
}

Coin FileCoinStorage::getCoinById(size_t id) const
{
    std::vector<Coin> coins = getAllCoins();
    for (Coin coin : coins)
        if (coin.id == id)
            return coin;
    return {};
}

Coin FileCoinStorage::saveCoin(Coin coin)
{
    std::vector<Coin> coins = getAllCoins();
    Coin res;
    for (Coin& curr : coins) {
        if (curr.id == coin.id) 
        {
            res = curr;
            curr = coin;
            break;
        }
    }
    writeCoins(coins);
    return res;
}

std::vector<Coin> FileCoinStorage::getCoins(const Coin& filter) const
{
    std::vector<Coin> coins = getAllCoins();
    std::vector<Coin> res;
    for (Coin& coin : coins) {
        bool checkCountry = filter.country.empty() ? true : filter.country == coin.country;
        bool checkCollection = filter.collection.empty() ? true : filter.collection == coin.collection;
        if (checkCountry && checkCollection)
            res.push_back(coin);
    }
    return res;
}

int FileCoinStorage::importCoins(std::vector<Coin> additionalCoins)
{
    std::vector<Coin> coins=getAllCoins();
    for (Coin& coin : additionalCoins) {
        coin.id = getNextId();
        setNextId(coin.id+1);
        coins.push_back(coin);
    }
    writeCoins(coins);
    return additionalCoins.size();
}

std::vector<std::string> FileCoinStorage::getCountries() const
{
    std::vector<Coin> coins = getAllCoins();
    std::set<std::string> countries;
    for (Coin& coin : coins)
        countries.insert(coin.country);
    std::vector<std::string>res;
    res.reserve(countries.size());
    for (const std::string& country : countries)
        res.push_back(country);
    return res;
}

std::vector<Collection> FileCoinStorage::getCollections(std::string_view country) const
{
    std::vector<Coin> coins = getAllCoins();
    std::map<std::string,int> collections;
    for (Coin& coin : coins)
        if(coin.country==country)
          collections[coin.collection]++;
    std::vector<Collection>res;
    res.reserve(collections.size());
    for (const auto& collection : collections) {
        Collection coll;
        coll.setName(collection.first);
        coll.setCountOfCoins(collection.second);
        res.push_back(coll);
    }
    return res;
}

size_t FileCoinStorage::getNextId()
{
    size_t id;
    std::fstream file("D:/projects/C++/Catalog/Catalog/LastId.txt", std::ios_base::in);
    file>>id;
    file.close();
    return id;
}

void FileCoinStorage::setNextId(size_t id)
{
    std::fstream file("D:/projects/C++/Catalog/Catalog/LastId.txt", std::ios_base::out);
    file << id;
    file.close();
}
