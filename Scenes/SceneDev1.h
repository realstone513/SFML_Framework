#pragma once
#include "Scene.h"
#include "../GameObject/Player.h"

class SceneDev1 : public Scene
{
protected:
	Player* player;

public:
	SceneDev1();
	~SceneDev1();

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};