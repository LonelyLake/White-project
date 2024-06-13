#pragma once

#include "Game.h"
#include "Map.h"
#include "Item.h" //
#include "Coin.h"
#include "Heart.h"

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

	//Controls
	bool up;
	bool down;
	bool left;
	bool right;

	bool isActiveKey;

	//Constructor
	Level(Game* game);
	//Destructor
	virtual ~Level();

//Functions:
	//Update
	void update(float deltaTime);
	void updatePlayerAnimation(float deltaTime);
	//Input
	void input(float deltaTime);
	//Render
	void renderLevel();

	//Other
	//void setPlayer(Player* player);
	
	//Add items that will appear on map
	void addMapItems(int itemAmount);

	//void checkItemCollision();
	//void handleItemCollision(Item* item);

	void nearItems();
	void takeItem(Item* item);
};