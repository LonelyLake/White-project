#include "stdafx.h"

#include "Menu.h"

Menu::Menu(Game* game) {
    this->game = game;

    font.loadFromFile("Fonts/LoversQuarrel-Regular.ttf");

    titleText.setFont(font);
    titleText.setString("My Game");
    titleText.setCharacterSize(100);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(game->window->getSize().x / 2 - titleText.getGlobalBounds().width / 2, 100);

    startGameText.setFont(font);
    startGameText.setString("Start Game");
    startGameText.setCharacterSize(60);
    startGameText.setFillColor(sf::Color::White);
    startGameText.setPosition(game->window->getSize().x / 2 - startGameText.getGlobalBounds().width / 2, 300);

    exitGameText.setFont(font);
    exitGameText.setString("Exit Game");
    exitGameText.setCharacterSize(60);
    exitGameText.setFillColor(sf::Color::White);
    exitGameText.setPosition(game->window->getSize().x / 2 - exitGameText.getGlobalBounds().width / 2, 400);

    selectedOption = 0;
}

Menu::~Menu() {
}

void Menu::update(float deltaTime) {
    game->pollEvents();

    if (Keyboard::isKeyPressed(Keyboard::Up) && selectedOption > 0) {
        selectedOption--;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down) && selectedOption < 1) {
        selectedOption++;
    }

    switch (selectedOption) {
    case 0:
        startGameText.setFillColor(sf::Color::Yellow);
        exitGameText.setFillColor(sf::Color::White);
        break;
    case 1:
        startGameText.setFillColor(sf::Color::White);
        exitGameText.setFillColor(sf::Color::Yellow);
        break;
    }

    if (Keyboard::isKeyPressed(Keyboard::Enter)) {
        if (selectedOption == 0) {
            game->startGame();
        }
        else if (selectedOption == 1) {
            game->exitGame();
        }
    }
}

void Menu::render() {
    game->window->clear();

    game->window->draw(titleText);
    game->window->draw(startGameText);
    game->window->draw(exitGameText);

    game->window->display();
}
