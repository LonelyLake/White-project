#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Level.h"
#include "Map.h"

//Initialization
void Game::initVariables()
{
	
	//Init player
	playerTexture.loadFromFile("Images/AnimationSheet_Character.png", IntRect(0, 0, 32, 32));
	player = new Player(this, "Knight", playerTexture);

	// Initialize the view with the window's size
	view.setSize(window->getSize().x, window->getSize().y);
	view.setCenter(player->positionX, player->positionY);

	//Init gamemode
	gameMode = GameModes::TRAVEL;
	pause = false;

	//Init location
	location = Locations::CASTLE_HALL;
	
	//Init level
	currentLevel = 1;
	level = new Level(this);

	//Set player to level
	//level->setPlayer(player);
}

void Game::initWindow()
{
	//Create window
	videomode.height = 1000;
	videomode.width = 1200;
	window = new RenderWindow(videomode, "Simple game", Style::Titlebar | Style::Close);
}

//Constructor
Game::Game()
{
	//Initialization
	initWindow();
	initVariables();
}

//Destructor
Game::~Game()
{
	delete level; //Remove later
	delete player;
	delete window;
}

//Accessors
const bool Game::running() const {
	return window->isOpen();
}

//Functions

//Check for events and basic input
void Game::pollEvents() {
	//event polling
	while (window->pollEvent(event)) {
		switch(event.type) {

		//Close window
		case Event::Closed:
			window->close();
			break;

		case Event::KeyPressed:

		//Game pause
			if (event.key.code == Keyboard::Escape) {
				if (!pause){
					pause = true;
				}
				else {
					pause = false;
				}
			}

			//Edtor mode
			if (event.key.code == Keyboard::K) {
				if (!editorMode) {
					editorMode = true;
				}
				else {
					editorMode = false;
				}
			}
			break;
		}
	}
}

//Update game
void Game::update()
{
	//SFML events
	pollEvents();

	// Delta time calculation
	dt = clock.restart().asSeconds();;

	//Update game objects
	if (!pause) {
		//Update player

		player->update();
		// Update the view's center
		view.setCenter(player->positionX,  player->positionY);

		//Update travel mode
		switch (gameMode) {
		case GameModes::TRAVEL:
			level->update(dt);
			break;
		}
	}

	//Set editor mode - TEST!!!!!!!!!!!!!!
	if (editorMode) {
		view.setSize(window->getSize().x * 8, window->getSize().y * 8);
		player->velocity = 1000.f;
	}
	else {
		view.setSize(window->getSize().x, window->getSize().y);
		player->velocity = 400.f;
	}
}

//Render
void Game::render()
{
	/*
		@return void
			- clear old frame
			- render objects
			- display frame in window

		renders game objects
	*/

	
	window->clear();
	//Set view
	window->setView(view);
	//Render game
	level->renderLevel();

	// Display the rendered frame
	window->display();
}

//void Game::gameProcess()
//{
//	if()
//}