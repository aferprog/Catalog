#include "CSVUserStorage.h"
#include<fstream>


User CSVUserStorage::makeUser(csv::CSVRow& row)
{
    User user;
    user.id = row[0].get<size_t>();
    user.username = row[1].get<std::string>();
    user.password = row[2].get<std::string>();
    return user;
}

bool CSVUserStorage::writeUsers(std::vector<User> users)
{
    /* std::ofstream file(filePath, std::ios_base::out);
    file << std::setprecision(2);
    file << "Id,Mintmark,Mintage,Year,Country,Collection,Name,IsMagnetic,Weight,Diameter,Thickness,Condition,Quantity,Shape,Price,PriceOfPurchase,Material,IsFavorite\n";
    auto writer = csv::make_csv_writer(file);
    for (const CoinPtr& coin : coins) {
        writer<<coin->getAllFieldsAsTuple();
    }                 
    file.close();
    return coins.size();*/
    std::ofstream file(filePath, std::ios_base::out);
    if (!file) {
        std::cerr << "can't open file: "<<filePath;
        return false;
    }
    file << "Id,UserName,Password\n";
    auto writer = csv::make_csv_writer(file);
    for (const User& user: users) {
        writer << user.getAllFieldsAsTuple();
    }
    file.close();
    return true;
}

std::vector<User> CSVUserStorage::getAllUsers()
{
    csv::CSVReader reader(filePath, format);
    std::vector<User> users;
    size_t i = 0;
    for (auto& row : reader) {
        users.push_back(makeUser(row));
    }
    return users;
}

//size_t CSVUserStorage::addUser(std::string username, std::string password)
//{
//    
//}
