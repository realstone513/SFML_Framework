#pragma once
#include "Object.h"

class RectangleObj : public Object
{
protected:
	RectangleShape shape;

public:
    RectangleObj();
    virtual ~RectangleObj() override;

	virtual void Draw(RenderWindow& window) override;

	void SetTexture(Texture* tex);
	void SetOrigin(Origins origin);
	void SetScale(float x, float y);
	void SetFillColor(Color color);

	void SetTextureRect(const IntRect& rect);
	const IntRect& GetTextureRect() const;

	Vector2f GetSize()const;
	FloatRect GetGlobalBounds() const;

	void SetPos(const Vector2f& pos) override;
};