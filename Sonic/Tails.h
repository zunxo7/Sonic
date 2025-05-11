#pragma once
#include "CharacterFactory.h"
class Tails : public CharacterFactory
{
public:
    Tails();

    bool canFly();
    void UsedAbility(char** lvl, const int cell_size, Clock& AbilityClock, bool& AbilityUsed);
};