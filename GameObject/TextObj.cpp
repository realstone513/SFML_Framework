#include "TextObj.h"

TextObj::TextObj(Font& font, string textString,
    float sizeX, float sizeY, Color textColor, int textSize)
{
    text.setFont(font);
    text.setString(textString);
    text.setPosition(sizeX, sizeY);
    position = { sizeX, sizeY };
    text.setFillColor(textColor);
    text.setCharacterSize(textSize);
}

TextObj::~TextObj()
{
}

void TextObj::Draw(RenderWindow& window)
{
    window.draw(text);
}

void TextObj::Translate(Vector2f delta)
{
    position.x += delta.x;
    position.y += delta.y;
}

void TextObj::SetOrigin(Origins origin)
{
    Utils::SetOrigin(text, origin);
}

void TextObj::SetString(string string)
{
    text.setString(string);
}

const string& TextObj::GetString() const
{
    return text.getString();
}

FloatRect TextObj::GetGlobalBounds()
{
    return text.getGlobalBounds();
}

void TextObj::SetColor(Color color)
{
    text.setFillColor(color);
}

void TextObj::SetPos(const Vector2f& pos)
{
    text.setPosition(pos);
}