#pragma once

#include "Player.h"
#include "Level.h"
#include "Map.h"



enum class GameModes
{
	TRAVEL,
	FIGHT,
	TRADE,
	UPGRADE,
	INVENTORY
};

enum class Locations
{
	CITY,
	CASTLE_HALL,
	CASTLE_MIDDLE,
	CASTLE_STAIRS,
	CASTLE_PRINCESS_ROOM
};

class Player;
class Level;
enum class Locations;


class Game
{
public:
//Variables:
	//SFML objects
	RenderWindow* window;
	VideoMode videomode;
	Event event;

	//Game objects
	Locations location;

	Player* player;
	Texture playerTexture;
	Sprite playerSprite;

	//Game logic
	int currentLevel;
	Level* level;


	//Game mode

	//private functions
	void initVariables();
	void initWindow();

public:
	//constructors
	Game();
	virtual ~Game();

	//accessors
	const bool running() const;

	//functions
	void pollEvents();
	void update();
	void render();
};

