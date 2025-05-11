#include "Menu.h"

Menu::Menu(){
	BackgroundFrame = 0;
	CurrentChoice = 1;
	font.load("Data/CustomFont");
	MenuBackGroundTexture.loadFromFile("Data/Menu/Background.png");
	MenuBackGroundSprite.setTexture(MenuBackGroundTexture);

	LogoTexture.loadFromFile("Data/Menu/Logo.png");
	LogoSprite.setTexture(LogoTexture);

	MenuForeGroundTexture.loadFromFile("Data/Menu/MenuForeground.png");
	MenuForeGroundSprite.setTexture(MenuForeGroundTexture);
	MenuForeGroundSprite.setColor(Color(0, 71, 255));

	MenuButtonTexture.loadFromFile("Data/Menu/Button.png");

}

void Menu::Update(RenderWindow* window, int& GameState, Event event) {

	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		if (MenuClock.getElapsedTime().asMilliseconds() >= 200) {
			MenuClock.restart();
			CurrentChoice -= 1; // Upper Option
			if (CurrentChoice < 1) CurrentChoice = 4;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		if (MenuClock.getElapsedTime().asMilliseconds() >= 200) {
			MenuClock.restart();
			CurrentChoice += 1; // Lower Option
			if (CurrentChoice > 4) CurrentChoice = 1;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter)) {
		GameState = CurrentChoice;
	}

	Draw(window);
}

void Menu::Draw(RenderWindow* window) {

	window->draw(MenuBackGroundSprite);

	if (MenuDisplayClock.getElapsedTime().asMilliseconds() >= 50) {
		MenuDisplayClock.restart();
		BackgroundFrame++;

		if (BackgroundFrame > 120) {
			BackgroundFrame = 0;
		}

		MenuBackGroundSprite.setTextureRect(IntRect(10 * BackgroundFrame, 0, 1200, 900));
	}

	window->draw(MenuForeGroundSprite);

	LogoSprite.setTexture(LogoTexture);
	LogoSprite.setPosition(429.6, 44.3);
	window->draw(LogoSprite);

	MenuButtonSprite.setTexture(MenuButtonTexture);
	
	float posX = 418.9;
	float posY[] = {310.4, 431.4, 557.1, 680.5};

	for (int i = 0; i < 4; i++) {
		MenuButtonSprite.setPosition(posX, posY[i]);
		if (i + 1 == CurrentChoice) {
			if (i + 1 == 4) {
				MenuButtonSprite.setColor(Color(175, 20, 12));
			}
			else {
				MenuButtonSprite.setColor(Color(209, 144, 0));
			}
		}
		else
			MenuButtonSprite.setColor(Color(0, 71, 255));
		window->draw(MenuButtonSprite);
	}

	font.draw(window, "new game", 510, 338.5, 3, 15, 3.6);
	font.draw(window, "options", 530, 456, 3, 15, 3.7);
	font.draw(window, "continue", 512, 584, 3, 15, 3.7);
	font.draw(window, "leaderboard", 476, 714, 3, 15, 3.4);

	Color backgroundColor(22, 29, 28);
	window->display();
	window->clear(backgroundColor);
}
