#include "Game.h"

Game::Game(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles): MyLevels(sonic, tails, knuckles) {
    ScreenWidht = 1200;
    ScreenHeight = 900;
    window = new RenderWindow(VideoMode(ScreenWidht, ScreenHeight), "Sonic the Hedgehog-OOP", Style::Close);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);

    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << std::endl;
    }
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
                window->close();
            break;
        }
    }
}



void Game::update() {
    this->pollEvents();
    MyLevels.Update();
}

void Game::Draw() {

    this->window->clear();

    MyLevels.Draw(window);

    this->window->display();
}