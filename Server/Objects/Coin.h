#pragma once
#include<memory>
#include<tuple>
#include<iostream>

#include"../General/CoreCoin.h"

class Coin: public CoreCoin
{
public:
	
	auto getAllFieldsAsTuple()const {
		return std::make_tuple(id,
			mintmark,
			mintage,
			year,
			country,
			collection,
			name,
			IsMagnetic?"true":"false",
			weight,
			diameter,
			thickness,
			numberToCondition(condition),
			quantity,
			shape,
			price,
			priceOfPurchase,
			material,
			IsFavorite?"true":"false");
	}
};
