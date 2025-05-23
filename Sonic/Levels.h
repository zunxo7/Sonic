#pragma once
#include "CharacterFactory.h"
#include "EnemyFactory.h"
#include "CustomFont.h"
#include "Time.h"

class Levels
{

	char** LvlGrid;
	float CellSize;
	int MaxWidht;
	bool AbilityUsed;
	bool FirstSpawn;
	TClass * GrandClock;

	CustomFont font;
	Font ScoreFont;

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
	Texture SignPostTex;
	Sprite SignPostSprite;
	Texture BoostTex;
	Sprite BoostSprite;
	Texture HPBoostTex;
	Sprite HPBoostSprite;
	int CurrentRing;
	int CurrentSign;

	const int CharactersSize;
	CharacterFactory** Characters;
	int CurrentPlayer;

	int EnemyNum;
	EnemyFactory** Enemies;

	const int MaxChars;
	char* NameArray;

	int CurrentIndex;
	string Name;
	string ScoreString;
	bool NameCompelete;
	bool DataStore;
	bool DataDisplay;
	bool isScoreStored;
	Text DisplayName;
	Text HSNamesText;
	Text HSScoreText;
	Text HighScoreTitle;
	Text GameOver;
	Text ScoreBoard;

public:
	Levels(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles, TClass* MyClock, int CurrentLevel);
	~Levels();

	void Update(int& CurrentLevel, Music& lvlMus, int Volume, bool MusicOn);
	void Draw(RenderWindow* window);
	void GameOverDraw(RenderWindow* window);
};

