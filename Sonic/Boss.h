#pragma once
#include "EnemyFactory.h"
class Boss :
    public EnemyFactory
{
    int PLayerFound;
    bool BottomReached;
    bool StopAnimation;
    Texture SpikeTexture;
    Sprite SpikeSprite;

public:
    Boss(int X, int Y);

    void MovePattern(char** lvl, const int cell_size, float X, float Y) override;
    void Animate() override;

    int Score();
};

