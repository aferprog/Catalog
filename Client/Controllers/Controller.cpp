#include "Controller.h"

Controller::Controller(){
	client = std::make_unique<rpc::client>("localhost",8080);
}
std::vector<std::string> Controller::getAllCountries(size_t userId) {
	return client->call("getAllCountries").as<std::vector<std::string>>();
}
int Controller::increment(size_t userId, size_t id) {
	return client->call("increment", id).as<int>();
}
int Controller::decrement(size_t userId, size_t id) {
	return client->call("decrement", id).as<int>();
}
std::vector<CoreCollection> Controller::getCollections(size_t userId, std::string_view country) {
	return client->call("getCollections", country.data()).as<std::vector<CoreCollection>>();
}
bool Controller::addCollection(size_t userId, std::string_view collectionName)
{
	return true; // return client->call("addCollection", userId, collectionName.data()).as<bool>();
}
bool Controller::registration(const std::string& username, const std::string& password)
{
	return true; //return client->call("registration", username, password).as<bool>();
}
size_t Controller::logIn(const std::string& username, const std::string& password)
{
	return 1; //return client->call("logIn", username, password).as<size_t>();
}
std::vector<CoreCoin> Controller::search(size_t userId, CoreCollection collection) {
	return client->call("search", collection).as<std::vector<CoreCoin>>();
}
bool Controller::toggleMark(size_t userId, size_t id) {
	return client->call("toggleMark", id).as<bool>();
}


