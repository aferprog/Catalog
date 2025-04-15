#pragma once
#include<memory>
#include<tuple>
#include <rpc/msgpack.hpp>
#include<iostream>

#include"../General/CoreCoin.h"

class Coin: public CoreCoin
{
public:
	MSGPACK_DEFINE(id, mintmark, mintage, year, country, collection, name, IsMagnetic, weight, diameter, thickness,condition, quantity, shape, price, priceOfPurchase, material, IsFavorite);
	
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
using CoinPtr = std::shared_ptr<Coin>;
