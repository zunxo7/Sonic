#include "Sonic.h"

Sonic::Sonic(): CharacterFactory(18) {

	ObjectTexture.loadFromFile("Data/Sonic.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 48, 48));
	ObjectSprite.setScale(Scale, Scale);
}