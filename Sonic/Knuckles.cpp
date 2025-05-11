#include "Knuckles.h"

Knuckles::Knuckles() : CharacterFactory(12) {

	ObjectTexture.loadFromFile("Data/Knuckles.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 48, 48));
	ObjectSprite.setScale(Scale, Scale);
}

bool Knuckles::canFly() {
	return false;
}

void Knuckles::UsedAbility(char** lvl, const int cell_size, Clock& AbilityClock,bool& AbilityUsed) {
	char LeftM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))];
	char RightM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))];

	char LeftD = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))];
	char RightD = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))];

	char LeftU = lvl[(int)((YPosition + 20) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))];
	char RightU = lvl[(int)((YPosition + 20) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))];

	if (XSpeed > 0) {
		if (RightD == 'b') {
			lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))] = 'B';
		}
		if (RightM == 'b') {
			lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))] = 'B';
		}
		if (RightU == 'b') {
			lvl[(int)((YPosition + 20) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))] = 'B';
		}
		if (RightD == 'B') {
			lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))] = ' ';
		}
		if (RightM == 'B') {
			lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))] = ' ';
		}
		if (RightU == 'B') {
			lvl[(int)((YPosition + 20) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))] = ' ';
		}
	}
	else if (XSpeed < 0) {
		if (LeftD == 'b') {
			lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))] = 'B';
		}
		if (LeftM == 'b') {
			lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))] = 'B';
		}
		if (LeftU == 'b') {
			lvl[(int)((YPosition + 20) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))] = 'B';
		}
		if (LeftD == 'B') {
			lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))] = ' ';
		}
		if (LeftM == 'B') {
			lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))] = ' ';
		}
		if (LeftU == 'B') {
			lvl[(int)((YPosition + 20) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))] = ' ';
		}
	}

	AbilityUsed = false;

}