#include "stdafx.h"
#include "Fight.h"
#include "Player.h"
#include "Enemy.h"

void Fight::startFight()
{
    while (player->health > 0 && enemy->health > 0) {
        playerTurn();
        if (enemy->health > 0) {
            enemyTurn();
        }
    }
    if (player->health > 0) {
        cout << "Player wins!" << endl;
    }
    else {
        cout << "Enemy wins!" << endl;
    }
}

void Fight::playerTurn()
{
    cout << "Player's turn:" << endl;
    int choice;
    cout << "1. Attack" << endl;
    cout << "2. Block" << endl;
    cout << "3. Special Attack" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        player->attack(enemy);
        break;
    case 2:
        player->block();
        break;
    case 3:
        player->specialAttack(enemy);
        break;
    default:
        cout << "Invalid choice." << endl;
    }
}

void Fight::enemyTurn()
{
    cout << "Enemy's turn:" << endl;
    int choice = rand() % 3; // random choice
    switch (choice) {
    case 0:
        enemy->attack(player);
        break;
    case 1:
        enemy->block();
        break;
    case 2:
        if (true/*player->canSeeSpecialAttack()*/) {
            cout << "Enemy is preparing a special attack!" << endl;
            enemy->specialAttack(player);
        }
        else {
            enemy->attack(player);
        }
        break;
    }
}