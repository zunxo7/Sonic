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

class SoundBoard
{
	CustomFont font, font2, font3, font4;

	Texture MenuBackGroundTexture;
	Sprite MenuBackGroundSprite;
	Texture MenuForeGroundTexture;
	Sprite MenuForeGroundSprite;
	Texture MenuButtonTexture;
	Sprite MenuButtonSprite;

	Clock MenuClock;
	int CurrentChoice;
	int VolumeSelector;

public:
	SoundBoard();
	void Update(bool& MusicOn, int& Volume);
	void Draw(RenderWindow* window, int& Volume, bool& MusicOn);
};

