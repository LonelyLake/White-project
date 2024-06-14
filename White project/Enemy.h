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

	char direction;
	float positionX;
	float positionY;

	float attackTimer; //Timer to control enemy's attack frequency
	const float attackDelay = 10.0f; // Delay between attacks (in seconds)


	Enemy();

	Enemy(Level* level, Texture texture, int health, int damage, int speed);
	virtual ~Enemy();

	Enemy(const Enemy& other);

	void update(float deltaTime);
	void move(float deltaTime);
	void attack(float deltaTime);

	bool canAttack();
};

