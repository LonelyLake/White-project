#include "stdafx.h"

#include "Game.h"
#include "Player.h"
#include "Interface.h"
#include "Inventory.h"
#include "Level.h"
#include "Map.h"
#include "Item.h"



Player::Player(Game* game, string name, Texture playerTexture)
{
	this->window = game->window;
	this->game = game;
	this->level = game->level;

	this->name = name;

	interface = new Interface(this);

	//Stats
	health = 8;
	maxHealth = 10;

	money = 0;

	//Inventory
	inventory = new Inventory(this);
	hasKey = false;

	this->texture = playerTexture;
	positionX = 0.f;
	positionY = 0.f;

	positionXTile = 0;
	//
	sprite.setTexture(texture);
	sprite.setScale(1.5f, 1.5f);
	sprite.setPosition(positionX, positionY);
	sideLook = 'l';

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

void Player::takeDamage(int damage) {
	health -= damage;
}