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

public:
	void Update(bool& MusicOn, int& Volume);
	void Draw(RenderWindow* window);
};

