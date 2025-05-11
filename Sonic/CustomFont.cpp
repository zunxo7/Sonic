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

    Texture underscore, underscoreOutline;
    underscore.loadFromFile(folderPath + "/_.png");
    underscoreOutline.loadFromFile(folderPath + "/Outline/__outline.png");
    FC[CharacterCount++] = { '_', underscore, underscoreOutline };

    Texture plus, plusOutline;
    plus.loadFromFile(folderPath + "/+.png");
    plusOutline.loadFromFile(folderPath + "/Outline/+_outline.png");
    FC[CharacterCount++] = { '+', plus, plusOutline };

}

void CustomFont::draw(RenderWindow* window, const string& Text, float x, float y, float LetterSpacing, float WordSpacing, float Scale, Color OutlineColor,float LineSpacing, Color TextColor) {
    float originalX = x;
    float lineHeight = LineSpacing * Scale;
    Color outline = (OutlineColor == Color(0, 71, 255)) ? currentOutlineColor : OutlineColor;
    Color text = (TextColor == Color::White) ? currentTextColor : TextColor;

    for (int i = 0; i < Text.size(); ++i) {
        char c = Text[i];
        
        if (c == '\n') {
            y += lineHeight;
            x = originalX;
            continue;
        }

        if (c >= 'a' && c <= 'z') c -= 32;

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
                outlineSprite.setColor(outline);
                window->draw(outlineSprite);
            }

            Sprite sprite;
            sprite.setTexture(tex);
            sprite.setScale(Scale, Scale);
            sprite.setPosition(x, y);
            sprite.setColor(text);
            window->draw(sprite);

            x += tex.getSize().x * Scale + LetterSpacing;
        }
    }
}

void CustomFont::setOutlineColor(Color color) {
    currentOutlineColor = color;
}

void CustomFont::setTextColor(Color color) {
    currentTextColor = color;
}