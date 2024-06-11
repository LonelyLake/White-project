#pragma once

#include "Player.h"
#include "Level.h"
#include "Map.h"

//Game modes
enum class GameModes
{
	TRAVEL,
	FIGHT,
	TRADE,
	UPGRADE,
	INVENTORY,

	MENU,
};

//Locations
enum class Locations
{
	CITY,
	CASTLE_HALL,
	CASTLE_MIDDLE,
	CASTLE_STAIRS,
	CASTLE_PRINCESS_ROOM
};




//Game
class Game
{
public:
//Variables:
	//SFML objects
	RenderWindow* window;
	VideoMode videomode;
	Event event;

//Game logic:
	

	//Player
	Player* player;
	Texture playerTexture;
	Sprite playerSprite;

	//Game mode
	GameModes gameMode;
	bool pause;

	//Game world mechanics
	Locations location;
	int currentLevel;
	Level* level;

	//Test
	bool editorMode;

	//Initialization
	void initVariables();
	void initWindow();

public:
	//constructor
	Game();
	//destructor
	virtual ~Game();

	//accessors
	const bool running() const;

	//functions
	void pollEvents();
	void update();
	void render();
};

