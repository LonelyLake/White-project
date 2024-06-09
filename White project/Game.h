#pragma once

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

	//Game logic
	int currentLevel;
	Level* level;

	//Map


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

