#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Object
{
protected:
    int id;
    string name;
    bool enabled;

    Vector2f position;
    float rotation;
    Vector2f scale;

public:
    Object();
    virtual ~Object();

    virtual void SetActive(bool active);
    virtual bool GetActive() const;

    virtual void SetPosition(Vector2f pos);
    virtual Vector2f GetPosition() const;

    virtual void Init();
    virtual void Release();
    virtual void Update();
    virtual void Draw(RenderWindow& window);
};