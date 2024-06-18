#pragma once

class Inventory {
private:
    Player* player;

    RectangleShape background;

    sf::Font font;
    Text titleText;
    sf::Text inventoryText;

    std::vector<Item*> items;
    int selectedItemIndex;

    //Upgrade menu text
    RectangleShape backgroundUpgrade;
	Text upgradeTitleText;
    bool isUpgraded;

    Text increaseMaxHealth;
    Text increaseShield;
    Text increaseEnergy;

public:
    Inventory(Player* player);
    void addItem(Item* items);
    void removeItem(int index);
    void removeItem(Item* item);
    void render(sf::RenderWindow* window);

    void upgrade();
};
