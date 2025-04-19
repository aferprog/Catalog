#include "Storages/FileStorages/FileUserStorage.h"
#include<algorithm>
#include<fstream>

size_t FileUserStorage::getLastId()
{
    size_t id;
    std::fstream file("./UsersData/LastUserId.txt", std::ios_base::in);
    file >> id;
    file.close();
    return id;
}

void FileUserStorage::setLastId(size_t id)
{
    std::fstream file("D:/projects/C++/Catalog/Catalog/UsersData/LastUserId.txt", std::ios_base::out);
    file << id;
    file.close();
}

FileUserStorage::FileUserStorage(std::string_view path)
{
    filePath = path;
}

User FileUserStorage::getUserData(User target)
{
    std::vector<User> users=getAllUsers();
    auto it=std::find_if(users.begin(), users.end(), [target](const User& curr) {
        return curr.username == target.username || curr.id == target.id;
    });
    if (it != users.end())
        return *it;
    return {"","",0 };
}

size_t FileUserStorage::addUser(const std::string& username, const std::string& password)
{
    /*std::vector<Coin> coins=getAllCoins();
    for (Coin& coin : additionalCoins) {
        coin.id = getNextId();
        setNextId(coin.id+1);
        coins.push_back(coin);
    }
    writeCoins(coins);
    return additionalCoins.size();*/
    size_t id = getLastId();
    setLastId(id+1);
    User user;
    user.id = id;
    user.password = password;
    user.username = username;
    std::vector<User> users = getAllUsers();
    users.push_back(user);
    writeUsers(users);
    return id;
}