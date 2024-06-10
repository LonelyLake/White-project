#pragma once

#include "Game.h"
#include "Map.h"
#include "Player.h"

class Player;
enum class Locations;
class Map;
class Tile;


class Level
{
public:
	RenderWindow* target;

	Locations location;

	Map* map;

	int tileSize;

	int newXTile;

	Texture backgroundTexture;
	Sprite backgroundSprite;

	Player* player;

	Level(Locations location, int *currentLevel, Player* player, RenderWindow* target);
	virtual ~Level();

	void update();

	void input();
	void renderLevel();
	
	//Other
	void setPlayer(Player* player);
};

