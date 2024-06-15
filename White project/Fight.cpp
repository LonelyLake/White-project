#include "stdafx.h"
#include "Fight.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"

Fight::Fight(Level* level, Player* player, Enemy* enemy, int maxTurns)
{
    this->window = level->target;

	this->level = level;
    this->player = player;
	this->enemy = enemy;
    this->maxTurns = maxTurns;
}

void Fight::startFight()
{
    playerTexture = player->texture;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(100, 100);

    enemyTexture = enemy->texture;
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(300, 100);

    font.loadFromFile("Fonts/Garton.ttf");

    playerHealthText.setFont(font);
    playerHealthText.setCharacterSize(24);
    playerHealthText.setPosition(100, 50);

    enemyHealthText.setFont(font);
    enemyHealthText.setCharacterSize(24);
    enemyHealthText.setPosition(300, 50);

    playerHealthText.setString("Player Health: " + std::to_string(player->health));
    enemyHealthText.setString("Enemy Health: " + std::to_string(enemy->health));

    actionText.setFont(font);
	actionText.setCharacterSize(24);
	actionText.setPosition(50, 260);
    actionText.setFillColor(Color::Red);
    actionText.setString("Choose an action: 1. Attack, 2. Block, 3. Special Attack");

    winText.setFont(font);
    winText.setCharacterSize(48);
    winText.setPosition(200, 200);

    loseText.setFont(font);
    loseText.setCharacterSize(48);
    loseText.setPosition(200, 200);

    Clock clock;

    /*int turnCount = 0;
    while (player->health > 0 && enemy->health > 0 && 0 && turnCount < maxTurns) {
        sf::Time elapsed = clock.restart();
        update();
        level->target->clear();
        render(level->target);
        sf::sleep(sf::seconds(1.0f / 60.0f) - elapsed);

        turnCount++;
    }*/
}

void Fight::playerTurn() {
    sf::Event event;

    while (true) {
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    player->attack(enemy);

                    actionText.setString("Player attacks");
                    render(window); // Update the actionText
                    window->display(); // Update the window to display the changes

                    return;
                }
                else if (event.key.code == sf::Keyboard::Num2) {
                    player->block();

                    actionText.setString("Player blocks");
                    render(window); // Update the actionText
                    window->display(); // Update the window to display the changes

                    return;
                }
                else if (event.key.code == sf::Keyboard::Num3) {
                    player->specialAttack(enemy);

                    actionText.setString("Player uses special attack");
                    render(window); // Update the actionText
                    window->display(); // Update the window to display the changes

                    return;
                }
            }
        }

        render(window); // Render the actionText
        window->display(); // Update the window to display the changes
    }
}

void Fight::enemyTurn() {
    playerTurnActive = false;

    int choice = rand() % 3; // random choice
    switch (choice) {
    case 0:
        enemy->attack(player);
        //sf::sleep(sf::seconds(2)); // add 2-second delay

        actionText.setString("Enemy attacks");
        render(window); // Update the actionText
        window->display(); // Update the window to display the changes

        break;
    case 1:
        enemy->block();
        //sf::sleep(sf::seconds(2)); // add 2-second delay

        actionText.setString("Enemy blocks");
        render(window); // Update the actionText
        window->display(); // Update the window to display the changes

        break;
    case 2:
        if (!enemyPrepareSpecialAttack) {
            cout << "Enemy prepares special attack!" << endl;
            enemy->specialAttack(player);
            enemyPrepareSpecialAttack = true;

            actionText.setString("Enemy prepares special attack!");
            render(window); // Update the actionText
            window->display(); // Update the window to display the changes

        }
        else if (enemyPrepareSpecialAttack) {
            cout << "Enemy uses special attack!" << endl;
            enemy->specialAttack(player);
            enemyPrepareSpecialAttack = true;

            actionText.setString("Enemy uses special attack!");
            render(window); // Update the actionText
            window->display(); // Update the window to display the changes

        }
        else {
            enemy->attack(player);

            actionText.setString("Enemy attack!");
            render(window); // Update the actionText
            window->display(); // Update the window to display the changes

        }

        break;
    }
}

void Fight::update()
{
    if (player->health <= 0) {
        // The fight is over, so we can exit the loop
        cout << "Fight is over!" << endl;
        playerLost = true;
    }
    else if (enemy->health <= 0) {
        // The fight is over, so we can exit the loop
        cout << "Fight is over!" << endl;
        playerWon = true;

        enemy->isDead = true;
        delete enemy;
        level->fightStarted = false;
    }

    if (playerTurnActive) {
        actionText.setString("Choose an action: 1. Attack, 2. Block, 3. Special Attack");
    }
    else {
        actionText.setString("");
    }

    playerTurn();

    if (enemy->health > 0) {
        enemyTurn();
    }

    playerHealthText.setString("Player Health: " + std::to_string(player->health));
    enemyHealthText.setString("Enemy Health: " + std::to_string(enemy->health));

    render(window); // Render the action text and other elements
    window->display(); // Display the rendered frame
}


    void Fight::render(sf::RenderWindow* window)
    {
        window->clear(Color::Black);
        window->draw(playerSprite);
        window->draw(enemySprite);
        window->draw(playerHealthText);
        window->draw(enemyHealthText);

        window->draw(actionText);

        if (player->health > 0 && enemy->health > 0) {
            sf::Text statusText;
            statusText.setFont(font);
            statusText.setCharacterSize(24);
            statusText.setPosition(200, 300);
            if (player->blockDamage) {
                statusText.setString("Player is blocking");
            }
            else {
                statusText.setString("Player's turn");
            }
            window->draw(statusText);
        }
        else if (player->health > 0) {
            window->draw(winText);
        }
        else {
            window->draw(loseText);
        }
    }