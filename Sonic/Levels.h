#pragma once
#include "CharacterFactory.h"
#include "Collectiables.h"

class Levels
{

	char** LvlGrid;
	float CellSize;
	int CurrentLevel;
	int MaxWidht;

	Texture wallTex1;
	Sprite wallSprite1;

	int CollectiablesSize;
	Collectiables** PtrCollectiables;

	const int CharactersSize;
	CharacterFactory** Characters;
	int CurrentPlayer;
	Clock PlayerClock;
	Clock SwitchClock;

public:
	Levels(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles);
	~Levels();

	void Update();
	void Draw(RenderWindow* window);
};

