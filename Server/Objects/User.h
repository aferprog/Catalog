#pragma once
#include<string>
class User
{
public:
	auto getAllFieldsAsTuple()const {
		return std::make_tuple(id, username, password);
	}
	std::string username;
	std::string password;
	size_t id;
};

