#pragma once

#include "Game.h"
#include "Level.h"
#include "Map.h"

class Level;
class Map;

enum class Controls
{
	IDLE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};


class Player
{

public:
	string name;

	//Stats
	int health;
	int damage;

	//Position of the player on the map.
	int positionX;
	int positionY;

	Controls controls;

	//Window
	RenderWindow* window;
	
public:
	//Variables
	Texture texture;
	Sprite sprite;

	//Level*
	Level* level;
	Map* map;

	Player(string name, Texture playerTexture, RenderWindow* window);

	~Player();

	void update();
	void render();

	void input();

	//Other functions
	void setPosition(int x, int y);

};