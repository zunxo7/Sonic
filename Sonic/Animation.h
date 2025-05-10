#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class Animation
{
	int Direction; // 0 For Right, 1 For Left, 2 Same
	int Action[7]; // Stores Different Actions And Their Frames
	int CurrentFrame;
	int PreviousAction;
	int NextAction;
	int PreviousDirection;

public:
	Animation();

	void setActions(int Array[7]);
	void setAction(int Direc, int NextAct);
	void NextFrame(Sprite& ObjectSprite, Texture& ObjectTexture, int x, int y);

	int getDirection();

};

