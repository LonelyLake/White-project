#pragma once

#include "Game.h"
#include "Player.h"
#include "Tile.h"
#include "Item.h"



class Map
{
public:
	RenderWindow* target;

	Player* player;

	Locations location;
	int* currentLevel;

	int height;
	int width;

	float tileSize;
	//float tileScale;

	

	//Map
	vector<vector<Tile>> tiles;

	//Sprites
	Sprite wallSprite;
	Texture wallTexture;

	Sprite emptySprite;
	Texture emptyTexture;

	Sprite secretSprite;
	Texture secretTexture;

	Sprite lockSprite;
	Texture lockTexture;

	//Items
	vector<Item*> items;
	int itemAmount;

public:
	//Tiles coordinates
	int startX;
	int startY;
	int endX;
	int endY;

	int secretX;
	int secretY;

	Map(Level *level);
	~Map();

	//Functions
	void update();
	void render();

	//Functions
	void generateMap(int width, int height, int tileSize);
	void generateItems(vector <Item*> mapItems);

	void loadTileTextures();
};

