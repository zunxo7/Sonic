#pragma once

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;



struct FontCharacter {
    char ch;
    Texture texture;
    Texture outlineTexture;
};

class CustomFont {
private:
    FontCharacter FC[42];
    int CharacterCount = 0;

    int findIndex(char c);

public:
    void load(const string& folderPath);
    void draw(RenderWindow& window, const string& text, float x, float y, float LetterSpacing = 3, float WordSpacing = 15, float Scale = 5, Color OutlineColor = Color(0, 71, 255), Color TextColor = Color::White);
};
