#include"csv.hpp"
#include"CSVCoinStorage.h"
#include<iomanip>
#pragma message("Compiling CSVStorage.cpp")
static void fillCoin(Coin coin, csv::CSVRow& row);
std::vector<Coin> CSVCoinStorage::getAllCoins()const
{

    csv::CSVReader reader(filePath,format);
    std::vector<Coin> coins;
    size_t i = 0;
    for (auto& row : reader) {
        coins.push_back(Coin{});
        fillCoin(coins[i++], row);
    }
    return coins;
}

size_t CSVCoinStorage::writeCoins(std::vector<Coin>& coins)
{
    std::ofstream file(filePath, std::ios_base::out);
    if (!file) {
        std::cerr << "can't open file: " << filePath;
        return 0;
    }
    file << std::setprecision(2);
    file << "Id,Mintmark,Mintage,Year,Country,Collection,Name,IsMagnetic,Weight,Diameter,Thickness,Condition,Quantity,Shape,Price,PriceOfPurchase,Material,IsFavorite\n";
    auto writer = csv::make_csv_writer(file);
    for (const Coin& coin : coins) {
        writer<<coin.getAllFieldsAsTuple();
    }                 
    file.close();
    return coins.size();
}



CSVCoinStorage::CSVCoinStorage(std::string path):FileCoinStorage(path)
{
    format.delimiter(',');
    format.header_row(0);
}
//Id,Mintmark,Mintage,Year,Country,Collection,Name,IsMagnetic,Weight,Diameter,Thickness,Condition,Quantity,Shape,Price,Nominal,PriceOfPurchase,Material
void fillCoin(Coin coin, csv::CSVRow& row)
{
    coin.id = row[0].get<size_t>();
    coin.mintmark = row[1].get<std::string>();
    coin.mintage = row[2].get<int>();
    coin.year = row[3].get<int>();
    coin.country = row[4].get<std::string>();
    coin.collection = row[5].get<std::string>();
    coin.name = row[6].get<std::string>();
    coin.IsMagnetic = row[7].get<std::string>()=="true";
    coin.weight = row[8].get<float>();
    coin.diameter = row[9].get<float>();
    coin.thickness = row[10].get<float>();
    coin.condition = Coin::conditionToNumber(row[11].get<std::string>());
    coin.quantity = row[12].get<int>();
    coin.shape = row[13].get<std::string>();
    coin.price = row[14].get<float>();
    coin.priceOfPurchase = row[15].get<float>();
    coin.material = row[16].get<std::string>();

}
