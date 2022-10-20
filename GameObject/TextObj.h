#pragma once
#include "Object.h"

class TextObj : public Object
{
protected:
    Text text;

public:
    TextObj(Font& font,
        string textString,
        float sizeX = 0, float sizeY = 0,
        Color textColor = Color::White,
        int textSize = 75);
    virtual ~TextObj() override;

    virtual void Draw(RenderWindow& window) override;

    virtual void Translate(Vector2f delta) override;

    void SetOrigin(Origins origin);
    void SetString(string string);
    const string& GetString() const;

    FloatRect GetGlobalBounds();
    void SetColor(Color color);
    void SetPos(const Vector2f& pos);
};