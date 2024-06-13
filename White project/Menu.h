#pragma once
#include "Game.h"

class Menu {


private:
    Game* game;
    sf::Font font;
    sf::Text titleText;
    sf::Text startGameText;
    sf::Text exitGameText;
    int selectedOption;

public:
    Menu(Game* game);
    ~Menu();

    void update(float deltaTime);
    void render();
};