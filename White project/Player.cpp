#include "stdafx.h"
#include "Player.h"
#include "Game.h"

Player::Player(Game* game, string name, Texture playerTexture)
{
	this->window = game->window;
	

	this->name = name;
	this->texture = playerTexture;
	positionX = 0.f;
	positionY = 0.f;

	positionXTile = 0;
	//
	sprite.setTexture(texture);
	sprite.setScale(1.5f, 1.5f);
	sprite.setPosition(positionX, positionY);

	velocity = 10.f;


	
}

Player::~Player() {
	
}

void Player::update() {

	
	
}

void Player::render() {
	
	
	window->draw(sprite);
}

void Player::setPosition(int x, int y) {
	positionX = x;
	positionY = y;
	sprite.setPosition(positionX, positionY);
}