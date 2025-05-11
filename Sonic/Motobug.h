#pragma once
#include "EnemyFactory.h"
class Motobug : public EnemyFactory
{
public:
    Motobug(int X, int Y);

    void MovePattern(char** lvl, const int cell_size,float X);
};

