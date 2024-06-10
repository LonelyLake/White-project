#include "stdafx.h"
#include "Level.h"

enum class Locations;

Level::Level(Locations location,int* currentLevel, Player* player, sf::RenderWindow* target)
{
    this->target = target;
    this->player = player;
    this->location = location;
    tileSize = 50;

    map = new Map(location, currentLevel, player, target);
    map->generateMap(22, 18, tileSize);

    
}

Level::~Level() {
    delete map;
}

void Level::update()
{
	player->positionX = player->sprite.getPosition().x;
	player->positionY = player->sprite.getPosition().y;

	input();
	switch (player->controls)
	{
	case Controls::UP:
		player->sprite.move(0, -0.3f);
		break;
	case Controls::DOWN:
		player->sprite.move(0, 0.3f);
		break;
	case Controls::LEFT:
		player->sprite.move(-0.3f, 0);

		//Test
		cout << map << endl;
		cout << map->tiles[3][player->positionX / map->tileSize].getGlobalBounds().getPosition().x / map->tileSize - 1 << endl;
		break;
	case Controls::RIGHT:
		player->sprite.move(0.3f, 0);
		break;
	default:
		Controls::IDLE;
		break;
	}
}

void Level::input() {
	player->controls = Controls::IDLE;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player->controls = Controls::UP;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player->controls = Controls::DOWN;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player->controls = Controls::LEFT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player->controls = Controls::RIGHT;
	}
}

void Level::renderLevel()
{
    if (target == nullptr) {
        // Error handling: target is null
        //return;
    }

    // Clear the window
    
    // Render the map
    map->render();
    player->render();


}

//Other
void Level::setPlayer(Player* player) {
    this->player = player;
}