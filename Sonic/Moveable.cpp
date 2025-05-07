#include "Moveable.h"

Moveable::Moveable(): ObjectAnimation() {}

Moveable::~Moveable() {

}

void Moveable::DrawMoveable(RenderWindow* window,float PlayerX) {
	ObjectSprite.setPosition(XPosition - PlayerX, YPosition);
	window->draw(ObjectSprite);
}

