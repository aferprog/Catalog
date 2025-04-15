#include "CollectionModule.h"

Modules CollectionModule::activate(std::any& context)
{
	if (context.has_value()) {
		country = std::any_cast<std::string>(context);
		context.reset();
	}
	std::vector<Collection> collections=controller->getCollections(country);
	int i = 0;
	for (const Collection& a : collections) {
		std::cout << ++i << " " << a.getName()<<" "<< a.getCountOfCoins() << "\n";
	}
	printf("chosse the number of the collection or enter 0 to exit, enter -1 to go back to countries: ");
	int cmd;
	std::cin >> cmd;
	if (cmd == 0)
		return Modules::Exit;
	if (cmd == -1)
		return Modules::Countries;
	context = collections[cmd - 1];
	return Modules::Coins;
}
