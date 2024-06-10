#include "stdafx.h"
#include "Player.h"

Player::Player(string name, Texture playerTexture, RenderWindow* window)
{
	this->name = name;
	this->texture = playerTexture;
	positionX = 20;
	positionY = 0;
	//
	sprite.setTexture(texture);
	sprite.setPosition(positionX, positionY);
	this->window = window;
}

Player::~Player() {

}



void Player::render() {
	window->draw(sprite);
}

void Player::setPosition(int x, int y) {
	positionX = x;
	positionY = y;
	sprite.setPosition(positionX, positionY);
}