#include "stdafx.h"
#include "Level.h"

enum class Locations;

Level::Level(Locations location,int* currentLevel, sf::RenderWindow* target)
{
    this->target = target;
    this->location = location;
    tileSize = 50;

    map = new Map(location, currentLevel, target);
    map->generateMap(22, 18, tileSize);

    
}

Level::~Level() {
    delete map;
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