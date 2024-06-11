#pragma once

#include "Game.h"
#include "Map.h"
#include "Item.h"
#include "Coin.h"
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
	vector <Item*> mapItems;

	unsigned coinValue;
	Texture coinTexture;

	Level(Locations location, int *currentLevel, Player* player, RenderWindow* target);
	virtual ~Level();

	void update(float deltaTime);

	void input();
	void renderLevel();
	
	//Other
	void setPlayer(Player* player);
	void addMapItems(int itemAmount);
};

