#include "SoundBoard.h"
#include "Game.h"

SoundBoard::SoundBoard() {
	
	font.load("Data/CustomFont");
	font2.load();
	font3.load();
	font4.load();
	MenuBackGroundTexture.loadFromFile("Data/Soundboard.png");
	MenuBackGroundSprite.setTexture(MenuBackGroundTexture);

	
	MenuForeGroundTexture.loadFromFile("Data/Menu/MenuForeground.png");
	MenuForeGroundSprite.setTexture(MenuForeGroundTexture);
	MenuForeGroundSprite.setColor(Color(91, 204, 81));

	MenuButtonTexture.loadFromFile("Data/Menu/Button2.png");
	MenuButtonSprite.setTexture(MenuButtonTexture);
	MenuButtonSprite.setColor(Color(91, 204, 81));

	CurrentChoice = 1;
	VolumeSelector = 0;
}

void SoundBoard::Update(bool& MusicOn, int& Volume) {
	if (MenuClock.getElapsedTime().asMilliseconds() >= 200) {
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			MenuClock.restart();
			CurrentChoice--;
			if (CurrentChoice < 1) CurrentChoice = 2;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			MenuClock.restart();
			CurrentChoice++;
			if (CurrentChoice > 2) CurrentChoice = 1;
		}
		else if (CurrentChoice == 1 && Keyboard::isKeyPressed(Keyboard::Left)) {
			MenuClock.restart();
			VolumeSelector = 0;
			if (Volume - 10 >= 0) Volume -= 10;
		}
		else if (CurrentChoice == 1 && Keyboard::isKeyPressed(Keyboard::Right)) {
			MenuClock.restart();
			VolumeSelector = 1;
			if (Volume + 10 <= 100) Volume += 10;
		}
		else if (CurrentChoice == 2 && Keyboard::isKeyPressed(Keyboard::Enter)) {
			MenuClock.restart();
			MusicOn = !MusicOn;
		}
	}
}

void SoundBoard::Draw(RenderWindow* window, int& Volume, bool& MusicOn) {
	window->draw(MenuForeGroundSprite);
	window->draw(MenuBackGroundSprite);

	font.draw(window, "Options", 455, 80, 3, 20, 6.5, Color(53, 166, 43));
	font.draw(window, "Volume\nBackground Music ", 170, 270, 3, 20, 5.5, Color(53, 166, 43), 32);

	MenuButtonSprite.setPosition(540, 250);
	MenuButtonSprite.setColor((CurrentChoice == 1 && VolumeSelector == 0) ? Color::Red : Color(91, 204, 81));
	window->draw(MenuButtonSprite);

	font2.setOutlineColor((CurrentChoice == 1 && VolumeSelector == 0) ? Color::Red :
		(CurrentChoice == 1 && VolumeSelector == 1) ? Color(0, 71, 255) :
		Color(91, 204, 81));
	font2.draw(window, to_string(Volume), 675, 275, 3, 20, 5, Color(53, 166, 43),20,1);

	font.draw(window, "-", 565, 280, 3, 20, 4, Color(53, 166, 43),20,1);
	font.setOutlineColor((CurrentChoice == 1 && VolumeSelector == 0) ? Color::Red : Color(91, 204, 81));
	
	MenuButtonSprite.setPosition(835, 250);
	MenuButtonSprite.setColor((CurrentChoice == 1 && VolumeSelector == 1) ? Color(0, 71, 255) : Color(91, 204, 81));
	window->draw(MenuButtonSprite);
	font3.draw(window, "+", 860, 280, 3, 20, 4, Color(53, 166, 43), 20, 1);
	font3.setOutlineColor((CurrentChoice == 1 && VolumeSelector == 1) ? Color(0, 71, 255) : Color(91, 204, 81));

	MenuButtonSprite.setPosition(940, 425);
	MenuButtonSprite.setColor((CurrentChoice == 2) ? Color::White : Color(91, 204, 81));
	font4.draw(window, MusicOn ? "ON" : "OFF", 1050, 455, 3, 20, 4, (MusicOn ? Color(0, 71, 255) : Color::Red), 20, 1);
	font4.setOutlineColor((MusicOn ? Color(0, 71, 255) : Color::Red));
	window->draw(MenuButtonSprite);

	window->display();
	window->clear();
}