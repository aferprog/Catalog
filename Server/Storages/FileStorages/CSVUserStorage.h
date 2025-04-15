#pragma once
#include"csv.hpp"
#include"Storages/FileStorages/FileUserStorage.h"
class CSVUserStorage:public FileUserStorage{
	csv::CSVFormat format;
	static User makeUser(csv::CSVRow& row);
protected:
	bool writeUsers(std::vector<User> users)override;
	std::vector<User>getAllUsers()override;
public:
	CSVUserStorage(std::string_view path):FileUserStorage(path){}
	//size_t addUser(std::string username, std::string password)override;
};

