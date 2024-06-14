#include "stdafx.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Level.h"

Goblin::Goblin(Level* level, Texture texture, int health, int damage, int speed)
{
	this->level = level;

	this->texture = texture;
	this->sprite = Sprite(texture);
}

Goblin::~Goblin()
{
}
