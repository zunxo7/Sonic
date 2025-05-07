#include "Levels.h"

Levels::Levels(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles) : CharactersSize(3), Characters(new CharacterFactory*[3]) {

	wallTex1.loadFromFile("Data/brick1.png");
	wallSprite1.setTexture(wallTex1);

	CellSize = 64;
	CurrentLevel = 1;

	Characters[0] = sonic;
	Characters[1] = tails;
	Characters[2] = knuckles;
	CurrentPlayer = 0; // Sonic

	switch (CurrentLevel) {
	case 1:
		MaxWidht = 200;
		break;
	case 2:
		MaxWidht = 250;
		break;
	case 3:
		MaxWidht = 300;
		break;
	case 4:
		MaxWidht = 19;
		break;
	}
	LvlGrid = new char* [14];
	for (int i = 0; i < 14; ++i) {
		LvlGrid[i] = new char[MaxWidht];
	}

	for (int i = 0; i < MaxWidht;i++) {
		for (int j = 0; j < 14;j++) {
			if (j == 13 || j == 0 || i == 0 || i == MaxWidht -1) {
				LvlGrid[j][i] = 'w';
			}
			else {
				LvlGrid[j][i] = 's';
			}
		}
	}
}

Levels::~Levels() {
	for (int i = 0; i < 14; ++i) {
		delete [] LvlGrid[i];
	}
	delete[] LvlGrid;
	LvlGrid = nullptr;
}

void Levels::Update() {
	if (PlayerClock.getElapsedTime().asMilliseconds() >= 25) {
		PlayerClock.restart();
		for (int i = 0; i < CharactersSize;i++) { // Characters
			Characters[i]->ApplyGravity(LvlGrid,CellSize);
			if (i == CurrentPlayer) {
				Characters[i]->PlayerMove(LvlGrid, CellSize,MaxWidht);
			}
			else {
				Characters[i]->MoveTo(LvlGrid, CellSize, Characters[CurrentPlayer]->getXPosition());
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			for (int i = 0; i < CharactersSize;i++) {
				Characters[i]->Jump(LvlGrid, CellSize);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Z) && SwitchClock.getElapsedTime().asSeconds() > 1) {
				SwitchClock.restart();
			
				CurrentPlayer++;

				if (CurrentPlayer >= 3) {
					CurrentPlayer = 0;
				}
				
			
		}

		for (int i = 0; i < CharactersSize;i++) { // Characters Update
			Characters[i]->Update();
		}
	}
}

void Levels::Draw(RenderWindow* window) {

	for (int i = 0; i < 14; i += 1) // Grid Items
	{
		for (int j = 0; j < MaxWidht; j += 1)
		{
			if (LvlGrid[i][j] == 'w')
			{
				wallSprite1.setPosition(j * CellSize - Characters[CurrentPlayer]->getXPosition(), i * CellSize);
				window->draw(wallSprite1);
			}
		}
	}

	for (int i = 0; i < CharactersSize;i++) { // Characters
		Characters[i]->DrawMoveable(window, Characters[CurrentPlayer]->getXPosition());
	}

}
