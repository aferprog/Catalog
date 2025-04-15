#pragma once
#include<iostream>
class CoreCollection {
    std::string name = "";
    int countOfCoins = 0;
public:
    inline std::string getName() const {
        return name;
    }
    inline void setName(const std::string& newName) {
        name = newName;
    }
    inline int getCountOfCoins() const {
        return countOfCoins;
    }
    inline void setCountOfCoins(int newCountOfCoins) {
        countOfCoins = newCountOfCoins;
    }
};