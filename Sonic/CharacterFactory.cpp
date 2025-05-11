#include "CharacterFactory.h"

int CharacterFactory::HP = 3;

CharacterFactory::CharacterFactory(int MSpeed): Moveable() {
	jumpBuffer.loadFromFile("Data/Sounds/Jump.wav");
	jumpSound.setBuffer(jumpBuffer);

	ringBuffer.loadFromFile("Data/Sounds/Ring.wav");
	ringSound.setBuffer(ringBuffer);

	int Actions[7] = { 1, 12, 10, 8, 16, 10, 8 };
	ObjectAnimation.setActions(Actions);

	Scale = 2;
	XPosition = 3 * 64;
	YPosition = 7 * 64;
	XSpeed = 0;
	YSpeed = 0;

	HitBoxX = 48 * Scale;
	HitBoxY = 48 * Scale;

	MaxSpeed = MSpeed;
	OnGround = false;
	IsFlying = false;
	Boosted = 0;
	BoostTimer = 0;
}

float CharacterFactory::getXPosition() {
	return XPosition;
}

float CharacterFactory::getYPosition() {
	return YPosition;
}

float CharacterFactory::getHitBoxX() {
	return HitBoxX;
}

float CharacterFactory::getHitBoxY() {
	return HitBoxY;
}

bool CharacterFactory::AttackMode() {
	return (IsFlying == false && YSpeed != 0);
}

void CharacterFactory::Teleport(int X, int Y) {
	XPosition = X * 64;
	YPosition = Y * 64;
}

float CharacterFactory::Gravity = 1;
float CharacterFactory::TerminalVelocity = 20;
float CharacterFactory::Acceleration = 0.5;
float CharacterFactory::Friction = 2;
float CharacterFactory::JumpStrength = -20;

int CharacterFactory::Rings = 0;
int CharacterFactory::Score = 0;

void CharacterFactory::setGravity(float grav) {
	Gravity = grav;
}

void CharacterFactory::setFriction(float Fric) {
	Friction = Fric;
}

void CharacterFactory::setScore(float score) {
	Score += score;
}

void CharacterFactory::ApplyGravity(char** lvl, const int cell_size)
{
	float offset_y = YPosition + YSpeed;

	char bottom_left_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char bottom_mid_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)];
	char bottom_right_down = lvl[(int)(offset_y + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];

	char bottom_left_down2 = lvl[(int)(offset_y + HitBoxY - 10) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char bottom_mid_down2 = lvl[(int)(offset_y + HitBoxY - 10) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)];
	char bottom_right_down2 = lvl[(int)(offset_y + HitBoxY - 10) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];

	char WallCharac[7] = { 'w','p','q','e','b','B','\0' };

	OnGround = false;
	bool inGround = false;

	for (int i = 0; i < 6;i++) {
		if ((bottom_left_down == WallCharac[i] || bottom_mid_down == WallCharac[i] || bottom_right_down == WallCharac[i])){
			OnGround = true;
		}
	}

	for (int i = 0; i < 6;i++) {
		if (bottom_left_down2 == WallCharac[i] || bottom_mid_down2 == WallCharac[i] || bottom_right_down2 == WallCharac[i]) {
			inGround = true;
		}
	}

	if (!OnGround)
	{
		YSpeed += Gravity;
		if (YSpeed >= TerminalVelocity) YSpeed = TerminalVelocity;
	}
	else if (YSpeed > 0) {
		YSpeed = 0;
	}
	else if (YSpeed == 0 && inGround) {
		YSpeed = 5;
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

	char bottom_left_down2 = lvl[(int)(YPosition + HitBoxY - 10) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char bottom_mid_down2 = lvl[(int)(YPosition + HitBoxY - 10) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)];
	char bottom_right_down2 = lvl[(int)(YPosition + HitBoxY - 10) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];


	char WallCharac[7] = { 'w','p','q','e','b','B','\0' };

	OnGround = false;
	bool inGround = false;

	for (int i = 0; i < 6;i++) {
		if (bottom_left_down2 == WallCharac[i] || bottom_mid_down2 == WallCharac[i] || bottom_right_down2 == WallCharac[i]) {
			inGround = true;
		}
	}

	for (int i = 0; i < 6;i++) {
		if ((bottom_left_down == WallCharac[i] || bottom_mid_down == WallCharac[i] || bottom_right_down == WallCharac[i]))
		{
			OnGround = true;
		}
	}

	if (OnGround && YSpeed == 0 && !inGround) {
		YSpeed += JumpStrength;
		jumpSound.play();
	}

}

void CharacterFactory::MoveTo(char** lvl, const int cell_size, int X) {

	if (X - XPosition > 10 * cell_size) {
		for (int i = 13; i > 0; i--) {
			if (lvl[i][(int)((X + HitBoxX) / cell_size - 10)] == ' ' && lvl[i + 1][(int)((X + HitBoxX) / cell_size - 10)] == ' ') {
				Teleport((int)((X + HitBoxX) / cell_size - 10), i);
			}
		}
	}

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

	if (XSpeed == 0) {
		ObjectAnimation.setAction(2, 0);
	}

	if (!OnGround && YSpeed != 0) {
		ObjectAnimation.setAction(2, 4);
	}

	XPosition += XSpeed;
	YPosition += YSpeed;
}

void CharacterFactory::Animate() {
	ObjectAnimation.NextFrame(ObjectSprite, ObjectTexture, HitBoxX / 2, HitBoxY / 2);
}

void CharacterFactory::CheckCollisionGrid(char** lvl, const int cell_size, Clock& RingClock,int& CurrentLevel) {

	float offset_x = XPosition + XSpeed;

	// Falling

	char WallCharac[7] = { 'w','p','q','e','b','B','\0' };

	char bottom_left_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 - 10) / cell_size))];
	char bottom_mid_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)];
	char bottom_right_down = lvl[(int)(YPosition + HitBoxY) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 + 10) / cell_size))];

	for (int i = 0; i < 6;i++) {
		if ((bottom_left_down == WallCharac[i] && bottom_mid_down == ' ') && OnGround) {
			ObjectAnimation.setAction(0, 6);
		}
		else if ((bottom_mid_down == ' ' && bottom_right_down == WallCharac[i]) && OnGround) {
			ObjectAnimation.setAction(1, 6);
		}
	}

	// Top
	
	float offset_y = YPosition + YSpeed;

	char LeftUp = lvl[(int)(offset_y + HitBoxY / 4.0) / cell_size][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0 + 10) / cell_size))];
	char MidUp = lvl[(int)(offset_y + HitBoxY / 4.0) / cell_size][(int)((XPosition + HitBoxX / 2.0) / cell_size)];
	char RightUp = lvl[(int)(offset_y + HitBoxY / 4.0) / cell_size][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0 - 10) / cell_size))];

	char WallCharacUp[6] = { 'w','q','e','b','B','\0'};

	for (int i = 0; i < 5;i++) {
		if (LeftUp == WallCharacUp[i] || MidUp == WallCharacUp[i] || RightUp == WallCharacUp[i]) {
			YSpeed = 0;
		}
	}

	// Left And Right

	char LeftD = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))];
	char MidD = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0) / cell_size))];
	char RightD = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))];

	char LeftM = lvl[(int)((YPosition + HitBoxY/2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))];
	char RightM = lvl[(int)((YPosition + HitBoxY/2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))];

	char LeftU = lvl[(int)((YPosition + 20) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))];
	char RightU = lvl[(int)((YPosition + 20) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))];

	if (XSpeed > 0) {
		switch (RightD) {
		case 'w':
		case 'q':
		case 'e':
		case 'b':
		case 'B':
			XSpeed = 0;
			ObjectAnimation.setAction(0, 5);
			break;
		case 'o':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = ' ';
				Rings++;
				ringSound.play();
			}
			break;
		case 'u':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = 'U';
				Boosted = true;
			}
			break;
		case 'h':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = 'H';
				HP++;
			}
			break;
		case 'f':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				CurrentLevel++;
			}
			break;
		}


		switch (RightM) {
		case 'w':
		case 'q':
		case 'e':
		case 'b':
		case 'B':
			XSpeed = 0;
			ObjectAnimation.setAction(0, 5);
			break;
		case 'o':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = ' ';
				Rings++;
				ringSound.play();
			}
			break;
		case 'u':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = 'U';
				Boosted = true;
			}
			break;
		case 'h':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = 'H';
				HP++;
			}
			break;
		case 'f':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				CurrentLevel++;
			}
			break;
		}

		switch (RightU) {
		case 'w':
		case 'q':
		case 'e':
		case 'b':
		case 'B':
			XSpeed = 0;
			break;
		case 'o':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + 20) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = ' ';
				Rings++;
				ringSound.play();
			}
			break;
		case 'u':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + 20) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = 'U';
				Boosted = true;
			}
			break;
		case 'h':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + 20) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 + HitBoxX / 4.0 - 5) / cell_size))] = 'H';
				HP++;
			}
			break;
		case 'f':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				CurrentLevel++;
			}
			break;
		}
	}
	else if (XSpeed < 0) {
		switch (LeftD) {
		case 'w':
		case 'q':
		case 'e':
		case 'b':
		case 'B':
			XSpeed = 0;
			ObjectAnimation.setAction(1, 5);
			break;
		case 'o':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = ' ';
				Rings++;
				ringSound.play();
			}
			break;
		case 'u':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = 'U';
				Boosted = true;
			}
			break;
		case 'h':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = 'H';
				HP++;
			}
			break;
		case 'f':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				CurrentLevel++;
			}
			break;
		}

		switch (LeftM) {
		case 'w':
		case 'q':
		case 'e':
		case 'b':
		case 'B':
			XSpeed = 0;
			ObjectAnimation.setAction(1, 5);
			break;
		case 'o':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = ' ';
				Rings++;
				ringSound.play();
			}
			break;
		case 'u':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = 'U';
				Boosted = true;
			}
			break;
		case 'h':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = 'H';
				HP++;
			}
			break;
		case 'f':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				CurrentLevel++;
			}
			break;
		}

		switch (LeftU) {
		case 'w':
		case 'q':
		case 'e':
		case 'b':
		case 'B':
			XSpeed = 0;
			break;
		case 'o':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + 20) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = ' ';
				Rings++;
				ringSound.play();
			}
			break;
		case 'u':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + 20) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = 'U';
				Boosted = true;
			}
			break;
		case 'h':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				lvl[(int)((YPosition + 20) / cell_size)][(int)(((offset_x + HitBoxX / 2.0 - HitBoxX / 4.0 + 5) / cell_size))] = 'H';
				HP++;
			}
			break;
		case 'f':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				CurrentLevel++;
			}
			break;
		}
	}

	switch (MidD) {
	case 'o':
		if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
			RingClock.restart();
			lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0) / cell_size))] = ' ';
			Rings++;
			ringSound.play();
		}
		break;
	case 'u':
		if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
			RingClock.restart();
			lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0) / cell_size))] = 'U';
			Boosted = true;
		}
		break;
	case 'h':
		if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
			RingClock.restart();
			lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((offset_x + HitBoxX / 2.0) / cell_size))] = 'H';
			HP++;
		}
		break;
	case 'f':
			if (RingClock.getElapsedTime().asMilliseconds() >= 10) {
				RingClock.restart();
				CurrentLevel++;
			}
			break;
	}

}

void CharacterFactory::UpdatedScore(int Add) {
	this->Score += Add;
}

void CharacterFactory::UpdatedRings(int Add) {
	this->Rings += Add;
}

void CharacterFactory::UpdatedHP(Clock& InvincilibityClock, int Add) {
	if (InvincilibityClock.getElapsedTime().asSeconds() >= 1) {
		InvincilibityClock.restart();
		this->HP += Add;
	}
}

void CharacterFactory::SpikeCollisions(char** lvl, const int cell_size, Clock& InvincilibityClock) {

	float offset_x = XPosition + XSpeed;

	char LeftD = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0) / cell_size))];
	char MidD = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0) / cell_size))];
	char RightD = lvl[(int)((YPosition + HitBoxY - 1) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0) / cell_size))];

	char LeftM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0) / cell_size))];
	char RightM = lvl[(int)((YPosition + HitBoxY / 2.0) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0) / cell_size))];

	char LeftU = lvl[(int)((YPosition + 20) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 - HitBoxX / 4.0) / cell_size))];
	char RightU = lvl[(int)((YPosition + 20) / cell_size)][(int)(((XPosition + HitBoxX / 2.0 + HitBoxX / 4.0) / cell_size))];

	if (XSpeed > 0) {
		if (RightD == 's' || RightM == 's' || RightU == 's') {
			UpdatedHP(InvincilibityClock, -1);
		}
	}
	else if (XSpeed < 0) {
		if (LeftD == 's' || LeftM == 's' || LeftU == 's') {
			UpdatedHP(InvincilibityClock, -1);
		}
	}

	if (MidD == 's') {
		UpdatedHP(InvincilibityClock, -1);
		YSpeed = -20;
	}
}
