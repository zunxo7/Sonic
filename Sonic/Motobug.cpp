#include "Motobug.h"

Motobug::Motobug(int X,int Y) {

	int Actions[7] = { 5, 0, 0, 0, 0, 0, 0 };
	ObjectAnimation.setActions(Actions);

	SpawnX = X;
	SpawnY = Y;
	HP = 2;

	Scale = 2;
	XPosition = X * 64;
	YPosition = Y * 64;
	XSpeed = 0;
	YSpeed = 0;

	HitBoxX = 41 * Scale;
	HitBoxY = 32 * Scale;

	ObjectTexture.loadFromFile("Data/Eniemies/Bug.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 41, 32));
	ObjectSprite.setScale(Scale, Scale);
}

void Motobug::MovePattern(char** lvl, const int cell_size,float X) {

	float offset_x = XPosition + XSpeed;

	char LeftM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))];
	char RightM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))];

	char bottom_left_down = lvl[(int)(YPosition + HitBoxY + 1) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char bottom_right_down = lvl[(int)(YPosition + HitBoxY + 1) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];


	if (X < XPosition && (LeftM < 'a' || LeftM > 'z') && (bottom_left_down != ' ')) {
		XSpeed = -10;
		ObjectAnimation.setAction(1, 1);
	}
	else if (X > XPosition && (RightM < 'a' || RightM > 'z') && (bottom_right_down != ' ')) {
		XSpeed = 10;
		ObjectAnimation.setAction(0, 1);
	}
	else {
		XSpeed = 0;
	}
}