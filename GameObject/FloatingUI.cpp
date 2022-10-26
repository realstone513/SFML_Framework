#include "FloatingUI.h"

FloatingUI::FloatingUI()
	: dir(0, -1), speed(20.f), range(50.f)
{
}

void FloatingUI::Release()
{
	TextObj::Release();
}

void FloatingUI::Reset()
{
	this->dir = { 0, -1 };
	this->speed = 20.f;
	this->range = 50.f;
	SetPos({ 0.f, 0.f });

	TextObj::Reset();
}

void FloatingUI::Update(float dt)
{
	Translate(dir * this->speed * dt);
	range -= Utils::Magnitude(dir * this->speed * dt);

	TextObj::Update(dt);
}

void FloatingUI::Draw(RenderWindow& window)
{
	TextObj::Draw(window);
}

void FloatingUI::Fire(const Vector2f pos, const Vector2f dir, float speed, float range)
{
	SetPos(pos);

	this->dir = dir;
	this->speed = speed;
	this->range = range;
}