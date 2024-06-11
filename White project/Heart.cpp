#include "stdafx.h"
#include "Heart.h"

Heart::Heart(Texture texture, int value) {
	this->value = value;
	this->texture = texture;

	isOnMap = false;

	sprite.setTexture(this->texture);
}

Heart::~Heart() {

}