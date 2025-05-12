#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "CustomFont.h"

using namespace sf;
using namespace std;

class Menu
{
	int CurrentChoice;
	CustomFont font, font2, font3, font4;

	Texture MenuBackGroundTexture;
	Sprite MenuBackGroundSprite;
	Texture MenuForeGroundTexture;
	Sprite MenuForeGroundSprite;
	Texture MenuButtonTexture;
	Sprite MenuButtonSprite;
	Texture LogoTexture;
	Sprite LogoSprite; 
	
	SoundBuffer MenuBuffer;
	Sound MenuSound;

	Clock MenuClock;
	Clock MenuDisplayClock;
	int BackgroundFrame;

public:
	Menu();
	void Update(RenderWindow* window, int& GameState, Event event);
	void Draw(RenderWindow* window);
};

