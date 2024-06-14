#pragma once

class Enemy
{
public:
	Level* level;

	int health;
	int damage;
	int speed;

	Texture texture;
	Sprite sprite;

	Enemy();

	Enemy(Level* level, Texture texture, int health, int damage, int speed);
	virtual ~Enemy();

	Enemy(const Enemy& other);
};

