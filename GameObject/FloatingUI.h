#pragma once
#include "TextObj.h"

class FloatingUI : public TextObj
{
protected:
	Vector2f dir;
	float speed;
	float range;

public:
	FloatingUI();
	virtual ~FloatingUI();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	void Fire(const Vector2f pos, const Vector2f dir, float speed, float range);
};