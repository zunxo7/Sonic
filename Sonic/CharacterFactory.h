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
	static bool IsInvincable;

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
	void Teleport(int X, int Y);

	void setGravity(float grav);
	void setFriction(float Fric);

	void ApplyGravity(char** lvl, const int cell_size);
	void PlayerMove(char** lvl, const int cell_size, int MaxWidht);
	void Jump(char** lvl, const int cell_size);
	void MoveTo(char** lvl, const int cell_size,int X);
	void Animate();

	void CheckCollisionGrid(char** lvl, const int cell_size, Clock& RingClock, int& CurrentLevel);
	void SpikeCollisions(char** lvl, const int cell_size, Clock& InvincilibityClock);

	void UpdatedScore(int Add = 0);
	void UpdatedRings(int Add = 0);
	void UpdatedHP(Clock& InvincilibityClock, int Add = 0);
	
	static int getRings() { return Rings; }
	static int getScore() { return Score; }
	static int getHP() { return HP; }

	void Update();

};
