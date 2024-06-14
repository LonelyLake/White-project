#include "stdafx.h"
#include "Level.h"
#include "Player.h"
#include "Item.h"
#include "Key.h"

Key::Key(Level* level, Texture texture) {
	this->texture = texture;

	isOnMap = false;
	used = false;

	sprite.setTexture(this->texture);
}

Key::~Key() {

}

void Key::takeItem(Player* player)
{
	player->hasKey = true;
	cout << "Player has key" << endl;
	cout << "take coin" << endl;
}
#pragma once

#include "Item.h"
#include "Level.h"