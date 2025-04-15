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
std::vector<Collection> Controller::getCollections(size_t userId, std::string_view country) {
	return client->call("getCollections", country.data()).as<std::vector<Collection>>();
}
std::vector<CoinPtr> Controller::coinsToPointer(const std::vector<Coin> &a){
	std::vector<CoinPtr> res(a.size());
	for (size_t i = 0; i < a.size(); ++i) {
		res[i]=std::make_shared<Coin>(a[i]);
	}
	return res;
}
std::vector<CoinPtr> Controller::search(size_t userId, Collection collection) {
	auto coins= client->call("search", collection).as<std::vector<Coin>>();
	return coinsToPointer(coins);
}
bool Controller::toggleMark(size_t userId, size_t id) {
	return client->call("toggleMark", id).as<bool>();
}


