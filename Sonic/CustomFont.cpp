#include "CustomFont.h"

using namespace std;
using namespace sf;

int CustomFont::findIndex(char c) {
    for (int i = 0; i < CharacterCount; i++)
        if (FC[i].ch == c)
            return i;
    return -1;
}

void CustomFont::load(const string& folderPath) {
    for (char c = 'A'; c <= 'Z'; c++) {
        Texture tex, outlineTex;
        tex.loadFromFile(folderPath + "/" + c + ".png");
        outlineTex.loadFromFile(folderPath + "/Outline/" + c + "_outline.png");
        FC[CharacterCount++] = { c, tex, outlineTex };
    }

    for (char c = '0'; c <= '9'; c++) {
        Texture tex, outlineTex;
        tex.loadFromFile(folderPath + "/" + c + ".png");
        outlineTex.loadFromFile(folderPath + "/Outline/" + c + "_outline.png");
        FC[CharacterCount++] = { c, tex, outlineTex };
    }

    Texture fullstop, fullstopOutline;
    fullstop.loadFromFile(folderPath + "/..png");
    fullstopOutline.loadFromFile(folderPath + "/Outline/._outline.png");
    FC[CharacterCount++] = { '.', fullstop, fullstopOutline };

    Texture comma, commaOutline;
    comma.loadFromFile(folderPath + "/,.png");
    commaOutline.loadFromFile(folderPath + "/Outline/,_outline.png");
    FC[CharacterCount++] = { ',', comma, commaOutline };

    Texture semicolon, semicolonOutline;
    semicolon.loadFromFile(folderPath + "/sc.png");
    semicolonOutline.loadFromFile(folderPath + "/Outline/sc_outline.png");
    FC[CharacterCount++] = { ':', semicolon, semicolonOutline };

    Texture dash, dashOutline;
    dash.loadFromFile(folderPath + "/-.png");
    dashOutline.loadFromFile(folderPath + "/Outline/-_outline.png");
    FC[CharacterCount++] = { '-', dash, dashOutline };

}

void CustomFont::draw(RenderWindow& window, const string& Text, float x, float y, float LetterSpacing, float WordSpacing, float Scale, Color OutlineColor, Color TextColor) {
    for (int i = 0; i < Text.size(); ++i) {
        char c = Text[i];

        if (c >= 'a' && c <= 'z') c -= 32;

        // Handle space
        if (c == ' ') {
            x += WordSpacing;
            continue;
        }

        int index = findIndex(c);
        if (index != -1) {
            const Texture& tex = FC[index].texture;
            const Texture& outlineTex = FC[index].outlineTexture;

            if (outlineTex.getSize().x > 0 && outlineTex.getSize().y > 0) {
                Sprite outlineSprite;
                outlineSprite.setTexture(outlineTex);
                outlineSprite.setScale(Scale, Scale);
                outlineSprite.setPosition(x, y);
                outlineSprite.setColor(OutlineColor);
                window.draw(outlineSprite);
            }

            Sprite sprite;
            sprite.setTexture(tex);
            sprite.setScale(Scale, Scale);
            sprite.setPosition(x, y);
            sprite.setColor(TextColor);
            window.draw(sprite);

            x += tex.getSize().x * Scale + LetterSpacing;
        }
    }
}

