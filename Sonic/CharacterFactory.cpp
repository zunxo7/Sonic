#include "CharacterFactory.h"

CharacterFactory::CharacterFactory(int MSpeed): Moveable() {
	int Actions[7] = { 1, 12, 10, 8, 16, 10, 8 };
	ObjectAnimation.setActions(Actions);

	Scale = 2;
	XPosition = 2 * 64;
	YPosition = 7 * 64;
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

	char bottom_left_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char bottom_mid_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)];
	char bottom_right_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];

	char WallCharac[6] = { 'w','p','q','e','b','\0' };

	OnGround = false;

	for (int i = 0; i < 5;i++) {
		if ((bottom_left_down == WallCharac[i] || bottom_mid_down == WallCharac[i] || bottom_right_down == WallCharac[i]))
		{
			OnGround = true;
		}
	}

	if (!OnGround)
	{
		YSpeed += Gravity;
		if (YSpeed >= TerminalVelocity) YSpeed = TerminalVelocity;
	}
	else if (YSpeed > 0){
		YSpeed = 0;
	}

}

void CharacterFactory::PlayerMove(char** lvl, const int cell_size,int MaxWidht) {

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		XSpeed -= Acceleration;
		ObjectAnimation.setAction(1, 1);

		if (XSpeed <= -MaxSpeed) {
			XSpeed = -MaxSpeed;
			ObjectAnimation.setAction(1, 2);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		XSpeed += Acceleration;
		ObjectAnimation.setAction(0, 1);

		if (XSpeed >= MaxSpeed) {
			XSpeed = MaxSpeed;
			ObjectAnimation.setAction(0, 2);
		}
	}
	else {
		if (XSpeed > 0) {
			XSpeed -= Acceleration * Friction;
			if (XSpeed < 0) {
				XSpeed = 0;
			}
		}
		if (XSpeed < 0) {
			XSpeed += Acceleration * Friction;
			if (XSpeed > 0) {
				XSpeed = 0;
			}
		}
	}

	if (XSpeed == 0) {
		ObjectAnimation.setAction(2, 0);
	}

	if (!OnGround && YSpeed != 0) {
		ObjectAnimation.setAction(2, 4);
	}

}


void CharacterFactory::Jump(char** lvl, const int cell_size) {

	char bottom_left_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char bottom_mid_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)];
	char bottom_right_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];


	char WallCharac[6] = { 'w','p','q','e','b','\0' };

	OnGround = false;

	for (int i = 0; i < 5;i++) {
		if ((bottom_left_down == WallCharac[i] || bottom_mid_down == WallCharac[i] || bottom_right_down == WallCharac[i]))
		{
			OnGround = true;
		}
	}

	if (OnGround && YSpeed == 0) {
		YSpeed += JumpStrength;
	}

}

void CharacterFactory::MoveTo(char** lvl, const int cell_size, int X) {
	if (X < XPosition - HitBoxX) {
		XSpeed -= Acceleration;
		ObjectAnimation.setAction(1, 1);

		if (XSpeed <= -MaxSpeed) {
			XSpeed = -MaxSpeed;
			ObjectAnimation.setAction(1, 2);
		}
	}
	if(X > XPosition + HitBoxX) {
		XSpeed += Acceleration;
		ObjectAnimation.setAction(0, 1);

		if (XSpeed >= MaxSpeed) {
			XSpeed = MaxSpeed;
			ObjectAnimation.setAction(0, 2);
		}
	}
	if(X > XPosition - HitBoxX && X < XPosition + HitBoxX) {
		XSpeed = 0;
	}

	if (XSpeed == 0) {
		ObjectAnimation.setAction(2, 0);
	}

	if (!OnGround && YSpeed != 0) {
		ObjectAnimation.setAction(2, 4);
	}

	if (lvl[(int)(YPosition + HitBoxY / 2.0) / cell_size][(int)(XPosition + 10) / cell_size + 1] == 'w' && XSpeed > 0) {
		Jump(lvl,cell_size);
	}

	if (lvl[(int)(YPosition + HitBoxY / 2.0) / cell_size][(int)(XPosition + HitBoxX) / cell_size - 1] == 'w' && XSpeed < 0) {
		Jump(lvl, cell_size);
	}
}

void CharacterFactory::Update() {
	XPosition += XSpeed;
	YPosition += YSpeed;
}

void CharacterFactory::Animate() {
	ObjectAnimation.NextFrame(ObjectSprite, ObjectTexture, HitBoxX / 2, HitBoxY / 2);
}

void CharacterFactory::CheckCollisionGrid(char** lvl, const int cell_size) {

	float offset_x = XPosition + XSpeed;

	char WallCharac[6] = { 'w','p','q','e','b','\0' };

	char bottom_left_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))];
	char bottom_mid_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)];
	char bottom_right_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))];

	if ((bottom_left_down == 'p' && bottom_mid_down != 'p' && bottom_right_down != 'p') && OnGround) {
		ObjectAnimation.setAction(0, 6);
	}
	else if ((bottom_left_down != 'p' && bottom_mid_down != 'p' && bottom_right_down == 'p') && OnGround) {
		ObjectAnimation.setAction(1, 6);
	}

	char Right = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))];
	char Mid = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)((offset_x + HitBoxX / 2.0) / cell_size)];
	char Left = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))];

	if (XSpeed > 0) {
		switch (Right) {
		case 'w':
		case 'p':
		case 'q':
		case 'e':
		case 'b':
			XSpeed = 0;
			ObjectAnimation.setAction(0, 5);
			break;
		}
	}
	else if (XSpeed < 0) {
		switch (Left) {
		case 'w':
		case 'p':
		case 'q':
		case 'e':
		case 'b':
			XSpeed = 0;
			ObjectAnimation.setAction(1, 5);
			break;
		}
	}

	switch (Mid) {
		case 'o':
			lvl[(int)(YPosition + HitBoxY / 2.0) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)] = ' ';
			Rings++;
		break;
	}



}

void CharacterFactory::UpdatedScore(Text ScoreText, int ScoreAdd) {
	this->Score += ScoreAdd;
	ScoreText.setString(to_string(Score));
}
