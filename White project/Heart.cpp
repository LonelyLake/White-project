#include "stdafx.h"
#include "Heart.h"
#include "Level.h"
#include "Player.h"

Heart::Heart(Level* level, Texture texture, int value) {
	this->level = level;
	this->texture = texture;
	this->value = value;

	isOnMap = false;
	used = false;

	sprite.setTexture(this->texture);
}

Heart::~Heart() {

}

void Heart::takeItem(Player* player)
{
	if(player->health < player->maxHealth) {
		level->player->health += value;
		used = true;
	}
	cout << "take coin" << endl;
}