#include "Levels.h"

Levels::Levels(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles) : CharactersSize(3), Characters(new CharacterFactory*[3]) {

	wallTex1.loadFromFile("Data/brick1.png");
	wallSprite1.setTexture(wallTex1);
	spikeTex.loadFromFile("Data/spike.png");
	spikeSprite.setTexture(spikeTex);
	ringTex.loadFromFile("Data/ring.png");
	ringSprite.setTexture(ringTex);
	ringSprite.setScale(3, 3);
	CurrentRing = 0;

	CellSize = 64;
	CurrentLevel = 1;

	Characters[0] = sonic;
	Characters[1] = tails;
	Characters[2] = knuckles;
	CurrentPlayer = 0; // Sonic

	switch (CurrentLevel) {
	case 1:

		levelBackGroundTexture.loadFromFile("Data/bg1.png");
		levelBackGroundSprite.setTexture(levelBackGroundTexture);

		MaxWidht = 200;
		char soniclevel[14][201] = {
			"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
			"w                                                                                                                                                                                                      w",
			"w                                                                             ooo                                                                                                                      w",
			"w                                                                             www                                                                                                                      w",
			"w                                                                                        b        bb                                                                                                   w",
			"w                                                                                        b        bb                                                             wwww                                  w",
			"w                                                                     z                  b ssssooobb                                 s                                                              e  w",
			"w                     o o                                    o     wwwwww            wwwwwwwwwwwwwwww                             s  www            z           oooooo                          wwwww  w",
			"w                   oo   oo  s                               w                                                                 s  www            wwww           wwwwww                                 w",
			"w              wwwww       wwwww                       o                                                   oooooo           s  www                                             wwwww                   w",
			"w                                                      w                                                   wwwwww        s  www    www      wwww                                                       w",
			"w       wwww                                     o                                                                       www      wooob                                                                w",
			"w                                  sssooss       wsssssssssssssssssssssssoooozsssssssssssssssssssssssssssss             sw        wooob ssss          ssssssssss                 sssssssoooozooosssss  w",
			"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
		};

		LvlGrid = new char* [14];
		for (int i = 0; i < 14; ++i) {
			LvlGrid[i] = new char[MaxWidht];
		}

		for (int i = 0; i < 14; ++i) {
			for (int j = 0; j < MaxWidht; ++j) {
				LvlGrid[i][j] = soniclevel[i][j];
			}
		}
		break;
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


		for (int i = 0; i < CharactersSize;i++) {
			Characters[i]->CheckCollisionGrid(LvlGrid, CellSize);
		}

		if (AnimationClock1.getElapsedTime().asMilliseconds() >= 100) {
			AnimationClock1.restart();
			for (int i = 0; i < CharactersSize;i++) {
				Characters[i]->Animate();
			}
		}

		if (AnimationClock2.getElapsedTime().asMilliseconds() >= 150) {
			AnimationClock2.restart();

			ringSprite.setTextureRect(IntRect(CurrentRing * 16, 0, 16, 16));
			CurrentRing++;
			if (CurrentRing >= 4) {
				CurrentRing = 0;
			}
		}

		for (int i = 0; i < CharactersSize;i++) { // Characters Update
			Characters[i]->Update();
		}
	}
}

void Levels::Draw(RenderWindow* window) {

	float Center = Characters[CurrentPlayer]->getXPosition() - 7 * CellSize;

	if (Center < 0 ) {
		Center = 0;
	}
	else if (Center > (MaxWidht - 19) * CellSize + 15) {
		Center = (MaxWidht - 19) * CellSize + 15;
	}

	levelBackGroundSprite.setPosition(0 - Center, 0);
	window->draw(levelBackGroundSprite);

	for (int i = 0; i < 14; i += 1) // Grid Items
	{
		for (int j = 0; j < MaxWidht; j += 1)
		{
			if (LvlGrid[i][j] == 'w')
			{
				wallSprite1.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(wallSprite1);
			}
			if (LvlGrid[i][j] == 's') {
				spikeSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(spikeSprite);
			}
			if (LvlGrid[i][j] == 'o') {
				ringSprite.setPosition(j * CellSize - Center + 8, i * CellSize + 8);
				window->draw(ringSprite);
			}
		}
	}

	for (int i = 0; i < CharactersSize;i++) { // Characters
		Characters[i]->DrawMoveable(window, Center);
	}

	window->display();
	window->clear();

}
