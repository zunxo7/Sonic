#pragma once
#include "EnemyFactory.h"
class BeeBot :
    public EnemyFactory
{
public:
    BeeBot(int X, int Y);

    void MovePattern(char** lvl, const int cell_size, float X, float Y) override;
    void Animate() override;

    int Score();
};

