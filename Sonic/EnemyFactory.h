#pragma once
#include "Moveable.h"

class EnemyFactory : public Moveable
{
protected:
	int SpawnX;
	int SpawnY;
	int HP;
	int AttackTime;

public:

	virtual ~EnemyFactory() {};

	virtual void MovePattern() = 0;
	
};

