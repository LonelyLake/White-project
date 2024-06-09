#pragma once

#include "Game.h"
#include "Level.h"

class Level;

enum class Controls
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};


class Player
{

private:
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

	Player(string name, Texture playerTexture, RenderWindow* window);

	~Player();

	void update();
	void render();

	void input();

	//Other functions
	void setPosition(int x, int y);

};