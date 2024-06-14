#include "stdafx.h"
#include "Player.h"
#include "Inventory.h"
#include "Item.h"
#include "Key.h"

Inventory::Inventory(Player* player) {
    this->player = player;

    background = sf::RectangleShape(sf::Vector2f(800, 1000));
	background.setFillColor(sf::Color(12, 32, 122, 150));

    font.loadFromFile("Fonts/Garton.ttf");
    titleText.setFont(font);
    titleText.setString("Inventory");
	titleText.setScale(2.f, 2.f);

    inventoryText.setFont(font);
    inventoryText.setPosition(sf::Vector2f(500, 100));
    inventoryText.setScale(2.f, 2.f);

    selectedItemIndex = 0;
}

void Inventory::addItem(Item* item) {
    items.push_back(std::move(item));
}

void Inventory::removeItem(int index) {
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
    }
}

void Inventory::removeItem(Item* item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
    }
}
void Inventory::render(sf::RenderWindow* window) {

    std::string inventoryString;
    for (size_t i = 0; i < items.size(); ++i) {
        if (i == selectedItemIndex) {
            inventoryString += "> ";
            inventoryString += items[i]->name + "\n";
        }
    }
    inventoryText.setString(inventoryString);

    background.setPosition(player->positionX - 400, player->positionY - 600);
    titleText.setPosition(player->positionX - 100, player->positionY - 400);
    inventoryText.setPosition(player->positionX - 100, player->positionY - 300);

    window->draw(background);
    window->draw(titleText);
    window->draw(inventoryText);
}