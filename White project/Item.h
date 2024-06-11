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

	//Constructor
	Item(Texture texture);

	//Destructor
	~Item();
};

