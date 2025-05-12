#include "CrabMeat.h"

CrabMeat::CrabMeat(int X, int Y) {

	int Actions[7] = { 3, 0, 0, 0, 0, 0, 0 };
	ObjectAnimation.setActions(Actions);

	SpawnX = X;
	SpawnY = Y;
	HP = 2;

	Scale = 2;
	XPosition = X * 64;
	YPosition = Y * 64;
	XSpeed = 0;
	YSpeed = 0;

	HitBoxX = 45 * Scale;
	HitBoxY = 32 * Scale;

	ObjectTexture.loadFromFile("Data/Enemies/Crab.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 45, 32));
	ObjectSprite.setScale(Scale, Scale);
}

void CrabMeat::MovePattern(char** lvl, const int cell_size, float X, float Y) {

	float offset_x = XPosition + XSpeed;

	char LeftM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))];
	char RightM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))];

	char bottom_left_down = lvl[(int)(YPosition + HitBoxY + 1) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char bottom_right_down = lvl[(int)(YPosition + HitBoxY + 1) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];


	if ( (LeftM < 'a' || LeftM > 'z') && (bottom_left_down != ' ') && XPosition > (SpawnX - 2) * 64) {
		XSpeed = -2;
		ObjectAnimation.setAction(1, 0);
	}
	else if ( (RightM < 'a' || RightM > 'z') && (bottom_right_down != ' ') && XPosition < (SpawnX + 2) * 64) {
		XSpeed = 2;
		ObjectAnimation.setAction(0, 0);
	}
	else {
		XSpeed = 0;
	}

	XPosition += XSpeed;
}

void CrabMeat::Animate() {
	ObjectAnimation.NextFrame(ObjectSprite, ObjectTexture, HitBoxX / 2, HitBoxY / 2);
}

int CrabMeat::Score() {
	return 50;
}