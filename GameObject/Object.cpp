#include "Object.h"

Object::Object()
{
    Init();
}

Object::~Object()
{
    Release();
}

void Object::SetActive(bool active)
{
    enabled = active;
}

bool Object::GetActive() const
{
    return enabled;
}

void Object::SetPosition(Vector2f pos)
{
    position = pos;
}

Vector2f Object::GetPosition() const
{
    return position;
}

void Object::Init()
{
}

void Object::Release()
{
}

void Object::Update()
{
}

void Object::Draw(RenderWindow& window)
{
}