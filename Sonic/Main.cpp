#include "Game.h"
#include "Sonic.h"
#include "Tails.h"
#include "Knuckles.h"

using namespace sf;
using namespace std;

int main()
{
	/////////////////////////////////////////////////////////////////
	// a cell is 64 by 64 pixels

	// 's' is regular space
	// 'q' is wall1 or floor1
	// 'w' is wall2 or floor2
	// 'e' is wall3 or floor3
	// 'b' is breakable wall
	// 'z' is spring

	// Uppercase for not interactable background accessories

	// C is for crystals

	Texture wallTex1;
	Sprite wallSprite1;

	Music lvlMus;

	lvlMus.openFromFile("Data/labrynth.ogg");
	lvlMus.setVolume(30);
	lvlMus.play();
	lvlMus.setLoop(true);

	///////////////////////////////////

	Sonic MySonic;
	Tails MyTails;
	Knuckles MyKnucles;

	Game MyGame(&MySonic, &MyTails, &MyKnucles);

	while (MyGame.running()) {
		MyGame.update();
		MyGame.Draw();
	}

	return 0;
}