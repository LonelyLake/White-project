#pragma once

#include "Game.h"
#include "Map.h"
#include "Item.h"
#include "Coin.h"
#include "Heart.h"
#include "Player.h"




class Level
{
public:
	//Window
	RenderWindow* target;

	//Player
	Player* player;

	//Location
	Locations location;

	//Level
	int* currentLevel;
	//Texture backgroundTexture;
	//Sprite backgroundSprite;

	//Map
	Map* map;
	int tileSize;
	int newXTile;

	//Items
	int itemAmount;
	vector <Item*> mapItems;

	unsigned coinValue;
	Texture coinTexture;
	Texture heartTexture;

	bool up;
	bool down;
	bool left;
	bool right;

	bool isActiveKey;

	Level(Locations location, int* currentLevel, Player* player, RenderWindow* target);
	virtual ~Level();

	void update(float deltaTime);

	void input(float deltaTime);
	void renderLevel();

	//Other
	void setPlayer(Player* player);
	void addMapItems(int itemAmount);

	void updatePlayerAnimation(float deltaTime);
};

