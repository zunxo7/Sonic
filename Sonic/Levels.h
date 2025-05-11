#pragma once
#include "CharacterFactory.h"
#include "Collectiables.h"

class Levels
{

	char** LvlGrid;
	float CellSize;
	int CurrentLevel;
	int MaxWidht;
	bool AbilityUsed;

	Font SonicFont;
	Text ScoreText;
	Text RingText;
	Text HpText;

	Texture levelBackGroundTexture;
	Sprite levelBackGroundSprite;
	Texture wallTex1;
	Texture wallTex2;
	Texture wallTex3;
	Texture wallTex4;
	Texture wallTex5;
	Sprite wallSprite;
	Texture Crystal1UTex;
	Texture Crystal1DTex;
	Texture Crystal2UTex;
	Texture Crystal2DTex;
	Sprite CrystalSprite;
	Texture spikeTex;
	Sprite spikeSprite;
	Texture ringTex;
	Sprite ringSprite;
	Texture LivesTex;
	Sprite LivesSprite;
	int CurrentRing;

	int CollectiablesSize;
	Collectiables** PtrCollectiables;

	const int CharactersSize;
	CharacterFactory** Characters;
	int CurrentPlayer;
	Clock PlayerClock;
	Clock SwitchClock;
	Clock AnimationClock1;
	Clock AnimationClock2;
	Clock RingClock;
	Clock AbilityClock;

public:
	Levels(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles);
	~Levels();

	void Update();
	void Draw(RenderWindow* window);
};

