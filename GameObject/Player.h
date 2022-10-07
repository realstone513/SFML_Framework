#pragma once
#include "SpriteObject.h"

class Player : public SpriteObject
{
protected:
	Vector2f direction;
	float speed;

public:
	Player();
	virtual ~Player();

	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};