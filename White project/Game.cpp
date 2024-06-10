#include "stdafx.h"
#include "Game.h"

//private functions
void Game::initVariables()
{

	playerTexture.loadFromFile("Images/Player.png", IntRect(20, 0, 64, 90));

	player = new Player("Knight", playerTexture, window);

	//Game variables
	location = Locations::CASTLE_HALL;
	
	

	//Level variables
	currentLevel = 1;
	level = new Level(location, &currentLevel, player, window);

	//set player to level
	level->setPlayer(player);

	//Create player////////////////////////////////
	
}

void Game::initWindow()
{
	videomode.height = 1000;
	videomode.width = 1200;
	window = new RenderWindow(videomode, "Simple game", Style::Titlebar | Style::Close);
}

//constructors
Game::Game()
{
	initWindow();
	initVariables();
}

Game::~Game()
{
	delete window;
}
//accessors
const bool Game::running() const {
	return window->isOpen();
}

//functions
void Game::pollEvents() {
	//event polling
	while (window->pollEvent(event)) {
		switch(event.type) {
		case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape) {
				window->close();
			}
			break;
		}
	}
}

void Game::update()
{
	pollEvents();

	level->update();
}

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
	level->renderLevel();

	

	// Draw game objects
	//...

	// Display the rendered frame
	window->display();
}
