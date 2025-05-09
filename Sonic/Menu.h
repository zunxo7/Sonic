#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class Menu
{
	int CurrentChoice;

	Texture MenuBackGroundTexture;
	Sprite MenuBackGroundSprite;
	Texture MenuForeGroundTexture;
	Sprite MenuForeGroundSprite;
	Texture MenuButtonTexture1;
	Texture MenuButtonTexture2;
	Sprite MenuButtonSprite;

	Clock MenuClock;
	Clock MenuDisplayClock;
	int BackgroundFrame;

public:
	Menu();
	void Update(RenderWindow* window, int& GameState, Event event);
	void Draw(RenderWindow* window);
};

