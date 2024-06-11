#pragma once

#include "Item.h"

class Coin
	: public Item
{
private:

public:
	Coin(Texture texture, int value);
	~Coin();
};

