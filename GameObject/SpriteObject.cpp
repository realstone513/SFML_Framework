#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
}

SpriteObject::~SpriteObject()
{
}

void SpriteObject::Init()
{
}

void SpriteObject::Update()
{

}

void SpriteObject::Draw(RenderWindow& window)
{
    window.draw(sprite);
}

void SpriteObject::SetTexture(Texture& tex)
{
    sprite.setTexture(tex);
}