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
	int Direction; // 0 For Right, 1 For Left
	int Action[7]; // Stores Different Actions And Their Frames
	int CurrentFrame;
	int PreviousAction;

public:
	Animation();

	void setActions(int Array[7]);
	void NextFrame(Sprite ObjectSprite, Texture ObjectTexture, float Scale, int Direc, int NextAct);

};

