#include "Scoreboard.h"
#include <fstream>

Scoreboard::Scoreboard() {
	DataDisplay = false;
	Name = "";
	ScoreString = "";
	MenuForeGroundTexture.loadFromFile("Data/Menu/MenuForeground.png");
	MenuForeGroundSprite.setTexture(MenuForeGroundTexture);
	BackGroundTexture.loadFromFile("Data/Scoreboard.png");
	MenuForeGroundSprite.setColor(Color(175, 20, 12));
	BackGroundSprite.setTexture(BackGroundTexture);
	font.load("Data/CustomFont");
}

void Scoreboard::Update(RenderWindow* window) {
	if (!DataDisplay) {
		string FileDataArray[10][2];
		string CurrentLine;

		ifstream HighScoreFile("Data/HighScoreFile/HighScore.txt");

		for (int i = 0; i < 10; i++) {
			HighScoreFile >> CurrentLine;
			int Count = 0;
			bool isName = true;
			while (CurrentLine[Count] != '\0') {
				if (CurrentLine[Count] == ',') {
					isName = false;
					Count++;
				}
				if (isName) {
					FileDataArray[i][0] += CurrentLine[Count];
					Count++;
				}
				else {
					FileDataArray[i][1] += CurrentLine[Count];
					Count++;
				}
			}
		}

		for (int i = 0; i < 10; i++) {
			Name += FileDataArray[i][0] + '\n';
			ScoreString += FileDataArray[i][1] + '\n';
		}

		DataDisplay = true;
	}
}

void Scoreboard::Draw(RenderWindow* window) {

	window->draw(MenuForeGroundSprite);
	window->draw(BackGroundSprite);
	font.draw(window, "High Score", 425, 60, 3, 20, 6, Color(175, 20, 12));
	font.draw(window, Name,428, 190, 3, 15, 3, Color(175, 20, 12));
	font.draw(window, ScoreString, 760, 190, 3, 15, 3, Color(175, 20, 12));

	window->display();
	window->clear();
}
