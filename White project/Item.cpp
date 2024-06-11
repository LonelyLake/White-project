#include "stdafx.h"
#include "Item.h"


Item::Item(Texture texture)
{
	sprite.setTexture(texture);
	sprite.setPosition(positionX, positionY);
}

Item::~Item() {

}