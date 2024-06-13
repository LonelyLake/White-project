#pragma once


class Level;
class Map;

enum class Controls
{
	IDLE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
};


class Player
{

public:
	string name;

	//Stats
	int health;
	int masHealth;;
	int damage;

	float velocity;

	int money;

	//Position of the player on the map.
	float positionX;
	float positionY;

	int positionXTile;
	int positionYTile;

	//Control keys
	Controls controls;

	//Camera view

	//Window
	RenderWindow* window;
	
public:
	//Variables
	Texture texture;
	Sprite sprite;

	//Level*
	Level* level;
	Map* map;

	Player(Game* game, string name, Texture playerTexture);

	~Player();

	void update();
	void render();

	void input();

	//Other functions
	void setPosition(int x, int y);

};