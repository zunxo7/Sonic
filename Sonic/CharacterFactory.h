#pragma once
#include "Moveable.h"

class CharacterFactory : public Moveable
{
protected:
	float MaxSpeed;
	bool OnGround;
	bool IsFlying;
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

	virtual bool canFly() = 0;
	virtual void UsedAbility(char** lvl, const int cell_size, Clock& AbilityClock, bool& AbilityUsed) = 0;

	float getXPosition();
	float getYPosition();

	void ApplyGravity(char** lvl, const int cell_size);
	void PlayerMove(char** lvl, const int cell_size, int MaxWidht);
	void Jump(char** lvl, const int cell_size);
	void MoveTo(char** lvl, const int cell_size,int X);
	void Animate();

	void CheckCollisionGrid(char** lvl, const int cell_size, Clock& RingClock);
	void UpdatedScore(Text& ScoreText,int Add = 0);
	void UpdatedRings(Text& RingText, int Add = 0);
	void UpdatedHP(Text& HpText, int Add = 0);

	void Update();

};
