#include "stdafx.h"
#include "Map.h"


Map::Map(Locations location, int* currentLevel, Player* player, RenderWindow *target)
{
	//Map
	this->location = location;
	this->currentLevel = currentLevel;
	this->player = player;
	this->target = target;

	tileScale = 12.f;

	wallTexture.loadFromFile("Images/Map/Tiles/wall_2.png");
	wallSprite.setTexture(wallTexture);
	wallSprite.setScale(tileScale, tileScale);

	emptyTexture.loadFromFile("Images/Map/Tiles/Floor.png", IntRect(0, 0, 20, 20));
	emptySprite.setTexture(emptyTexture);
	emptySprite.setScale(tileScale, tileScale);

	secretTexture.loadFromFile("Images/Map/Items/Golden Key.png");
	secretSprite.setTexture(secretTexture);
	secretSprite.setScale(5, 5);

	lockTexture.loadFromFile("Images/Map/Tiles/door_closed.png");
	lockSprite.setTexture(lockTexture);
	lockSprite.setScale(5, 5);

}

Map::~Map()
{
}

void Map::generateMap(int width, int height, int tileSize)
{
	this->width = width;
	this->height = height;
	this->tileSize = tileSize;

	tiles.clear();
	tiles.resize(height);

	startY = height - 2;

	for (int i = 0; i < height; i++) {
		if (i < tiles.size()) {
			tiles[i].resize(width);
		}
		else {
			std::cerr << "Error: Out of range access in tiles vector." << std::endl;
			break;
		}

		for (int j = 0; j < width; ++j) {
			// Initialize each tile here...
			tiles[i][j].sprite = wallSprite;
			tiles[i][j].wall = true;
		}
	}

	//Lines
	int linia1X{};
	int linia2Y{};
	int linia3X{};

	//tworzenie drogi glownej
	{
		linia1X = rand() % (height - 2) + 1;
		startX = linia1X;

		for (int i = 0; i < height; i++) {
			tiles[i][linia1X].sprite = emptySprite;
			tiles[i][linia1X].wall = false;
		}

		//koncowa x
		endX = linia1X;

		//tworzenie drog bocznych
		int szerokosc_linii2{};
		linia2Y = rand() % (height - 2 - 2) + 2;
		if (linia1X <= width / 2) {
			for (int i = linia1X; i < width; i++) {
				tiles[linia2Y][i].sprite = emptySprite;
				tiles[linia2Y][i].wall = false;
				szerokosc_linii2++;
			}

			//tworzenie dodatkowych galedzi
			linia3X = rand() % (width - linia1X - 5) + linia1X + 4;
			if (linia2Y <= height / 2) {
				for (int i = linia2Y; i < height - 2; i++) {
					tiles[i][linia3X].sprite = emptySprite;
					tiles[i][linia3X].wall = false;
					secretY = height - 3;
				}
			}
			if (linia2Y > height / 2) {
				for (int i = 2; i < linia2Y; i++) {
					tiles[i][linia3X].sprite = emptySprite;
					tiles[i][linia3X].wall = false;
					secretY = 2;
				}
			}
		}
		else if (linia1X > width / 2) {
			for (int i = 0; i < linia1X; i++) {
				tiles[linia2Y][i].sprite = emptySprite;
				tiles[linia2Y][i].wall = false;
			}

			//tworzenie dodatkowych galedzi

			linia3X = rand() % (linia1X - 6 - 0) + 1;
			if (linia2Y <= height / 2) {
				for (int i = linia2Y; i < height - 2; i++) {
					tiles[i][linia3X].sprite = emptySprite;
					tiles[i][linia3X].wall = false;
					secretY = height - 3;
				}
			}
			if (linia2Y > height / 2) {
				for (int i = 2; i < linia2Y; i++) {
					tiles[i][linia3X].sprite = emptySprite;
					tiles[i][linia3X].wall = false;
					secretY = 2;
				}
			}
		}


		//Secret and lock
		secretX = linia3X;

		secretSprite.setPosition(secretX * tileSize, secretY * tileSize);
		//tiles[secretY][secretX] = secret_icon;

		//koniec
		//tiles[endY][endX] = lock_icon;
		lockSprite.setPosition(endX * tileSize, 0);

		player->setPosition(startX * tileSize, startY * tileSize);

		//TEST

		player->positionXTile = startX;
		player->positionYTile = startY;
	}
}

void Map::render() {
	// Clear the window

	
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			tiles[i][j].sprite.setPosition(j * tileSize, i * tileSize);
			target->draw(tiles[i][j].sprite);
		}
	}

	target->draw(secretSprite);
	target->draw(lockSprite);

	// Display the rendered frame
	//Test
}