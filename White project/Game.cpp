#include "stdafx.h"
#include "Game.h"

//private functions
void Game::initVariables()
{
	
	//Init player
	playerTexture.loadFromFile("Images/Player.png", IntRect(20, 20, 45, 80));
	player = new Player("Knight", playerTexture, window);

	//Init gamemode
	gameMode = GameModes::TRAVEL;
	pause = false;

	//Init location
	location = Locations::CASTLE_HALL;
	
	//Init level
	currentLevel = 1;
	level = new Level(location, &currentLevel, player, window);

	//Set player to level
	level->setPlayer(player);
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
	delete window;
}

//Accessors
const bool Game::running() const {
	return window->isOpen();
}

//Functions

//Check for events
void Game::pollEvents() {
	//event polling
	while (window->pollEvent(event)) {
		switch(event.type) {
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
				
				//window->close();
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

//Update
void Game::update()
{
	//SFML events
	pollEvents();

	// Delta time calculation
	static Clock clock;
	float dt = clock.restart().asSeconds();;

	//Update game objects
	if (!pause) {
		//Update player
		player->update();

		//Update travel mode
		switch (gameMode) {
		case GameModes::TRAVEL:
			level->update(dt);
			break;
		}
	}

	//Set editor mode - TEST!!!!!!!!!!!!!!
	if (editorMode) {
		player->view.setSize(window->getSize().x * 8, window->getSize().y * 8);
		player->velocity = 1000.f;
	}
	else {
		player->view.setSize(window->getSize().x, window->getSize().y);
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

	//Render game
	window->clear();
	level->renderLevel();

	// Display the rendered frame
	window->display();
}
