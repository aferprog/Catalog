#include "CoinModule.h"

Modules CoinModule::activate(std::any& context)
{
	if (context.has_value()) {
	    collection = std::any_cast<CoreCollection>(context);
		context.reset();
	}
	std::vector<CoreCoin> coins = controller->search(1, collection);
	int i = 0;
	for (const CoreCoin& coin : coins) {
		std::cout << ++i << " " <<coin.id<<"  " << coin.name << " " << coin.quantity << "  ";
		if (coin.IsFavorite) std::cout << "+";
		else std::cout << "-";
		puts("");
	}
	printf("chosse the number of the coin or enter 0 to exit, enter -1 to go back to collections: ");
	int cmd;
	std::cin >> cmd;
	if (cmd == 0)
		return Modules::Exit;
	if (cmd == -1)
		return Modules::Collections;
	context = coins[cmd-1];
	return Modules::CoinDetails;
}
