#include "stdafx.h"
#include "Level.h"


enum class Locations;

Level::Level(Game* game)
{
    //Take data from game
    this->player = game->player;
    this->currentLevel = &game->currentLevel;
    this->target = game->window;
    this->location = game->location;

	//Create map
    tileSize = 140;
    map = new Map(this);
    map->generateMap(30, 30, tileSize);

    //Item info
    coinValue = 10;

    //Add map items for level
    itemAmount = 2;
    addMapItems(itemAmount);

    //Generate items on map
	map->generateItems(mapItems);
    
	//Game process
    isActiveKey = false;
}

Level::~Level() {
    delete map;
}


//map->tiles[player->positionY / map->tileSize - 1][player->positionX / map->tileSize - 1].getGlobalBounds().getPosition().x / map->tileSize;
    void Level::update(float deltaTime) {
        float playerX = player->sprite.getPosition().x;
        float playerY = player->sprite.getPosition().y;

      input(deltaTime);


        // Move player
        sf::FloatRect playerBounds(playerX, playerY, player->sprite.getGlobalBounds().width, player->sprite.getGlobalBounds().height);

        if (player->controls == Controls::UP) {
            playerBounds.top -= player->velocity * deltaTime;
        }
        if (player->controls == Controls::DOWN) {
            playerBounds.top += player->velocity * deltaTime;
        }
        if (player->controls == Controls::LEFT) {
            playerBounds.left -= player->velocity * deltaTime;
        }
        if (player->controls == Controls:: RIGHT) {
            playerBounds.left += player->velocity * deltaTime;
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

    updatePlayerAnimation(deltaTime);
}

//Player controls
    void Level::input(float deltaTime) {
		if (!isActiveKey)
        {
            up = Keyboard::isKeyPressed(Keyboard::W);
            down = Keyboard::isKeyPressed(Keyboard::S);
            left = Keyboard::isKeyPressed(Keyboard::A);
            right = Keyboard::isKeyPressed(Keyboard::D);
        }

        player->controls = Controls::IDLE;
        if (up) {
            player->controls = Controls::UP;
            up = false;
        }
        else if (left) {
            player->controls = Controls::LEFT;
			left = false;
        }
        else if (right) {
            player->controls = Controls::RIGHT;
			right = false;
        }
        else if (down) {
            player->controls = Controls::DOWN;
			down = false;
        }

        if (up || left || right || down) {
            isActiveKey = true;
		}
		else {
			isActiveKey = false;
		}
        

        //VICTORY!!!
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

    //Heart
    heartTexture.loadFromFile("Images/Level/Items/Heart.png");
    Heart* heart = new Heart(heartTexture, 1);
    heart->sprite.setScale(1, 1);

    mapItems[1] = goldenCoin;

    // mapItems[0] = goldenCoin;
	////Key
	//Texture keyTexture;
	//keyTexture.loadFromFile("Images/Level/Items/Golden Key.png");
	//mapItems[1] = new Key(keyTexture);

}

void Level::updatePlayerAnimation(float deltaTime) {
    
    if(player->controls != Controls::IDLE){
        static int frameIndex = 0;
        static float animationTimer = 0.f;
        const float animationSpeed = 0.1f; // Fixed animation speed

        animationTimer += 0.01f; // Fixed time increment
        if (animationTimer >= animationSpeed) {
            frameIndex = (frameIndex + 1) % 8; // Assuming 3 frames in the animation
            animationTimer = 0.0f;
        }

        int startX = 0; // Starting x-coordinate of the animation frames
        int startY = 160; // Starting y-coordinate of the animation frames (4th line)
        int frameWidth = 32; // Width of each animation frame
        int frameHeight = 32; // Height of each animation frame

        player->texture.loadFromFile("Images/AnimationSheet_Character.png", IntRect(startX + frameIndex * frameWidth, startY, frameWidth, frameHeight));
        player->sprite.setTexture(player->texture);
        player->sprite.setScale(2.5f, 2.5f);

    }
    else {
        static int frameIndex = 0;
        static float animationTimer = 0.f;
        const float animationSpeed = 0.5f; // Fixed animation speed

        animationTimer += 0.01f; // Fixed time increment
        if (animationTimer >= animationSpeed) {
            frameIndex = (frameIndex + 1) % 2; // Assuming 3 frames in the animation
            animationTimer = 0.0f;
        }

        int startX = 0; // Starting x-coordinate of the animation frames
        int startY = 0; // Starting y-coordinate of the animation frames (4th line)
        int frameWidth = 32; // Width of each animation frame
        int frameHeight = 32; // Height of each animation frame

        player->texture.loadFromFile("Images/AnimationSheet_Character.png", IntRect(startX + frameIndex * frameWidth, startY, frameWidth, frameHeight));
        player->sprite.setTexture(player->texture);
        player->sprite.setScale(2.5f, 2.5f);
    }
        //...

        
}