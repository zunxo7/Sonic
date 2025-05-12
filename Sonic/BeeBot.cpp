#include "BeeBot.h"

BeeBot::BeeBot(int X, int Y) {

	int Actions[7] = { 4, 4, 0, 0, 0, 0, 0 };
	ObjectAnimation.setActions(Actions);

	SpawnX = X;
	SpawnY = Y;
	HP = 2;

	Scale = 2;
	XPosition = X * 64;
	YPosition = Y * 64;
	XSpeed = 0;
	YSpeed = 0;

	HitBoxX = 46 * Scale;
	HitBoxY = 38 * Scale;

	ObjectTexture.loadFromFile("Data/Enemies/Bug.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 46, 38));
	ObjectSprite.setScale(Scale, Scale);
}

void BeeBot::MovePattern(char** lvl, const int cell_size, float X, float Y) {

	float offset_x = XPosition + XSpeed;

	char LeftM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))];
	char RightM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))];

	char DownM = lvl[(int)(YPosition + HitBoxY + 1) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char UpM = lvl[(int)(YPosition + HitBoxY + 1) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];


	if (X < XPosition - 10 && (LeftM < 'a' || LeftM > 'z')) {
		XSpeed = -1;
		ObjectAnimation.setAction(1, 1);
	}
	else if (X > XPosition + 10 && (RightM < 'a' || RightM > 'z')) {
		XSpeed = 1;
		ObjectAnimation.setAction(0, 1);
	}
	else {
		XSpeed = 0;
	}

	XPosition += XSpeed;

	if (Y < YPosition - 10 && (UpM < 'a' || UpM > 'z')) {
		YSpeed = -2;
	}
	else if (Y > YPosition + 10 && (DownM < 'a' || DownM > 'z')) {
		YSpeed = 2;
	}
	else {
		YSpeed = 0;
	}

	YPosition += YSpeed;
}

void BeeBot::Animate() {
	ObjectAnimation.NextFrame(ObjectSprite, ObjectTexture, HitBoxX / 2, HitBoxY / 2);
}

int BeeBot::Score() {
	return 200;
}