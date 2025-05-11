#pragma once
#include "Moveable.h"

class EnemyFactory : public Moveable
{
protected:
	int SpawnX;
	int SpawnY;
	int HP;
	int AttackTime;
	Clock HurtTimer;
	Clock AttackTimer;

public:

	virtual ~EnemyFactory() {};

	virtual void MovePattern(char** lvl, const int cell_size, float X) = 0;
	virtual void Animate() = 0;
	virtual int Score() = 0;

	bool CheckCollision(int X,int Y,int HitX,int HitY);
	int getHP();
	void ChangeHP(int Diff);
};

