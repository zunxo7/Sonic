#include "Levels.h"

Levels::Levels(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles) : CharactersSize(3), Characters(new CharacterFactory*[3]) {

	if (!SonicFont.loadFromFile("Data/Fonts/SonicFont.otf")) {
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << std::endl;
	}

	ScoreText.setFont(SonicFont);
	ScoreText.setCharacterSize(30);
	ScoreText.setPosition(0, 64);
	ScoreText.setString("Score: 0");

	CurrentLevel = 2;
	string basePath = "Data/Levels/Level";
	basePath += (char)('0' + CurrentLevel);
	basePath += "/";

	levelBackGroundTexture.loadFromFile(basePath + "bg.png");
	levelBackGroundSprite.setTexture(levelBackGroundTexture);

	wallTex1.loadFromFile(basePath + "brick1.png");
	wallTex2.loadFromFile(basePath + "brick2.png");
	wallTex3.loadFromFile(basePath + "brick3.png");
	wallTex4.loadFromFile(basePath + "brick4.png");
	wallTex5.loadFromFile(basePath + "brick5.png");
	spikeTex.loadFromFile(basePath + "spike.png");
	spikeSprite.setTexture(spikeTex);
	ringTex.loadFromFile("Data/ring.png");
	ringSprite.setTexture(ringTex);
	ringSprite.setScale(3, 3);
	CurrentRing = 0;

	Crystal1UTex.loadFromFile(basePath + "crystal1.png");
	Crystal1DTex.loadFromFile(basePath + "crystal1d.png");
	Crystal2UTex.loadFromFile(basePath + "crystal2.png");
	Crystal2DTex.loadFromFile(basePath + "crystal2d.png");

	CellSize = 64;

	Characters[0] = sonic;
	Characters[1] = tails;
	Characters[2] = knuckles;
	CurrentPlayer = 0; // Sonic

	switch (CurrentLevel) {
	case 1: 
		{
			MaxWidht = 200;
			char soniclevel[14][201] = {

				"wwwwqwwqwwwwwwwqwwwwwwwwqwwwwewwwwwwwwwwwwwwwwwwwwwwwbwwwwwwwwwwqwwewwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
				"qeqweqwqeqweqwwbqeqwe       eqbqqweweeqeeweqeeqwbebw          wqwewbwqqr wbqwbewbwwwbwqqwwqw c eqwe c eewbwwwb wqwewbwqqr wbqwbewbwwwbwqqwwqw  wqqwwqwebqebbqewebwbwwqqbbqewebqqweqwqbwqqbbqew wwqwqebbw",
				"wwbeq c wbew  e  wbe         wqwwebqwwqweoobwb   er              ebqebb   bwbwwqqr wbqqweqw     eq     e         ebqebb   bwbwwqqr wbqqweqw       ebqebbbwbwwqqeqeweqqwewqwq C wwqe  wqwq     wq    qwqw",
				"wq c    r e      r              qwe      ooee             o       qwbC eqwbqbb qqwq  eqr        r                  qwbC  qwbqbb qqwq  eqr             bwbwwqqwwbqqweqwqbbwbwwqqeqe ew     wqwq  C   R  w",
				"q                                qw        we          o  p         ewbwbqw wbC eq   c                               qwbq eqw  qw   q                                       bwbwwqqeqew R ebbbwbwwqqeqww",
				"w                   oC                 o  we        o  p     o       qewee   eewbw                                                                                             ebbbwbwwqqeweq  qeweqq  w",
				"w               oo  peqwwbqwwq         p            p   R    p         ew     qewe	             o                                             so                                    wweqw        weq   w",
				"w               bb   wqweewowqe                  o     bbb      o              r e           o  p     o                                 oo    pp       wqqwwqw                                         w",
				"q       s   ooo       webqwooww     C R          p     qoow     p                         o  p     o  p                                 pp          qwbqeqwbqbbqqwq                                    w",
				"w     wwe   ppp       qweweooob    ebbbe      o         wqw        o                      p        p      wbb      oo  s oo soos  ooo            wqqwwqwwwoooboqqwqeq                       oo         w",
				"w   qew  b             qwqwwoob   ew   we     p                    p                o                    qooow     pp pp pp pppp  ppp           qewee  c     booc oweb     oo    oo   oo    pp         w",
				"w  wewooob             weweeoob  ew     wee                                         p                   wwooow                                 qqwqeq o o o obooooooob     pp    pp   pp               w",
				"wwwqq ooob  sssssssssssseweweeewwwssssssswwwssssssssssssssssssssssss C                    sssssssssss   eqooow   ssssssssssssssssssssssssssssswbqqweqw  C R  booC ooob  sssssssssssssssssssssssss   f  w",
				"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwbbbbbwwbbwwbbwwbbwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
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
	case 2: 
		{
			MaxWidht = 250;
			char soniclevel2[14][250] = {

				"wwwwqwwqwwwwwwwqwwwwwwwwqwwwwewwwwwwwwwwwwwwwwwwwwwwwbwwwwwwwwwwqwwewwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
				"qeqweqwqeqweqwwbqeqwe eqbqqweqbqqweweeqeeweqeeqwbebw    wqwewbwqqr    wbqwbewbwwwbwqqwwqw c eqwe c eqbqqweweeqeeweqeeqwbebwqwqwewbwqqr wbqwbewbwwwbwqqwwqwwwwqqwwqwebqebbqewebwbwwqqbbqewebqqweqwqbwqqbbqew wwqwqebb      wwqwqebb      qqqewebw   qqqeww",
				"wwbeq c wbew  e  wbe   wbe     wbeq c wbew  e  wbe          ebqebb       bwbwwqqr wbqqweqw   qqweq    wbeq  wbew  e  wbewwqqr wbqqweqw      e       w                q        ewebw    ewebw      ewebw     ewebw           ewebw        ewebw     ewebww",
				"wq c    r e      r      r        c    r e      r             b  r          qwbc     eqwb      qqwq      c    r e      r    qwb  qwbqbb                                           r       c          r         c                           eeq        qeew",
				"q                                                           b               e         e        w                                                                                                                                                       qw",
				"w                                                          b                                                             oC                             o   p     o                                                                                     w",
				"w                         o                                b                                                         oo  peqwwbqwwq                     p    R    p                                                   wwqwq                             w",
				"w               soo   o   p                         o   ooob                                                         bb   wqweewqwqe                 o       bbb      o                                            wqqwwqwwww                           w",
				"q         soo   ppp   p       ooo              o    p   pppp                                                  s   ooo       webqwooww     C R        p       qoow     p                            oo            qwwq c   wwq R                         w",
				"w     o   ppp                 ppp    o     o   p               C o       ooo        R  C   R   C            wwe   ppp       qweweooob    ebbbe     o          wqw       o     oo  s oo soos  ooo   pp       wqqwwqwww     qqwqeq pwp     ss             w",
				"w     p            bbb               p     p                   ppp       ppp      bbbbwqwqbbbbwqbq       qew  b             qwqwwoob   ew   we     p                    p     pp pp pp pppp  ppp           qewee  c             b   qwwqqqwqqqe         w",
				"w                  qooq                                                         eeewqwqeeewqeqwqqwqe    wewooob             weweeoob  ew     wee                          C                               qqwqeq                b              b        w",
				"wwqqwssssssssssssssesosqsssssssssssssssssssssssssssssssssssssssssssssssssssssssqweewqwqewqeweweewqewqqwwqq ooob  sssssssssssseweweeewwwssssssswwwsssssssssssssssssssssssspppssssssssssssssssssssssssssssswbqqweqw  C   f        b              b   ssss w",
				"wwwwwwwwwwwwwwwwwwwwbbbwwwwwwwwwwwwwwwqwwwwwwwwwwwwwwwwwwwwwewwwwwwwwwwwwwwwwwwwwqwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwbbbwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
			};

			LvlGrid = new char* [14];
			for (int i = 0; i < 14; ++i) {
				LvlGrid[i] = new char[MaxWidht];
			}

			for (int i = 0; i < 14; ++i) {
				for (int j = 0; j < MaxWidht; ++j) {
					LvlGrid[i][j] = soniclevel2[i][j];
				}
			}
			break;
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
			if (LvlGrid[i][j] == 'w'){
				wallSprite.setTexture(wallTex1);
				wallSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(wallSprite);
			}
			else if (LvlGrid[i][j] == 'p'){
				wallSprite.setTexture(wallTex2);
				wallSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(wallSprite);
			}
			else if (LvlGrid[i][j] == 'q') {
				wallSprite.setTexture(wallTex3);
				wallSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(wallSprite);
			}
			else if (LvlGrid[i][j] == 'e') {
				wallSprite.setTexture(wallTex4);
				wallSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(wallSprite);
			}
			else if (LvlGrid[i][j] == 'b') {
				wallSprite.setTexture(wallTex5);
				wallSprite.setTextureRect(IntRect(0, 0, CellSize, CellSize));
				wallSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(wallSprite);
			}
			else if (LvlGrid[i][j] == 's') {
				spikeSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(spikeSprite);
			}
			else if (LvlGrid[i][j] == 'o') {
				ringSprite.setPosition(j * CellSize - Center + 8, i * CellSize + 8);
				window->draw(ringSprite);
			}
			else if (LvlGrid[i][j] == 'C') {
				CrystalSprite.setTexture(Crystal1UTex);
				CrystalSprite.setPosition(j * CellSize - Center, i * CellSize );
				window->draw(CrystalSprite);
			}
			else if (LvlGrid[i][j] == 'c') {
				CrystalSprite.setTexture(Crystal1DTex);
				CrystalSprite.setPosition(j * CellSize - Center , i * CellSize);
				window->draw(CrystalSprite);
			}
			else if (LvlGrid[i][j] == 'R') {
				CrystalSprite.setTexture(Crystal2UTex);
				CrystalSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(CrystalSprite);
			}
			else if (LvlGrid[i][j] == 'r') {
				CrystalSprite.setTexture(Crystal2DTex);
				CrystalSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(CrystalSprite);
			}
		}
	}

	for (int i = 0; i < CharactersSize;i++) { // Characters
		Characters[i]->DrawMoveable(window, Center);
	}

	window->draw(ScoreText);

	window->display();
	window->clear();

}
