#include "stdafx.h"
#include "Coin.h"

Coin::Coin(Texture texture, int value) {
	this->value = value;
	this->texture = texture;

	isOnMap = false;

	sprite.setTexture(this->texture);
}

Coin::~Coin() {

}