#pragma once

#include "Game.h"
#include "Map.h"
#include "Item.h"
#include "Player.h"




class Level
{
public:
	RenderWindow* target;

	Locations location;

	//Texture backgroundTexture;
	//Sprite backgroundSprite;

	Map* map;
	int tileSize;
	int newXTile;



	Player* player;

	

	Level(Locations location, int *currentLevel, Player* player, RenderWindow* target);
	virtual ~Level();

	void update(float deltaTime);

	void input();
	void renderLevel();
	
	//Other
	void setPlayer(Player* player);
};

