#include "Tails.h"

Tails::Tails() : CharacterFactory(10) {

	ObjectTexture.loadFromFile("Data/Tails.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 48, 48));
	ObjectSprite.setScale(Scale, Scale);
}