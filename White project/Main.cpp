#include "stdafx.h"
#include "Game.h"

int main()
{
	//init random seed
	srand(time(NULL));
	//init Game engine
	Game game;

	//Game loop
	while (game.running())
	{
		//Update
		game.update();
		//Render
		game.render();
	}

	return 0;
}