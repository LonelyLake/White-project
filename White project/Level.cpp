#include "stdafx.h"
#include "Level.h"

enum class Locations;

Level::Level(Locations location,int* currentLevel, sf::RenderWindow* target)
{
    this->target = target;
    this->location = location;

    map = new Map(location, currentLevel, target);
    map->generateMap(22, 18, 50);


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
    target->clear();

    // Render the map
    map->render();

    // Display the rendered frame
    target->display();
}