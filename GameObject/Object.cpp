#include "Object.h"

int Object::objCount = 0;

Object::Object()
	:isDevMod(false)
{
	id = ++objCount;
	Init();
}

Object::~Object()
{
	Release();
}

int Object::GetObjId() const
{
	return id;
}

void Object::SetActive(bool active)
{
	enabled = active;
}

bool Object::GetActive()
{
	return enabled;
}

void Object::Init()
{
	hitbox.setFillColor(Color::Red);
	hitbox.setOutlineColor(Color::Black);
	hitbox.setOutlineThickness(2.f);
	Reset();
}

void Object::Release()
{
}

void Object::Reset()
{
	enabled = true;
}

void Object::SetPos(const Vector2f& pos)
{
	position = pos;
	Vector2f hitboxPos = { hitBoxRect.left, hitBoxRect.top };
	hitbox.setPosition(hitboxPos + pos);
}

const Vector2f& Object::GetPos() const
{
	return position;
}

void Object::Translate(Vector2f delta)
{
	SetPos(position + delta);
}

void Object::Update(float dt)
{
}

void Object::Draw(RenderWindow& window)
{
	if ( isDevMod )
	{
		window.draw(hitbox);
	}
}

void Object::SetHitbox(const FloatRect rect)
{
	hitBoxRect = rect;
	hitbox.setSize({ rect.width, rect.height });
	Utils::SetOrigin(hitbox, Origins::MC);
}

RectangleShape Object::GetHitbox() const
{
	return hitbox;
}