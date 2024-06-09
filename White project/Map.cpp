#include "stdafx.h"
#include "Map.h"
#include "Game.h"

Map::Map(Locations location, int* currentLevel, RenderWindow *target)
{
	this->location = location;
	this->currentLevel = currentLevel;
	this->target = target;

	wallTexture.loadFromFile("Images/Map/Tiles/wall_2.png");
	wallSprite.setTexture(wallTexture);
	wallSprite.setScale(3.f, 3.f);

	emptyTexture.loadFromFile("Images/Map/Tiles/Floor.png", IntRect(0, 0, 20, 20));
	emptySprite.setTexture(emptyTexture);
	emptySprite.setScale(3.f, 3.f);

	secretTexture.loadFromFile("Images/Map/Items/Golden Key.png");
	secretSprite.setTexture(secretTexture);
	secretSprite.setScale(1.2f, 1.2f);

	lockTexture.loadFromFile("Images/Map/Tiles/door_closed.png");
	lockSprite.setTexture(lockTexture);
	lockSprite.setScale(1.5f, 1.5f);
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
			tiles[i][j] = wallSprite;
		}
	}

	//Lines
	int linia1X{};
	int linia2Y{};
	int linia3X{};

	//tworzenie drogi glownej
	linia1X = rand() % (height - 1);
	startX = linia1X;

	for (int i = 0; i < height; i++) {
		tiles[i][linia1X] = emptySprite;
	}

	//koncowa x
	endX = linia1X;

	//tworzenie drog bocznych
	int szerokosc_linii2{};
	linia2Y = rand() % (height - 2 - 2) + 2;
	if (linia1X <= width / 2) {
		for (int i = linia1X; i < width; i++) {
			tiles[linia2Y][i] = emptySprite;
			szerokosc_linii2++;
		}

		//tworzenie dodatkowych galedzi
		linia3X = rand() % (width - linia1X - 4) + linia1X + 4;
		if (linia2Y <= height / 2) {
			for (int i = linia2Y; i < height - 2; i++) {
				tiles[i][linia3X] = emptySprite;
				secretY = height - 3;
			}
		}
		if (linia2Y > height / 2) {
			for (int i = 2; i < linia2Y; i++) {
				tiles[i][linia3X] = emptySprite;
				secretY = 2;
			}
		}
	}
	else if (linia1X > width / 2) {
		for (int i = 0; i < linia1X; i++) {
			tiles[linia2Y][i] = emptySprite;
		}

		//tworzenie dodatkowych galedzi

		linia3X = rand() % (linia1X - 4 - 0);
		if (linia2Y <= height / 2) {
			for (int i = linia2Y; i < height - 2; i++) {
				tiles[i][linia3X] = emptySprite;
				secretY = height - 3;
			}
		}
		if (linia2Y > height / 2) {
			for (int i = 2; i < linia2Y; i++) {
				tiles[i][linia3X] = emptySprite;
				secretY = 2;
			}
		}
	}

	//Secret and lock
	secretX = linia3X;

	secretSprite.setPosition((1 + secretX) * tileSize, (1 + secretY) * tileSize);
	//tiles[secretY][secretX] = secret_icon;

	//koniec
	//tiles[endY][endX] = lock_icon;
	lockSprite.setPosition((1 + endX) * tileSize, 1);
}

void Map::render() {
	// Clear the window

	target->clear();
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			tiles[i][j].setPosition((1+ j) * tileSize, (1 + i) * tileSize);
			target->draw(tiles[i][j]);
		}
	}

	target->draw(secretSprite);
	target->draw(lockSprite);

	// Display the rendered frame
	target->display();
	//Test
}