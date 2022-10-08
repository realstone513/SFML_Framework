#pragma once
#include "SpriteObject.h"

class Player : public SpriteObject
{
protected:
	Vector2f direction;
	Vector2f direction2;
	float velocity;
	float accelation;
	float deaccelation;

public: 
	Player();
	virtual ~Player();

	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};