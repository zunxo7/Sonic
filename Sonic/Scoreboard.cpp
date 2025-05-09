#include "Scoreboard.h"

Scoreboard::Scoreboard() {

	DataDisplay = false;
	Name = "";
	ScoreString = "";

	ScoreFont.loadFromFile("Data/Fonts/ScoreFont.ttf");

	// High Score Names
	HSNamesText.setFont(ScoreFont);
	HSNamesText.setCharacterSize(20);
	HSNamesText.setPosition(1200 / 4 + 2 * 64, 900 / 4);

	// High Score Scores
	HSScoreText.setFont(ScoreFont);
	HSScoreText.setCharacterSize(20);
	HSScoreText.setPosition(1200 / 4 * 2 + 2 * 64, 900 / 4);

	HighScoreTitle.setFont(ScoreFont);
	HighScoreTitle.setCharacterSize(90);
	HighScoreTitle.setPosition(1200 / 4, 900 / 4 - 3 * 64);
	HighScoreTitle.setString("HighScore");

}


void Scoreboard::Update(RenderWindow* window) {

	if (DataDisplay == false) {

		string FileDataArray[10][2]; // To Store File Data

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
			Name = Name + '\n' + FileDataArray[i][0];
			ScoreString = ScoreString + '\n' + FileDataArray[i][1];
		}

		HSNamesText.setString(Name);
		HSScoreText.setString(ScoreString);

		DataDisplay = true;

	}
}


void Scoreboard::Draw(RenderWindow* window) {
	window->draw(HSNamesText);
	window->draw(HSScoreText);
	window->draw(HighScoreTitle);

	window->display();
	window->clear();
}