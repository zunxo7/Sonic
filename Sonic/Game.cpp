#include "Game.h"

Game::Game(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles, TClass* Clock) : MyLevels(sonic, tails, knuckles, Clock), MyMenu() {
    ScreenWidht = 1200;
    ScreenHeight = 900;
    GameState = 0;
    window = new RenderWindow(VideoMode(ScreenWidht, ScreenHeight), "Sonic the Hedgehog-OOP", Style::Close);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(120);
}

Game::~Game() {
    delete window;
    window = nullptr;
}

const bool Game::running() const {
    return window->isOpen();
}

const bool Game::isGameOver() const {
    return false;
}

void Game::pollEvents() {
    while (window->pollEvent(event)) {
        switch (event.type) {
        case Event::Closed:
            window->close();
            break;
        case Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                GameState = 0;
            break;
        }
    }
}


void Game::update() {
    this->pollEvents();

    switch (GameState){
        case 0:
            MyMenu.Update(window, GameState, event);
        break;
        case 1:
            MyLevels.Update();

        break;
        case 2:


        break;
        case 3:


        break;
        case 4:
            MyScoreboard.Update(window);

        break;
    }
}

void Game::Draw() {


    switch (GameState) {
    case 1:
        MyLevels.Draw(window);

        break;
    case 2:


        break;
    case 3:


        break;
    case 4:
        MyScoreboard.Draw(window);

        break;
    }
}