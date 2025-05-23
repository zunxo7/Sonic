#pragma once
#include "Scoreboard.h"
#include "Menu.h"
#include "Levels.h"
#include "CustomFont.h"
#include "SoundBoard.h"

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
    Music BgMusic;

    int ScreenWidht;
    int ScreenHeight;
    int GameState;
    int CurrentLevel;
    int Volume;
    bool MusicOn;

    Scoreboard MyScoreboard;
    SoundBoard MySoundBoard;
    Menu MyMenu;
    Levels** MyLevels;

public:
    Game(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles, TClass* Clock);
    ~Game();

    const bool running() const;
    const bool isGameOver() const;

    void pollEvents();
    void update();
    void Draw();
};

