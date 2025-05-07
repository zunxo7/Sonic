#include "Knuckles.h"

Knuckles::Knuckles() : CharacterFactory(12) {

	ObjectTexture.loadFromFile("Data/Knuckles.png");
	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(0, 0, 48, 48));
	ObjectSprite.setScale(Scale, Scale);
}
