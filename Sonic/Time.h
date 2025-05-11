#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;


class TClass
{
	Clock PlayerClock;
	Clock SwitchClock;
	Clock AnimationClock1;
	Clock AnimationClock2;
	Clock RingClock;
	Clock AbilityClock;
	Clock InvincilibityClock;
public:

	Clock& getPlayerClock();
	Clock& getSwitchClock();
	Clock& getAnimationClock1();
	Clock& getAnimationClock2();
	Clock& getRingClock();
	Clock& getAbilityClock();
	Clock& getInvincilibityClock();
};

