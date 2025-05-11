#pragma once
#include "CharacterFactory.h"
class Knuckles : public CharacterFactory
{
public:
    Knuckles();

    bool canFly();
    void UsedAbility(char** lvl, const int cell_size, Clock& AbilityClock, bool& AbilityUsed);
};

