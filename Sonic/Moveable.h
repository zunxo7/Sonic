#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"

using namespace sf;
using namespace std;

class Moveable
{
protected:
	Texture ObjectTexture;
	Sprite ObjectSprite;
	float XPosition;
	float YPosition;
	float XSpeed;
	float YSpeed;

	int HitBoxX;
	int HitBoxY;
	float Scale;

public:
	Animation ObjectAnimation;

	Moveable();
	virtual ~Moveable();

	void DrawMoveable(RenderWindow* window, float PlayerX);


};

