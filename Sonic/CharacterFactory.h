#pragma once
#include "Moveable.h"

class CharacterFactory : public Moveable
{
protected:
	float MaxSpeed;
	bool OnGround;
	bool Boosted;
	int BoostTimer;

	static float Gravity;
	static float TerminalVelocity;
	static float Acceleration;
	static float Friction;
	static float JumpStrength;

	static int HP;
	static int Rings;
	static int Score;

public:
	CharacterFactory(int MSpeed);
	virtual ~CharacterFactory() {}

	float getXPosition();
	float getYPosition();

	void ApplyGravity(char** lvl, const int cell_size);
	void PlayerMove(char** lvl, const int cell_size, int MaxWidht);
	void Jump(char** lvl, const int cell_size);
	void MoveTo(char** lvl, const int cell_size,int X);
	void Animate();

	void CheckCollisionGrid(char** lvl, const int cell_size);

	void Update();

};
