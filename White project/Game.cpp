#include "stdafx.h"

#include "Game.h"
// Game class implementation

// Initialization
void Game::initVariables() {
    isMenuActive = true;
    
}


void Game::initWindow() {
    // Create window
    videomode.height = 1000;
    videomode.width = 1200;
    window = new RenderWindow(videomode, "Simple game", Style::Titlebar | Style::Close);
}

// Constructor
Game::Game() {
    // Initialization
    initWindow();
    initVariables();
}

// Destructor
Game::~Game() {
    delete level; // Remove later
    delete player;
    delete window;
}

// Accessors
const bool Game::running() const {
    return window->isOpen();
}

// Functions

// Check for events and basic input
void Game::pollEvents() {
    // Event polling
    while (window->pollEvent(event)) {
        switch (event.type) {
            // Close window
        case Event::Closed:
            window->close();
            break;

        case Event::KeyPressed:
            // Game pause
            if (event.key.code == Keyboard::Escape) {
                pause = !pause;
            }

            // Editor mode
            if (event.key.code == Keyboard::K) {
                editorMode = !editorMode;
            }

            if (event.key.code == Keyboard::Q) {
                startGame();
            break;
            }
        }
    }
}

// Update game
void Game::update(float dt) {
    // SFML events
    pollEvents();

    // Update game objects
    if (!pause) {
        // Update player
        player->update();

        // Update the view's center
        view.setCenter(player->positionX, player->positionY);

        // Update travel mode
        switch (gameMode) {
        case GameModes::TRAVEL:
            level->update(dt);
            break;
        }
    }

    // Set editor mode - TEST!!!!!!!!!!!!!!
    if (editorMode) {
        view.setSize(window->getSize().x * 8, window->getSize().y * 8);
        player->velocity = 1000.f;
    }
    else {
        view.setSize(window->getSize().x, window->getSize().y);
        player->velocity = 400.f;
    }
}

// Render
void Game::render() {
    window->clear();

    // Set view
    window->setView(view);

    // Render game
    level->renderLevel();

    // Display the rendered frame
    window->display();
}

// void Game::gameProcess()
// {
//     if()
// }

void Game::run() {

    menu = new Menu(this);

    while (window->isOpen()) {
        dt = clock.restart().asSeconds();

        if (isMenuActive) {
            
            menu->update(dt);
            menu->render();
        }
        else {
            update(dt);
            render();
        }
    }

    delete menu;
}

void Game::startGame() {
    isMenuActive = false;
    // Initialize the game
    //...
    // Initialize music
    music.openFromFile("Music/Pixel 5.ogg");
    //music.play(); //Add music later
    //music.setLoop(true);

    // Initialize player
    playerTexture.loadFromFile("Images/AnimationSheet_Character.png", IntRect(0, 0, 32, 32));
    player = new Player(this, "Knight", playerTexture);

    // Initialize the view with the window's size
    view.setSize(window->getSize().x, window->getSize().y);
    view.setCenter(player->positionX, player->positionY);

    // Initialize game mode
    gameMode = GameModes::TRAVEL;
    pause = false;

    // Initialize location
    location = Locations::CASTLE_HALL;

    // Initialize level
    currentLevel = 1;
    level = new Level(this);

    // Set player to level
    // level->setPlayer(player);
}

void Game::exitGame() {
    window->close();
}