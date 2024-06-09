#pragma once
#include "Game.h"

enum class Locations;

class Map
{
private:
	RenderWindow* target;

	Locations location;
	int* currentLevel;

	int height;
	int width;
	int tileSize;

	//Tiles coordinates
	int startX;
	int startY;
	int endX;
	int endY;

	int secretX;
	int secretY;

	//Map
	vector<vector<Sprite>> tiles;

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
	Map(Locations location, int* currentLevel, RenderWindow* target);
	~Map();

	//Functions
	void update();
	void render();

	void generateMap(int width, int height, int tileSize);
};