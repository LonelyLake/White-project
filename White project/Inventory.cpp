#include "stdafx.h"
#include "Player.h"
#include "Inventory.h"
#include "Item.h"
#include "Key.h"

Inventory::Inventory(Player* player) {
    this->player = player;
    font.loadFromFile("Fonts/PrincessSofia-Regular.ttf");
    inventoryText.setFont(font);
    inventoryText.setPosition(sf::Vector2f(100, 100));
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
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == item) {
            if (Key* key = dynamic_cast<Key*>(*it)) {
                // Remove the item from the inventory
                items.erase(it--);
                key->takeItem(player);
                cout << player->hasKey << endl;
                // delete key; // only delete if key is dynamically allocated
                return;
            }
            else {
                // Remove the item from the inventory
                items.erase(it--);
                return;
            }
        }
    }
    }
void Inventory::render(sf::RenderWindow* window) {
    window->clear(Color::Yellow);
    std::string inventoryString;
    for (size_t i = 0; i < items.size(); ++i) {
        if (i == selectedItemIndex) {
            inventoryString += "> ";
        }
        inventoryString += typeid(items[i]).name();
        inventoryString += "\n";
    }
    inventoryText.setString(inventoryString);
    window->draw(inventoryText);
}