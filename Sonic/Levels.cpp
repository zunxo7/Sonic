#include "Levels.h"

Levels::Levels(CharacterFactory* sonic, CharacterFactory* tails, CharacterFactory* knuckles, TClass * MyClock) : CharactersSize(3), Characters(new CharacterFactory*[3]), GrandClock(MyClock) {

	font.load("Data/CustomFont");

	AbilityUsed = false;

	LivesTex.loadFromFile("Data/Lives.png");
	LivesSprite.setTexture(LivesTex);

	BoostTex.loadFromFile("Data/SpecialBoost.png");
	BoostSprite.setTexture(BoostTex);
	BoostSprite.setScale(2, 2);

	HPBoostTex.loadFromFile("Data/LivesBoost.png");
	HPBoostSprite.setTexture(HPBoostTex);
	HPBoostSprite.setScale(2, 2);

	CurrentLevel = 3;
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
	CurrentRing = 0;

	SignPostTex.loadFromFile(basePath + "Signpost.png");
	SignPostSprite.setTexture(SignPostTex);
	CurrentSign = 0;

	Crystal1UTex.loadFromFile(basePath + "crystal1.png");
	Crystal1DTex.loadFromFile(basePath + "crystal1d.png");
	Crystal2UTex.loadFromFile(basePath + "crystal2.png");
	Crystal2DTex.loadFromFile(basePath + "crystal2d.png");

	CellSize = 64;

	Characters[0] = sonic;
	Characters[1] = tails;
	Characters[2] = knuckles;
	CurrentPlayer = 2; // Sonic

	Characters[CurrentPlayer]->UpdatedHP(GrandClock->getInvincilibityClock());

	switch (CurrentLevel) {
	case 1:
		{
			MaxWidht = 200;
			const int Rows = 15;
			char soniclevel[Rows][201] = {

				"wwwwqwwqwwwwwwwqwwwwwwwwqwwwwewwwwwwwwwwwwwwwwwwwwwwwbwwwwwwwwwwqwwewwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
				"qeqweqwqeqweqwwbqeqwe       eqbqqweweeqeeweqeeqwbebw          wqwewbwqqr wbqwbewbwwwbwqqwwqw c eqwe c eewbwwwb wqwewbwqqr wbqwbewbwwwbwqqwwqw  wqqwwqwebqebbqewebwbwwqqbbqewebqqweqwqbwqqbbqew wwqwqebbw",
				"wwbeq c wbew  e  wbe         wqwwebqwwqweoobwb   er              ebqebb   bwbwwqqr wbqqweqw     eq     e         ebqebb   bwbwwqqr wbqqweqw       ebqebbbwbwwqqeqeweqqwewqwq C wwqe  wqwq     wq    qwqw",
				"wq c    r e      r              qwe      ooee             o       qwbC eqwbqbb qqwq  eqr        r                  qwbC  qwbqbb qqwq  eqr             bwbwwqqwwbqqweqwqbbwbwwqqeqe ew     wqwq  C   R  w",
				"q                                qw       uwe          o  p         ewbwbqw wbC eq   c                               qwbq eqw  qw   q                                       bwbwwqqeqew R ebbbwbwwqqeqww",
				"w                   oC                 o  we        o  p     o       qewee   eewbw                                                                                             ebbbwbwwqqeweq  qeweqq  w",
				"w               oo  peqwwbqwwq         p            p   R    p         ew     qewe	             o                                             so                                    wweqw        weq   w",
				"w               bb   wqweewowqe                  o     bbb      o              r e           o  p     o                                 oo    pp       wqqwwqw                                         w",
				"q       s   ooo       webqwooww     C R          p     quob     p                         o  p     o  p                                 pp          qwbqeqwbqbbqqwq                                    w",
				"w     wwe   ppp       qweweooob    ebbbe      o         wqb        o                      p        p      wbb      oo  s oo soos  ooo            wqqwwqwwwoooboqqwqeq                       oo         w",
				"w   qew  b             qwqwwoob   ew   we     p            qq      p                o                    qooob     pp pp pp pppp  ppp          qewee  c      booc oweb     oo    oo   oo    pp         w",
				"w  wewooob             weweeoob  ew     wee                                         p                   wwooob                                 qqwqeq o o o obooooooob     pp    pp   pp               w",
				"wwwqq ooob  sssssssssssseweweeewwwssssssswwwssssssssssssssssssssssss C                    sssssssssss   eqooob   ssssssssssssssssssssssssssssswbqqweqw  C R hbooC ooob  sssssssssssssssssssssssss   f  w",
				"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwbbbbbwwbbwwbbwwbbwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
				"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK"
			};

			LvlGrid = new char* [Rows];
			for (int i = 0; i < Rows; ++i) {
				LvlGrid[i] = new char[MaxWidht];
			}

			for (int i = 0; i < Rows; ++i) {
				for (int j = 0; j < MaxWidht; ++j) {
					LvlGrid[i][j] = soniclevel[i][j];
				}
			}

			break;
		}
	case 2: 
		{
			MaxWidht = 250;
			const int Rows = 15;
			char soniclevel2[Rows][251] = {

				"wwwwqwwqwwwwwwwqwwwwwwwwqwwwwewwwwwwwwwwwwwwwwwwwwwwwbwwwwwwwwwwqwwewwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
				"qeqweqwqeqweqwwbqeqwe eqbqqweqbqqweweeqeeweqeeqwbebw    wqwewbwqqr    wbqwbewbwwwbwqqwwqw c eqwe c eqbqqweweeqeeweqeeqwbebwqwqwewbwqqr wbqwbewbwwwbwqqwwqwwwwqqwwqwebqebbqewebwbwwqqbbqewebqqweqwqbwqqbbqew wwqwqebb      wwqwqebb      qqqewebw   qqqewww",
				"wwbeq c wbew  e  wbe   wbe     wbeq c wbew  e  wbe          ebqebb       bwbwwqqr wbqqweqw   qqweq    wbeq  wbew  e  wbewwqqr wbqqweqw      e       w                q        ewebw    ewebw      ewebw     ewebw           ewebw        ewebw     ewebwww",
				"wq c    r e      r      r        c    r e      r             b  r          qwbc     eqwb      qqwq      c    r e      r    qwb  qwbqbb                                           r       c          r         c                           eeq        qeeww",
				"q                                                           b               e         e        w                                                                                                                                                       qww",
				"w                                                          b                                                             oC                             o   p     o                                                                                      w",
				"w                         o                                b                                                         oo  peqwwbqwwq                     p    R    p                                                   wwqwq                              w",
				"w               soo   o   p                         o   ooob                                                         bb   wqweewqwqe                 o       bbb      o                                            wqqwwqwwww                            w",
				"q         soo   ppp   p       ooo              o    p   pppp                                                  s   ooo       webqwooww     C R        p       qoob     p                            oo            qwwq c   wwq R                          w",
				"w     o   ppp                 ppp    o     o   p               C o       ooo        R  C   R   C            wwe   ppp       qweweooob    ebbbe     o          wqb       o     oo  s oo soos  ooo   pp       wqqwwqwww     qqwqeq pwp     ss              w",
				"w     p            bbb               p     p                   ppp       ppp      bbbbwqwqbbbbwqbq       qew  b             qwqwwoob   ew   we     p             qq     p     pp pp pp pppp  ppp           qewee  c             b   qwwqqqwqqqe          w",
				"w                  qooq                                                         eeewqwqeeewqeqwqqwqe    wewooob             weweeoob  ew     wee                          C                               qqwqeq                b              b         w",
				"wwqqwssssssssssssssesosqsssssssssssssssssssssssssssssssssssssssssssssssssssssssqweewqwqewqeweweewqewqqwwqq ooob  sssssssssssseweweeewwwssssssswwwsssssssssssssssssssssssspppssssssssssssssssssssssssssssswbqqweqw  C   f        b              b   ssss  w",
				"wwwwwwwwwwwwwwwwwwwwbbbwwwwwwwwwwwwwwwqwwwwwwwwwwwwwwwwwwwwwewwwwwwwwwwwwwwwwwwwwqwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwbbbwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
				"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK"
			};

			LvlGrid = new char* [Rows];
			for (int i = 0; i < Rows; ++i) {
				LvlGrid[i] = new char[MaxWidht];
			}

			for (int i = 0; i < Rows; ++i) {
				for (int j = 0; j < MaxWidht; ++j) {
					LvlGrid[i][j] = soniclevel2[i][j];
				}
			}

			break;
		}
	case 3:
	{
		MaxWidht = 300;
		const int Rows = 15;
		char soniclevel2[Rows][301] = {

			"wwwwqwwqwwwwwwwqwwwwwwwwqwwwwewwwwwwwwwwwwwwwwwwwwwwwbwwwwwwwwwwqwwewwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
			"qeqweqwqeqw                           qweqwqeqw  C    C  qweqwqeqw                                                                                                                                       qwwqqwwqwqoouoo          qwqwqwwqqwqwqwqwooooooooeqwwqeewqqqqeq      r     c                eqwwqew",
			"weqweq C                                qweqw              qweqw                 r     c     c                                                                                                                qwwqqooooo           ooooooooooooooooooooooooewqwqewqeqqq                             eqwwqeww",
			"weq                                      eqq                eqq        qpppwwqeeqweeqwqeqeeeqwwqw                                                          r  c  r                                               qwwqqwwqwq        oooooooooooooooooooooooooooooewqewq                               eqwwqew",
			"q               oooo                      R                  C               eeqwwqw             b                                                    qwwqqwwqwqqwwqqwwqwq  oooo                                   qwwqqwwqwq      qwwqqwqwewqwqeewqweqeqwwqeeqewqwwq                                  ewwew",
			"w               pppp    ooos                                                 wqwww               b                                                 qwwqqwwqwq               pppp                                  qwwqqwwqwqeepppppp                                                                       w",
			"w                       pppp                                                 qqewqq  s    qqqwwqeqwq                                          ooqwwqqwwqwq                        oooo                                                                                                                     w",
			"w       sooo                                                           qpppwwqweqwqeqw  oooo     wqwqe U                                   ooqwwqqwwqwq                           pppp           oooo    ooo                    soos                                                                       w",
			"q       pppp                                                                wqweqwqqweq oooo      ewqeqw                                 ooqwwqqwwqwq                                   oooo     pppp    ppp                    pppp    ooso                                                               w",
			"w                                                                           qqweqwqqweqqwqqqqw     qewqeweq                             qwwqqwwqwq          bbbbbb            oooo      pppp                               qqqq         pppp      sooos                 R                                  w",
			"wq	           oooos                      eqq                qwe             wwqqw        oooob      qwqwqwwqqq         o o          qwwqqwwqwq             boooooob           pppp                                 qwwqqwwqwq                     ppppp      qwwqqwwqwqqwoCooo                             w",
			"weqwe r       ppppp                  qweqwqweqw            qweqwqwooowqqbbbwweq          oooob      ooooooooob       o    o         qwwqqwwqwq             boohooob                                              qwwqqwwqwq                                qwwqqwwqwqqwwqqwwqwqoHoo                        w",
			"weqweqwqsssssssssssssssssssssssqweqwqeqwqweqwqeqwsssssssqweqwqweqwqweqwsssssw    u       oooob      ooooooooob        oooo         wqwqe                    bbbbbb         ssssssssssssssssssssssssssssssssssqwwqqwwqwqsssssssssssssssssssssssssssssssssqwwqqwwqwqqwwqqwwqwqqwwqqwwq         f    C  R     w",
			"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwqwwwwwwwwwwwwwwwwwwwwwewwwwwwwwwwwwwwwwwwwwqwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwbbbbbbbbbbbbbbbbbwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwqwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
			"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK"
		};

		LvlGrid = new char* [Rows];
		for (int i = 0; i < Rows; ++i) {
			LvlGrid[i] = new char[MaxWidht];
		}

		for (int i = 0; i < Rows; ++i) {
			for (int j = 0; j < MaxWidht; ++j) {
				LvlGrid[i][j] = soniclevel2[i][j];
			}
		}

		break;
	}
	case 4:
		{
			MaxWidht = 19;
			const int Rows = 15;
			char bossLevel[Rows][20] = {

				"wwwwwwwwwwwwwwwwwww",
				"w                 w",
				"w                 w",
				"w                 w",
				"w                 w",
				"w                 w",
				"w                 w",
				"w                 w",
				"w                 w",
				"w                 w",
				"w    qqqqqqqqq    w",
				"w                 w",
				"w                 w",
				"wwwwwwwwwwwwwwwwwww",
				"KKKKKKKKKKKKKKKKKKK"
			};


			LvlGrid = new char* [Rows];
			for (int i = 0; i < Rows; ++i) {
				LvlGrid[i] = new char[MaxWidht];
			}

			for (int i = 0; i < Rows; ++i) {
				for (int j = 0; j < MaxWidht; ++j) {
					LvlGrid[i][j] = bossLevel[i][j];
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
	if (GrandClock->getPlayerClock().getElapsedTime().asMilliseconds() >= 25) {
		GrandClock->getPlayerClock().restart();
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

		if (Keyboard::isKeyPressed(Keyboard::Z) && GrandClock->getSwitchClock().getElapsedTime().asSeconds() > 1) {
			GrandClock->getSwitchClock().restart();

				AbilityUsed = false;
			
				CurrentPlayer++;

				if (CurrentPlayer >= 3) {
					CurrentPlayer = 0;
				}
				
		}

		if (Keyboard::isKeyPressed(Keyboard::E) && GrandClock->getAbilityClock().getElapsedTime().asSeconds() > 1 * (CurrentPlayer == 2) + 5 * (CurrentPlayer == 1) && !AbilityUsed) {
			GrandClock->getAbilityClock().restart();
			AbilityUsed = true;
		}

		if (AbilityUsed) {
			Characters[CurrentPlayer]->UsedAbility(LvlGrid, CellSize, GrandClock->getAbilityClock(), AbilityUsed);
		}


		for (int i = 0; i < CharactersSize;i++) {
			Characters[i]->CheckCollisionGrid(LvlGrid, CellSize, GrandClock->getRingClock());
		}

		Characters[CurrentPlayer]->SpikeCollisions(LvlGrid, CellSize, GrandClock->getInvincilibityClock());

		if (GrandClock->getAnimationClock1().getElapsedTime().asMilliseconds() >= 100) {
			GrandClock->getAnimationClock1().restart();
			for (int i = 0; i < CharactersSize;i++) {
				Characters[i]->Animate();
			}
		}

		if (GrandClock->getAnimationClock2().getElapsedTime().asMilliseconds() >= 150) {
			GrandClock->getAnimationClock2().restart();

			ringSprite.setTextureRect(IntRect(CurrentRing * 17, 0, 15, 16));
			CurrentRing++;
			if (CurrentRing >= 4) {
				CurrentRing = 0;
			}

			SignPostSprite.setTextureRect(IntRect(CurrentSign * 48, 0, 48, 48));
			CurrentSign++;
			if (CurrentSign >= 5) {
				CurrentSign = 0;
			}
		}

		for (int i = 0; i < CharactersSize;i++) { // Characters Update
			Characters[i]->Update();
		}

		Characters[CurrentPlayer]->UpdatedScore();
		Characters[CurrentPlayer]->UpdatedRings();
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
			else if (LvlGrid[i][j] == 'B') {
				wallSprite.setTexture(wallTex5);
				wallSprite.setTextureRect(IntRect(64, 0, 64, 64));
				wallSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(wallSprite);
				wallSprite.setTextureRect(IntRect(0, 0, 64, 64));
			}
			else if (LvlGrid[i][j] == 's') {
				spikeSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(spikeSprite);
			}
			else if (LvlGrid[i][j] == 'o') {
				ringSprite.setScale(3, 3);
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
			else if (LvlGrid[i][j] == 'h') {
				HPBoostSprite.setTexture(HPBoostTex);
				HPBoostSprite.setTextureRect(IntRect(0, 0, 32, 32));
				HPBoostSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(HPBoostSprite);
			}
			else if (LvlGrid[i][j] == 'H') {
				HPBoostSprite.setTexture(HPBoostTex);
				HPBoostSprite.setTextureRect(IntRect(32, 0, 32, 32));
				HPBoostSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(HPBoostSprite);
			}
			else if (LvlGrid[i][j] == 'u') {
				BoostSprite.setTexture(BoostTex);
				BoostSprite.setTextureRect(IntRect(0, 0, 32, 32));
				BoostSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(BoostSprite);
			}
			else if (LvlGrid[i][j] == 'U') {
				BoostSprite.setTexture(BoostTex);
				BoostSprite.setTextureRect(IntRect(32, 0, 32, 32));
				BoostSprite.setPosition(j * CellSize - Center, i * CellSize);
				window->draw(BoostSprite);
			}
			else if (LvlGrid[i][j] == 'f') {
				SignPostSprite.setScale(2, 2);
				SignPostSprite.setPosition(j * CellSize - Center - 24, i * CellSize - 34);
				window->draw(SignPostSprite);
			}
		}
	}

	for (int i = 0; i < CharactersSize;i++) { // Characters
		Characters[i]->DrawMoveable(window, Center);
	}


	LivesSprite.setTextureRect(IntRect(24 * CurrentPlayer,0,24,24));
	ringSprite.setScale(1.5, 1.5);
	LivesSprite.setPosition(5, CellSize + 32 + 5);
	window->draw(LivesSprite);

	ringSprite.setScale(2, 2);
	ringSprite.setPosition(5,CellSize);
	window->draw(ringSprite);


	font.draw(window, to_string(CharacterFactory::getRings()), 32 + 10, 62 , 3, 15, 2.7,Color::Black);
	font.draw(window, to_string(CharacterFactory::getHP()), 32 + 10, 64 + 33, 3, 15, 2.7, Color::Black);
	font.draw(window, "Score: " + to_string(CharacterFactory::getScore()), 10, 10, 2.0f, 15, 2.7, Color::Black);

	window->display();
	window->clear();

}
