#include "stdafx.h"
#include "Player.h"

Player::Player(string name, Texture playerTexture, RenderWindow* window)
{
	this->name = name;
	this->texture = playerTexture;
	positionX = 0;
	positionY = 0;
	//
	sprite.setTexture(texture);
	this->window = window;
}

Player::~Player() {

}

void Player::update()
{
	switch (controls)
	{
	case Controls::UP:
		break;
	case Controls::DOWN:
		break;
	case Controls::LEFT:
		break;
	case Controls::RIGHT:
		break;
	default:
		break;
	}
}

void Player::input() {
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		controls = Controls::UP;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		controls = Controls::DOWN;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		controls = Controls::LEFT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		controls = Controls::RIGHT;
	}
}

void Player::render() {
	window->draw(sprite);
}

void Player::setPosition(int x, int y) {
	this->positionX = x;
	this->positionY = y;
	sprite.setPosition(x, y);
}