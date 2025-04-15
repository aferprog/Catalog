#include "CoinDetailsModule.h"

void CoinDetailsModule::MakeFavorite(CoinPtr coin)
{
	coin->IsFavorite = controller->toggleMark(coin->id);
}

Modules CoinDetailsModule::activate(std::any& context)
{
	CoinPtr coin = std::any_cast<CoinPtr>(context);
	context.reset();
	int cmd = 1;
	while (cmd == 1) {
		std::cout << *coin;
		printf("enter 1 to toggle isFavorite enter 0 to exit, enter -1 to go back to coins, '2' to add coin and '3' to remove coin: ");
		std::cin >> cmd;
		if (cmd == 2) {
			controller->increment(coin->id);
			coin->quantity++;
		}
		if (cmd == 3) {
			controller->decrement(coin->id);
			coin->quantity = std::max(0, coin->quantity-1);
		}

		if (cmd == 1)
			MakeFavorite(coin);
		if (cmd == 0)
			return Modules::Exit;
		if (cmd == -1)
			return Modules::Coins;
	}
}
