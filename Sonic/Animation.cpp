#include "Animation.h"

Animation::Animation(): Direction(0), CurrentFrame(0), PreviousAction(1), NextAction(1), PreviousDirection(0){
	Action[0] = 7;
}

void Animation::setActions(int Array[7]) {
	for (int i = 0; i < 7;i++) {
		Action[i] = Array[i];
	}
}

int Animation::getDirection() {
	return Direction;
}


void Animation::setAction(int Direc,int NextAct) {
	if (Direc != 2) {
		Direction = Direc;
	}
		NextAction = NextAct;
}

void Animation::NextFrame(Sprite& ObjectSprite, Texture& ObjectTexture, int x, int y) {

	if (PreviousAction != NextAction || PreviousDirection != Direction) {
		CurrentFrame = 0;
	}
	else {
		CurrentFrame++;

		if (CurrentFrame >= Action[PreviousAction]) {
			CurrentFrame = 0;
		}
	}

	PreviousDirection = Direction;
	PreviousAction = NextAction;
	if (PreviousDirection == 1) {
		ObjectSprite.setTextureRect(IntRect((Action[PreviousAction] * (x + 1) * PreviousDirection) - (CurrentFrame + 1) * (x + 1) + 1, PreviousAction * (y + 1) * 2 + (y + 1) * PreviousDirection, x, y));
	}
	else{
		ObjectSprite.setTextureRect(IntRect(CurrentFrame * (x + 1) + 1, PreviousAction * (y + 1) * 2 + (y + 1) * PreviousDirection, x, y));
	}
	
}
