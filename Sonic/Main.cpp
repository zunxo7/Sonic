#include "Game.h"
#include "Sonic.h"
#include "Tails.h"
#include "Knuckles.h"

using namespace sf;
using namespace std;

int main()
{

	Sonic MySonic;
	Tails MyTails;
	Knuckles MyKnucles;
	TClass MyClock;

	Game MyGame(&MySonic, &MyTails, &MyKnucles, &MyClock);

	while (MyGame.running()) {
		MyGame.update();
		MyGame.Draw();
	}

	return 0;
}