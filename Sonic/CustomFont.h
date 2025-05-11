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
    Color currentOutlineColor = Color(0, 71, 255);
    Color currentTextColor = Color::White;

    int findIndex(char c);

public:
    void load(const string& folderPath = "Data/CustomFont");
    void draw(RenderWindow* window, const string& text, float x, float y, float LetterSpacing = 3, float WordSpacing = 15, float Scale = 3, Color OutlineColor = Color(0, 71, 255), float LineSpacing = 20, Color TextColor = Color::White);
    void setOutlineColor(Color color);
    void setTextColor(Color color);
};
