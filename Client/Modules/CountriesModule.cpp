#include "CountriesModule.h"

Modules CountriesModule::activate(std::any& context)
{
    std::vector<std::string> countries=controller->getAllCountries(1);
    int i = 1;
    for (const std::string& a : countries) {
        std::cout << i++ <<" " << a << "\n";
    }
    printf("chosse the number of the country or enter 0 to exit: ");
    int cmd;
    std::cin >> cmd;
    if (cmd == 0)
        return Modules::Exit;
    context = countries[cmd - 1];
    return Modules::Collections;
}
