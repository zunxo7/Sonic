#include "Game.h"

Game::Game(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles, TClass* Clock) : MyMenu() {
    ScreenWidht = 1200;
    ScreenHeight = 900;
    GameState = 0;
    window = new RenderWindow(VideoMode(ScreenWidht, ScreenHeight), "Sonic the Hedgehog-OOP", Style::Close);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(120);
    CurrentLevel = 3;

    MyLevels = new Levels*[4];

    MyLevels[0] = new Levels(sonic, tails, knuckles, Clock, 1);
    MyLevels[1] = new Levels(sonic, tails, knuckles, Clock, 2);
    MyLevels[2] = new Levels(sonic, tails, knuckles, Clock, 3);
    MyLevels[3] = new Levels(sonic, tails, knuckles, Clock, 4);

    BgMusic.openFromFile("Data/Sounds/labrynth.ogg");
    BgMusic.setVolume(30);
    BgMusic.play();
    BgMusic.setLoop(true);

    Volume = 30;
    MusicOn = true;
}

Game::~Game() {
    delete window;
    window = nullptr;
    delete[] MyLevels;
    MyLevels = nullptr;
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
            MyLevels[CurrentLevel - 1]->Update(CurrentLevel, BgMusic, Volume, MusicOn);

        break;
        case 2:
            MySoundBoard.Update(MusicOn,Volume);

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
        MyLevels[CurrentLevel - 1]->Draw(window);

        break;
    case 2:
        MySoundBoard.Draw(window, Volume);

        break;
    case 3:


        break;
    case 4:
        MyScoreboard.Draw(window);

        break;
    }
}