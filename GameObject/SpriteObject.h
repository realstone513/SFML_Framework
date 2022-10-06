#pragma once
#include "Object.h"

class SpriteObject : public Object
{
protected:
    Sprite sprite;

public:
    SpriteObject();
    virtual ~SpriteObject();

    virtual void Init();
    virtual void Update();
    virtual void Draw(RenderWindow& window);

    void SetTexture(Texture& tex);
};