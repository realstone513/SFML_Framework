#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "../GameObject/Object.h"

using namespace sf;
using namespace std;

enum class Scenes
{
	Dev1,
    Dev2
};
class Scene
{
protected:
	Scenes type;
    list<Object*> objList;
    list<Object*> uiObjList;

public:
	Scene(Scenes type);
	virtual ~Scene();

	virtual void Enter() = 0;
	virtual void Exit() = 0;

    virtual void Update(float dt);
    virtual void Draw(RenderWindow& window);
};