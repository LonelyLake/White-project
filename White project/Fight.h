#pragma once

class Fight {
public:
    Fight(Player* player, Enemy* enemy) : player(player), enemy(enemy) {}

    void startFight();

private:
    void playerTurn();

    void enemyTurn();

    Player* player;
    Enemy* enemy;
};