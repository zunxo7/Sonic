#include "SoundBoard.h"
#include "Game.h"

SoundBoard::SoundBoard() {
	
	font.load("Data/CustomFont");
	MenuBackGroundTexture.loadFromFile("Data/Soundboard.png");
	MenuBackGroundSprite.setTexture(MenuBackGroundTexture);

	
	MenuForeGroundTexture.loadFromFile("Data/Menu/MenuForeground.png");
	MenuForeGroundSprite.setTexture(MenuForeGroundTexture);
	MenuForeGroundSprite.setColor(Color(91, 204, 81));

	MenuButtonTexture.loadFromFile("Data/Menu/Button2.png");
	MenuButtonSprite.setTexture(MenuButtonTexture);
	MenuButtonSprite.setColor(Color(91, 204, 81));
}

void SoundBoard::Update(bool& MusicOn, int& Volume) {

}


void SoundBoard::Draw(RenderWindow* window, int& Volume) {
	window->draw(MenuForeGroundSprite);
	window->draw(MenuBackGroundSprite);
	font.draw(window, "Options", 455, 80, 3, 20, 6.5, Color(53, 166, 43));
	font.draw(window, "Volume\nBackground Music ", 170, 270, 3, 20, 5.5, Color(53, 166, 43),32);
	MenuButtonSprite.setPosition(540, 250);
	window->draw(MenuButtonSprite);
	font.draw(window, "-", 565, 280, 3, 20, 4, Color(53, 166, 43));
	font.draw(window, "10", 675, 275, 3, 20, 5, Color(53, 166, 43));
	MenuButtonSprite.setPosition(800, 250);
	window->draw(MenuButtonSprite);
	font.draw(window, "+", 825, 280, 3, 20, 4, Color(53, 166, 43));
	MenuButtonSprite.setPosition(965, 425);
	window->draw(MenuButtonSprite);

	window->display();
	window->clear();
}