#pragma once
#include "CharacterFactory.h"

class Sonic : public CharacterFactory
{
public:
	Sonic();

	bool canFly();
	void UsedAbility(char** lvl, const int cell_size, Clock& AbilityClock, bool& AbilityUsed);
};

