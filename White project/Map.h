#pragma once

#include "Game.h"
#include "Player.h"
#include "Tile.h"

enum class Locations;
class Player;
class Tile;

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
	float tileScale;

	

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

public:
	//Tiles coordinates
	int startX;
	int startY;
	int endX;
	int endY;

	int secretX;
	int secretY;

	Map(Locations location, int* currentLevel, Player* player, RenderWindow* target);
	~Map();

	//Functions
	void update();
	void render();

	void generateMap(int width, int height, int tileSize);
};