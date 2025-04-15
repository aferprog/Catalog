#pragma once
#include"User.h"
class IUserStorage
{
public:
	virtual User getUserData(User user)=0;
	virtual size_t addUser(const std::string& username, const std::string& password)=0;
	virtual ~IUserStorage() = default;
};

