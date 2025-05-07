#include "CharacterFactory.h"

CharacterFactory::CharacterFactory(int MSpeed): Moveable(){
	int Actions[7] = { 1, 12, 10, 8, 16, 10, 8 };
	Scale = 2;

	ObjectAnimation.setActions(Actions);
	XPosition = 100;
	YPosition = 100;
	XSpeed = 0;
	YSpeed = 0;

	HitBoxX = 48 * Scale;
	HitBoxY = 48 * Scale;

	MaxSpeed = MSpeed;
	OnGround = false;
	Boosted = false;
	BoostTimer = 0;
}

float CharacterFactory::getXPosition() {
	return XPosition;
}

float CharacterFactory::getYPosition() {
	return YPosition;
}

float CharacterFactory::Gravity = 1;
float CharacterFactory::TerminalVelocity = 20;
float CharacterFactory::Acceleration = 0.5;
float CharacterFactory::Friction = 2;
float CharacterFactory::JumpStrength = -20;

int CharacterFactory::HP = 3;
int CharacterFactory::Rings = 0;
int CharacterFactory::Score = 0;

void CharacterFactory::ApplyGravity(char** lvl, const int cell_size)
{
	float offset_y = YPosition + YSpeed;

	char bottom_left_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)(XPosition + HitBoxX) / cell_size - 1];
	char bottom_right_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)(XPosition + HitBoxX) / cell_size];
	char bottom_mid_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)(XPosition + HitBoxX) / cell_size + 1];


	if (bottom_left_down == 'w' || bottom_mid_down == 'w' || bottom_right_down == 'w')
	{
		OnGround = true;
	}
	else
	{
		OnGround = false;
	}

	if (!OnGround)
	{
		YSpeed += Gravity;
		if (YSpeed >= TerminalVelocity) YSpeed = TerminalVelocity;
	}
	else
	{
		YSpeed = 0;
	}

}

void CharacterFactory::PlayerMove(char** lvl, const int cell_size,int MaxWidht) {
	float NextX = XPosition + XSpeed;

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		XSpeed -= Acceleration;

		if (XSpeed <= -MaxSpeed) {
			XSpeed = -MaxSpeed;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		XSpeed += Acceleration;

		if (XSpeed >= MaxSpeed) {
			XSpeed = MaxSpeed;
		}
	}
	else {
		if (XSpeed > 0) {
			XSpeed -= Acceleration * Friction;
			if (XSpeed < 0) XSpeed = 0;
		}
		if (XSpeed < 0) {
			XSpeed += Acceleration * Friction;
			if (XSpeed > 0) XSpeed = 0;
		}
	}

}


void CharacterFactory::Jump(char** lvl, const int cell_size) {

	char bottom_left_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(XPosition + HitBoxX) / cell_size - 1];
	char bottom_right_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(XPosition + HitBoxX) / cell_size];
	char bottom_mid_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(XPosition + HitBoxX) / cell_size + 1];


	if (bottom_left_down == 'w' || bottom_mid_down == 'w' || bottom_right_down == 'w')
	{
		OnGround = true;
	}
	else
	{
		OnGround = false;
	}

	if (OnGround) {
		YSpeed += JumpStrength;
	}

}

void CharacterFactory::MoveTo(char** lvl, const int cell_size, int X) {
	if (X < XPosition - HitBoxX) {
		XSpeed -= Acceleration;

		if (XSpeed <= -MaxSpeed) {
			XSpeed = -MaxSpeed;
		}
	}
	if(X > XPosition + HitBoxX) {
		XSpeed += Acceleration;

		if (XSpeed >= MaxSpeed) {
			XSpeed = MaxSpeed;
		}
	}
	if(X > XPosition - HitBoxX && X < XPosition + HitBoxX) {
		XSpeed = 0;
	}
}

void CharacterFactory::Update() {
	XPosition += XSpeed;
	YPosition += YSpeed;
}
