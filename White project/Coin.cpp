#include "stdafx.h"
#include "Coin.h"
#include "Level.h"
#include "Player.h"

Coin::Coin(Level* level, Texture texture, int value) {
	this->level = level;
	this->value = value;
	this->texture = texture;

	isOnMap = false;

	sprite.setTexture(this->texture);
}

Coin::~Coin() {

}

void Coin::takeItem(Player* player)
{
	level->player->money += value;
	cout << "take coin" << endl;
}
#pragma once

#include "Item.h"
#include "Level.h"


