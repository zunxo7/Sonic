#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;


class Scoreboard
{
	bool DataDisplay;
	String Name;
	String ScoreString;

	Font ScoreFont;
	Text HSNamesText;
	Text HSScoreText;
	Text HighScoreTitle;

public:
	Scoreboard();
	void Update(RenderWindow* window);
	void Draw(RenderWindow* window);
};

