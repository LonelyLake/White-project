#pragma once

#include "Game.h"
#include "Map.h"

enum class Locations;
class Map;

class Level
{
public:
	RenderWindow* target;

	Locations location;

	Map* map;

	Texture backgroundTexture;
	Sprite backgroundSprite;
	Level(Locations location, int *currentLevel, RenderWindow* target);
	virtual ~Level();
	void renderLevel();
private:
	
};

