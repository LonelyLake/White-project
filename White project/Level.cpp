#include "stdafx.h"
#include "Level.h"


enum class Locations;

Level::Level(Locations location,int* currentLevel, Player* player, sf::RenderWindow* target)
{
    this->currentLevel = currentLevel;
    this->target = target;
    this->player = player;
    this->location = location;
    tileSize = 140;

	//Create map
    map = new Map(location, currentLevel, player, target);
    map->generateMap(30, 30, tileSize);

    //Item info
    coinValue = 10;

    //Add map items for level
    addMapItems(10);
    //Generate items on map

    cout << &mapItems << endl;
	map->generateItems(mapItems);
    
}

Level::~Level() {
    delete map;
}


//map->tiles[player->positionY / map->tileSize - 1][player->positionX / map->tileSize - 1].getGlobalBounds().getPosition().x / map->tileSize;
void Level::update(float deltaTime) {
    float playerX = player->sprite.getPosition().x;
    float playerY = player->sprite.getPosition().y;

    input();

    //Move player
    sf::FloatRect playerBounds(playerX, playerY, player->sprite.getGlobalBounds().width, player->sprite.getGlobalBounds().height);

    switch (player->controls) {
    case Controls::UP:
        playerBounds.top -= player->velocity * deltaTime;
        break;

    case Controls::DOWN:
        playerBounds.top += player->velocity * deltaTime;
        break;

    case Controls::LEFT:
        playerBounds.left -= player->velocity * deltaTime;
        break;

    case Controls::RIGHT:
        playerBounds.left += player->velocity * deltaTime;
        break;

    default:
        player->controls = Controls::IDLE;
        break;
    }

    // Check for collisions with walls
    for (int y = playerBounds.top / map->tileSize; y <= (playerBounds.top + playerBounds.height) / map->tileSize; ++y) {
        for (int x = playerBounds.left / map->tileSize; x <= (playerBounds.left + playerBounds.width) / map->tileSize; ++x) {
            if (map->tiles[y][x].wall && playerBounds.intersects(map->tiles[y][x].sprite.getGlobalBounds())) {
                // Handle collision with wall
                // Move the player back to the previous position
                switch (player->controls) {
                case Controls::UP:
                    playerBounds.top += player->velocity * deltaTime;
                    break;

                case Controls::DOWN:
                    playerBounds.top -= player->velocity * deltaTime;
                    break;

                case Controls::LEFT:
                    playerBounds.left += player->velocity * deltaTime;
                    break;

                case Controls::RIGHT:
                    playerBounds.left -= player->velocity * deltaTime;
                    break;

                default:
                    break;
                }
                break;
            }
        }
    }

    // Prevent the player from moving into the first and last lines of the map
    if (playerBounds.top < map->tileSize || playerBounds.top + playerBounds.height > map->height * map->tileSize - map->tileSize) {
        playerBounds.top = clamp(playerBounds.top, static_cast<float>(map->tileSize), static_cast<float>(map->height * map->tileSize - player->sprite.getGlobalBounds().height - map->tileSize));
    }

    if (playerBounds.left < map->tileSize || playerBounds.left + playerBounds.width > map->width * map->tileSize - map->tileSize) {
        playerBounds.left = clamp(playerBounds.left, static_cast<float>(map->tileSize), static_cast<float>(map->width * map->tileSize - player->sprite.getGlobalBounds().width - map->tileSize));
    }

    player->sprite.setPosition(playerBounds.left, playerBounds.top);
    player->positionX = playerBounds.left;
    player->positionY = playerBounds.top;
    player->positionXTile = static_cast<int>(playerBounds.left) / map->tileSize;
    player->positionYTile = static_cast<int>(playerBounds.top) / map->tileSize;
}

//Player controls
void Level::input() {
	player->controls = Controls::IDLE;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player->controls = Controls::UP;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player->controls = Controls::DOWN;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player->controls = Controls::LEFT;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
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

void Level::addMapItems(int itemAmount) {
    mapItems.resize(itemAmount);
    
    //Coin
	 //???
	coinTexture.loadFromFile("Images/Level/Items/Golden Coin.png");
    Coin* goldenCoin = new Coin(coinTexture, coinValue);
    goldenCoin->sprite.setScale(1, 1);

    mapItems[0] = goldenCoin;


    // mapItems[0] = goldenCoin;
	////Key
	//Texture keyTexture;
	//keyTexture.loadFromFile("Images/Level/Items/Golden Key.png");
	//mapItems[1] = new Key(keyTexture);

}