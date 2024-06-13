#pragma once


#include "Menu.h"
#include "Player.h"
#include "Level.h"

class Menu;
class Player;
class Level;

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

	Clock clock;
	float dt;

	bool isMenuActive;

//Additions
	Music music;
	
//Game logic:
	
	//Player
	Player* player;
	Texture playerTexture;
	Sprite playerSprite;

	//View
	View view;

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

	//Game processs

public:
	//constructor
	Game();
	//destructor
	virtual ~Game();

	//accessors
	const bool running() const;

	//functions
	void pollEvents();
	void update(float dt);
	void render();

	void gameProcess();

	void run();
	void startGame();
	void exitGame();

private:
	Menu* menu;
};

