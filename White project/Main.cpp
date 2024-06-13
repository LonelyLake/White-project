#include "stdafx.h"
#include "Game.h"

//Start program
int main()
{
	//init random seed
	srand(time(NULL));

	// Create an instance of the Game class
	Game game;

	// Run the game
	game.run();

	//End program
	return 0;
}