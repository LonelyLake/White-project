#pragma once


class Item
{
public:
	//Position
	int positionX;
	int positionY;

	//Look
	Texture texture;
	Sprite sprite;

	//
	bool isOnMap;

	//Parameters
	int value;

	//Constructor
	Item();
	Item(Texture texture);

	//Copy constructor
	Item(const Item& sItem);

	//Destructor
	virtual ~Item();

	virtual void takeItem(Player* player) = 0;
};

