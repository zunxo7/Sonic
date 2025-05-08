#include "Tails.h"

Tails::Tails() : CharacterFactory(10) {
	int Actions[7] = { 1, 12, 10, 8, 6, 10, 8 };
	ObjectAnimation.setActions(Actions);

	ObjectTexture.loadFromFile("Data/Tails.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 48, 48));
	ObjectSprite.setScale(Scale, Scale);
}