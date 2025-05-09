#pragma once
#include "Scoreboard.h"
#include "Menu.h"
#include "Levels.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Game {
private:
    RenderWindow* window;
    Event event;
    Font font;

    int ScreenWidht;
    int ScreenHeight;
    int GameState;

    Scoreboard MyScoreboard;
    Menu MyMenu;
    Levels MyLevels;

public:
    Game(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles);
    ~Game();

    const bool running() const;
    const bool isGameOver() const;

    void pollEvents();
    void update();
    void Draw();

};

