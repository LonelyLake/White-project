#include "stdafx.h"
#include "Game.h"

//private functions
void Game::initVariables()
{

	playerTexture.loadFromFile("Images/Player.png", IntRect(20, 20, 45, 80));

	player = new Player("Knight", playerTexture, window);

	//Game variables
	location = Locations::CASTLE_HALL;
	
	

	//Level variables
	currentLevel = 1;
	level = new Level(location, &currentLevel, player, window);

	//set player to level
	level->setPlayer(player);

	gameMode = GameModes::TRAVEL;
	pause = false;

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
				if (!pause){
					pause = true;
				}
				else {
					pause = false;
				}
				
				//window->close();
			}

			if (event.key.code == Keyboard::K) {
				if (!editorMode) {
					editorMode = true;
				}
				else {
					editorMode = false;
				}

				//window->close();
			}
			break;
		}
	}
}

void Game::update()
{
	pollEvents();

	if (!pause) {
		player->update();
		level->update();
	}

	if (editorMode) {
		player->view.setSize(window->getSize().x * 8, window->getSize().y * 8);
		player->velocity = 5;
	}
	else {
		player->view.setSize(window->getSize().x, window->getSize().y);
		player->velocity = 0.7f;
	}
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
