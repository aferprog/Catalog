#pragma once
#include<vector>
#include"./Storages/IUserStorage.h"
class FileUserStorage:public IUserStorage
{
	size_t getLastId();
	void setLastId(size_t id);
protected:
	virtual bool writeUsers(std::vector<User> users) = 0;
	virtual std::vector<User> getAllUsers()=0;
	std::string filePath;
public:
	FileUserStorage(std::string_view path);
	virtual User getUserData(User user)override;
	virtual size_t addUser(const std::string &username, const std::string &password)override;
	virtual ~FileUserStorage() = default;
};

