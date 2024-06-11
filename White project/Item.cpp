#include "stdafx.h"
#include "Item.h"

Item::Item() {

}
Item::Item(Texture texture)
{
    this->texture = texture;
    this->sprite = Sprite(texture);
    this->isOnMap = false;
    this->value = 0;
	sprite.setTexture(texture);
	isOnMap = false;
}

Item::Item(const Item& other) {
    // Copy the members of the other object
    //positionX = other.positionX;
	//positionY = other.positionY;
    texture = other.texture;
    sprite = Sprite(texture); // Assign the texture to the sprite
    isOnMap = other.isOnMap;
    value = other.value;
    //... copy other members...

    
}

//Item::Item(const Item& sItem)
//{
//
//}

Item::~Item() {

}

