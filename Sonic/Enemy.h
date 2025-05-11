#pragma once
#include "Moveable.h"

class Enemy : public Moveable
{
	int SpawnX;
	int SpwanY;
	int HP;

public:

	virtual ~Enemy() {};

	virtual void MovePattern() = 0;
	
};

