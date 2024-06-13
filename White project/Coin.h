#pragma once

#include "Item.h"

class Coin
	: public Item
{


public:
	Level* level;
	Coin(Level* level, Texture texture, int value);
	~Coin();

	void takeItem(Player* player);
};
