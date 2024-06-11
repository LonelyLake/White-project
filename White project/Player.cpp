#include "stdafx.h"
#include "Player.h"

Player::Player(string name, Texture playerTexture, RenderWindow* window)
{
	this->name = name;
	this->texture = playerTexture;
	positionX = 0.f;
	positionY = 0.f;

	positionXTile = 0;
	//
	sprite.setTexture(texture);
	sprite.setScale(1.5f, 1.5f);
	sprite.setPosition(positionX, positionY);

	velocity = 0.7f;

	this->window = window;

	// Initialize the view with the window's size
	view.setSize(window->getSize().x, window->getSize().y);
	//TEst view.setSize(window->getSize().x * 8, window->getSize().y * 8);

	view.setCenter(positionX, positionY);
}

Player::~Player() {
	view.setCenter(positionX, positionY);
}

void Player::update() {

	// Update the view's center
	view.setCenter(positionX, positionY);
	
}

void Player::render() {
	window->setView(view);
	
	window->draw(sprite);
}

void Player::setPosition(int x, int y) {
	positionX = x;
	positionY = y;
	sprite.setPosition(positionX, positionY);
}