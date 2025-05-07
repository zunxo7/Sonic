#include "Game.h"
#include "Sonic.h"
#include "Tails.h"
#include "Knuckles.h"

using namespace sf;
using namespace std;

// prototypes 
void player_gravity(char** lvl, float& offset_y, float& velocityY, bool& onGround, float& gravity, float& terminal_Velocity, int& hit_box_factor_x, int& hit_box_factor_y, float& player_x, float& player_y, const int cell_size, int& Pheight, int& Pwidth);

void draw_player(RenderWindow& window, Sprite& LstillSprite, float player_x, float player_y);

void display_level(RenderWindow& window, const int height, const int width, char** lvl, Sprite& wallSprite1, const int cell_size);

int main()
{
	/////////////////////////////////////////////////////////////////
	// a cell is 64 by 64 pixels

	// 's' is regular space
	// 'q' is wall1 or floor1
	// 'w' is wall2 or floor2
	// 'e' is wall3 or floor3
	// 'b' is breakable wall
	// 'z' is spring

	// Uppercase for not interactable background accessories

	// C is for crystals

	Texture wallTex1;
	Sprite wallSprite1;

	Music lvlMus;

	lvlMus.openFromFile("Data/labrynth.ogg");
	lvlMus.setVolume(30);
	lvlMus.play();
	lvlMus.setLoop(true);

	////////////////////////////////////////////////////////

	float jumpStrength = -20; // Initial jump velocity
	float gravity = 1;  // Gravity acceleration

	Texture LstillTex;
	Sprite LstillSprite;

	bool onGround = false;

	float offset_x = 0;
	float offset_y = 0;

	float terminal_Velocity = 20;

	float acceleration = 0.2;

	float scale_x = 2.5;
	float scale_y = 2.5;

	////////////////////////////
	int raw_img_x = 24;
	int raw_img_y = 35;

	int Pheight = raw_img_y * scale_y;
	int Pwidth = raw_img_x * scale_x;

	//only to adjust the player's hitbox

	int hit_box_factor_x = 8 * scale_x;
	int hit_box_factor_y = 5 * scale_y;

	LstillTex.loadFromFile("Data/0left_still.png");
	LstillSprite.setTexture(LstillTex);
	LstillSprite.setScale(scale_x, scale_y);

	////////////////////////////////////////////////////////

	Sonic MySonic;
	Tails MyTails;
	Knuckles MyKnucles;

	Game MyGame(&MySonic, &MyTails, &MyKnucles);

	while (MyGame.running()) {
		MyGame.update();
		MyGame.Draw();
	}

	return 0;
}


// functions


void draw_player(RenderWindow& window,Sprite& LstillSprite,float player_x,float player_y) {

	LstillSprite.setPosition(player_x, player_y);
	window.draw(LstillSprite);

}
void display_level(RenderWindow& window,const int height, const int width,char** lvl,Sprite&wallSprite1,const int cell_size)
{
	for (int i = 0; i < height; i += 1)
	{
		for (int j = 0; j < width; j += 1)
		{
			if (lvl[i][j] == 'w')
			{
				wallSprite1.setPosition(j * cell_size, i * cell_size);
				window.draw(wallSprite1);
			}
		}
	}
}