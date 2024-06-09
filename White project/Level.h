#pragma once

#include "Game.h"
#include "Map.h"
#include "Player.h"

class Player;
enum class Locations;
class Map;


class Level
{
public:
	RenderWindow* target;

	Locations location;

	Map* map;

	int tileSize;

	Texture backgroundTexture;
	Sprite backgroundSprite;

	Player* player;

	Level(Locations location, int *currentLevel, RenderWindow* target);
	virtual ~Level();
	void renderLevel();
	
	//Other
	void setPlayer(Player* player);
};

