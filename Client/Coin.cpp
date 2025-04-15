#include"Coin.h"
std::ostream& operator<<(std::ostream& out, const Coin& coin) {
	out << std::left << std::setw(20) << "ID:" << coin.id << std::endl;
	out << std::left << std::setw(20) << "Mintmark:" << (coin.mintmark.empty() ? "N/A" : coin.mintmark) << std::endl;
	out << std::left << std::setw(20) << "Mintage:" << (coin.mintage == -1 ? "N/A" : std::to_string(coin.mintage)) << std::endl;
	out << std::left << std::setw(20) << "Year:" << (coin.year == -1 ? "N/A" : std::to_string(coin.year)) << std::endl;
	out << std::left << std::setw(20) << "Favorite:" << (coin.IsFavorite ? "Yes" : "No") << std::endl;
	out << std::left << std::setw(20) << "Collection:" << (coin.collection.empty() ? "N/A" : coin.collection) << std::endl;
	out << std::left << std::setw(20) << "Name:" << (coin.name.empty() ? "N/A" : coin.name) << std::endl;
	out << std::left << std::setw(20) << "Magnetic:" << (coin.IsMagnetic ? "Yes" : "No") << std::endl;
	out << std::left << std::setw(20) << "Weight (grams):" << (coin.weight == -1 ? "N/A" : std::to_string(coin.weight)) << std::endl;
	out << std::left << std::setw(20) << "Diameter (mm):" << (coin.diameter == -1 ? "N/A" : std::to_string(coin.diameter)) << std::endl;
	out << std::left << std::setw(20) << "Thickness (mm):" << (coin.thickness == -1 ? "N/A" : std::to_string(coin.thickness)) << std::endl;
	out << std::left << std::setw(20) << "Condition:" << (coin.condition == -1 ? "N/A" : std::string(1, coin.condition)) << std::endl;
	out << std::left << std::setw(20) << "Quantity:" << (coin.quantity == -1 ? "N/A" : std::to_string(coin.quantity)) << std::endl;
	out << std::left << std::setw(20) << "Country:" << (coin.country.empty() ? "N/A" : coin.country) << std::endl;
	out << std::left << std::setw(20) << "Shape:" << (coin.shape.empty() ? "N/A" : coin.shape) << std::endl;
	out << std::left << std::setw(20) << "Price:" << (coin.price == -1 ? "N/A" : std::to_string(coin.price)) << std::endl;
	out << std::left << std::setw(20) << "Price of Purchase:" << (coin.priceOfPurchase == -1 ? "N/A" : std::to_string(coin.priceOfPurchase)) << std::endl;
	out << std::left << std::setw(20) << "Material:" << (coin.material.empty() ? "N/A" : coin.material) << std::endl;
	return out;
}