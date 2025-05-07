#include "Animation.h"

Animation::Animation(): Direction(0), CurrentFrame(0), PreviousAction(1){
	Action[0] = 7;
}

void Animation::setActions(int Array[7]) {
	for (int i = 0; i < 7;i++) {
		Action[i] = Array[i];
	}
}


void Animation::NextFrame(Sprite ObjectSprite, Texture ObjectTexture,float Scale, int Direc,int NextAct) {
	if (NextAct == PreviousAction && Direction == Direc) {
		CurrentFrame++;
		if (CurrentFrame > Action[PreviousAction]) {
			CurrentFrame = 0;
		}
	}
	else {
		CurrentFrame = 0;
		Direction = Direc;
		PreviousAction = NextAct;
	}

	ObjectSprite.setTexture(ObjectTexture);
	ObjectSprite.setTextureRect(IntRect(CurrentFrame * 49 + 1, PreviousAction * 49 * 2 + 49 * Direction, 48, 48));
	ObjectSprite.setScale(Scale, Scale);
}
