#include "Menu.h"

Menu::Menu(){
	BackgroundFrame = 0;
	CurrentChoice = 1;

	MenuBackGroundTexture.loadFromFile("Data/Menu/Background.png");
	MenuBackGroundSprite.setTexture(MenuBackGroundTexture);

	MenuForeGroundTexture.loadFromFile("Data/Menu/Menu.png");
	MenuForeGroundSprite.setTexture(MenuForeGroundTexture);

	MenuButtonTexture1.loadFromFile("Data/Menu/Button1.png");
	MenuButtonTexture2.loadFromFile("Data/Menu/Button2.png");
}

void Menu::Update(RenderWindow* window, int& GameState, Event event) {

	if (MenuClock.getElapsedTime().asMilliseconds() >= 50) {
		MenuClock.restart();
		if (Keyboard::isKeyPressed(Keyboard::W) && CurrentChoice > 1) {
			CurrentChoice -= 1; // Upper Option
			cout << CurrentChoice << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::S) && CurrentChoice < 4) {
			CurrentChoice += 1; // Lower Option
			cout << CurrentChoice << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			GameState = CurrentChoice;
		}
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

	if (CurrentChoice == 1) {
		MenuButtonSprite.setTexture(MenuButtonTexture2);

		MenuButtonSprite.setPosition(419, 310); // 1 
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setTexture(MenuButtonTexture1);

		MenuButtonSprite.setPosition(419, 434); // 2
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setPosition(419, 557); // 3
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setPosition(419, 681); // 4
		window->draw(MenuButtonSprite);

	}
		
	else if (CurrentChoice == 2) {
		MenuButtonSprite.setTexture(MenuButtonTexture1);

		MenuButtonSprite.setPosition(419, 310); // 1 
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setTexture(MenuButtonTexture2);

		MenuButtonSprite.setPosition(419, 434); // 2
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setTexture(MenuButtonTexture1);

		MenuButtonSprite.setPosition(419, 557); // 3
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setPosition(419, 681); // 4
		window->draw(MenuButtonSprite);
	}
		
	else if (CurrentChoice == 3) {
		MenuButtonSprite.setTexture(MenuButtonTexture1);

		MenuButtonSprite.setPosition(419, 310); // 1 
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setPosition(419, 434); // 2
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setTexture(MenuButtonTexture2);

		MenuButtonSprite.setPosition(419, 557); // 3
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setTexture(MenuButtonTexture1);

		MenuButtonSprite.setPosition(419, 681); // 4
		window->draw(MenuButtonSprite);
	}
		
	else if (CurrentChoice == 4) {
		MenuButtonSprite.setTexture(MenuButtonTexture1);

		MenuButtonSprite.setPosition(419, 310); // 1 
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setPosition(419, 434); // 2
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setPosition(419, 557); // 3
		window->draw(MenuButtonSprite);

		MenuButtonSprite.setTexture(MenuButtonTexture2);

		MenuButtonSprite.setPosition(419, 681); // 4
		window->draw(MenuButtonSprite);

	}

	window->display();
	window->clear();
}
