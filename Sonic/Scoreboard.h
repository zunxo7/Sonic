#pragma once

#include <SFML/Graphics.hpp>
#include "CustomFont.h"

using namespace sf;
using namespace std;

class Scoreboard {
	bool DataDisplay;
	string Name;
	string ScoreString;
	Texture MenuForeGroundTexture;
	Sprite MenuForeGroundSprite;
	CustomFont font;
	Texture BackGroundTexture;
	Sprite BackGroundSprite;
public:
	Scoreboard();
	void Update(RenderWindow* window);
	void Draw(RenderWindow* window);
};
