#include "stdafx.h"
#include "Heart.h"


Heart::Heart(Level* level, Texture texture, int value) {
	this->level = level;
	this->value = value;
	this->texture = texture;

	isOnMap = false;

	sprite.setTexture(this->texture);
}

Heart::~Heart() {

}

void Heart::takeItem(Player* player)
{
	level->player->money += value;
	cout << "take coin" << endl;
}