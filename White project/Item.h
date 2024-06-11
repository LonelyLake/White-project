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
	int value = NULL;

	//Constructor
	Item();
	Item(Texture texture);

	//Copy constructor
	Item(const Item& sItem);
		
	//Destructor
	~Item();
};

