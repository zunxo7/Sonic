#include "Boss.h"

Boss::Boss(int X, int Y) {

	int Actions[7] = { 4, 0, 0, 0, 0, 0, 0 };
	ObjectAnimation.setActions(Actions);

	SpawnX = X;
	SpawnY = Y;
	HP = 100;

	Scale = 2;
	XPosition = X * 64;
	YPosition = Y * 64;
	XSpeed = 0;
	YSpeed = 0;

	HitBoxX = 84 * Scale;
	HitBoxY = 56 * Scale;
	BottomReached = false;
	StopAnimation = false;

	PLayerFound = 0;

	AttackTime = 1;

	ObjectTexture.loadFromFile("Data/Enemies/Boss.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 84, 56));
	ObjectSprite.setScale(Scale, Scale);

	SpikeTexture.loadFromFile("Data/Enemies/BossSpike.png");
	SpikeSprite.setTexture(SpikeTexture);
	SpikeSprite.setPosition(-64, -64);
}

void Boss::MovePattern(char** lvl, const int cell_size, float X) {

	float offset_x = XPosition + XSpeed;
	float offset_y = YPosition + YSpeed;

	char LeftM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 - 32) / cell_size))];
	char RightM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 + 32) / cell_size))];

	char bottom_mid_down = lvl[(int)(offset_y + HitBoxY + 1) / cell_size][(int)(((XPosition + HitBoxX / 2.0) / cell_size))];
	char TopMid = lvl[(int)(offset_y) / cell_size][(int)(((XPosition + HitBoxX / 2.0) / cell_size))];

	if(PLayerFound < 2){
		StopAnimation = false;
		if (ObjectAnimation.getDirection() == 1) { // Left
			if (LeftM == ' ' || LeftM == 'E') {
				XSpeed = -5;
				ObjectAnimation.setAction(1, 0);
			}
			else {
				ObjectAnimation.setAction(0, 0);
			}
		}
		else if (ObjectAnimation.getDirection() == 0) { // Right
			if (RightM == ' ' || RightM == 'E') {
				XSpeed = 5;
				ObjectAnimation.setAction(0, 0);
			}
			else {
				ObjectAnimation.setAction(1, 0);
			}
		}

		if (XPosition + HitBoxY / 2.0 > X  && XPosition + HitBoxY / 2.0 < X + 48) {
			if (AttackTimer.getElapsedTime().asSeconds() > 1) {
				AttackTimer.restart();
				PLayerFound++;
			}
		}

		XPosition += XSpeed;
	}
	else {
		StopAnimation = true;
		if(BottomReached == false){
			if (bottom_mid_down != 'q') {
				YSpeed = 5;
				SpikeSprite.setPosition(XPosition + HitBoxX / 2.0, YPosition + HitBoxY);
			}
			else {
				lvl[(int)(offset_y + HitBoxY + 1) / cell_size][(int)(((XPosition + HitBoxX / 2.0) / cell_size))] = ' ';
				BottomReached = true;
			}
		}
		else if(TopMid != 'w') {
			YSpeed = -5;
		}
		else {
			PLayerFound = 0;
			BottomReached = false;
		}
		YPosition += YSpeed;
	}
}

void Boss::Animate() {
	if(!StopAnimation){
		ObjectAnimation.NextFrame(ObjectSprite, ObjectTexture, HitBoxX / 2, HitBoxY / 2);
	}
}

int Boss::Score() {
	return 10000;
}