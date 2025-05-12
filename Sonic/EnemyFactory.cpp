#include "EnemyFactory.h"

bool EnemyFactory::CheckCollision(int X, int Y, int HitX, int HitY) {
	bool collided = false;

	int points[6][2] = { {X,Y},{X,Y + HitY},{X + HitX,Y} ,{X + HitX,Y + HitY},{X,Y + HitY / 2},{X + HitX / 2,Y} };

	for (int i = 0; i < 6; i++) {
		if (points[i][0] > XPosition && points[i][0] < XPosition + HitBoxX && points[i][1] > YPosition && points[i][1] < YPosition + HitBoxY) {
			collided = true;
		}
	}

	return collided;
}

int EnemyFactory::getHP() {
	return HP;
}

void EnemyFactory::ChangeHP(int Diff) {
	if (HurtTimer.getElapsedTime().asSeconds() > 0.1) {
		HurtTimer.restart();
		HP += Diff;
	}
}
