#pragma once

class Inventory {
private:
    Player* player;
    sf::Font font;
    sf::Text inventoryText;
    std::vector<Item*> items;
    int selectedItemIndex;

public:
    Inventory(Player* player);
    void addItem(Item* items);
    void removeItem(int index);
    void removeItem(Item* item);
    void render(sf::RenderWindow* window);
};
