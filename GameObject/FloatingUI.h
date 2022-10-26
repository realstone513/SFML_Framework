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
	virtual ~FloatingUI() {}

	virtual void Release() override;
	virtual void Reset() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	void Fire(const Vector2f pos,
		const Vector2f dir = { 0, -1 },
		float speed = 20.f,
		float range = 50.f);
};