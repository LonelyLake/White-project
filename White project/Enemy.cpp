#include "stdafx.h"
#include "Enemy.h"
#include "Level.h"


Enemy::Enemy() {

}

Enemy::Enemy(Level* level, Texture texture, int health, int damage, int speed)
{
    this->level = level;

    this->texture = texture;
    sprite.setTexture(texture);
}

Enemy::Enemy(const Enemy& other) {
    // Copy the members of the other object
    //positionX = other.positionX;
    //positionY = other.positionY;
    texture = other.texture;
    sprite = Sprite(texture); // Assign the texture to the sprite
    //... copy other members...
}

Enemy::~Enemy() {}