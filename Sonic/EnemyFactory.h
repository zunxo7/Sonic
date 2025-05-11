#pragma once
#include "Moveable.h"

class EnemyFactory : public Moveable
{
	int SpawnX;
	int SpwanY;
	int HP;

public:

	virtual ~EnemyFactory() {};

	virtual void MovePattern() = 0;
	
};

