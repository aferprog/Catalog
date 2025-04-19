#pragma once
#include<iostream>
#include "../General/CoreCollection.h"

class Collection: public CoreCollection {
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