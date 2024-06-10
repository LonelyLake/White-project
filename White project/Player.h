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

	float velocity;

	//Position of the player on the map.
	float positionX;
	float positionY;

	int positionXTile;
	int positionYTile;

	View view;

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