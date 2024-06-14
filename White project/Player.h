#pragma once

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

	Game* game;
	Interface* interface;

	//Stats
	int health;
	int maxHealth;;
	int damage;

	float velocity;

	int money;

	Inventory* inventory;
	bool hasKey;

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
	char sideLook;

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