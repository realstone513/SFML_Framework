#include "SceneDev1.h"
#include "../Frameworks.h"

SceneDev1::SceneDev1()
	: Scene(Scenes::Dev1)
{
	LOG::Print3String("scene1 create");
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Init()
{
	LOG::Print3String("scene1 init");

	for (auto obj : objList)
	{
		obj->Init();
	}
}

void SceneDev1::Release()
{
}

void SceneDev1::Enter()
{
	LOG::Print3String("scene1 enter");
}

void SceneDev1::Exit()
{
	LOG::Print3String("scene1 exit");
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Key::Space))
	{
		SCENE_MGR->ChangeScene(Scenes::Dev2);
		return;
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::F1))
	{
		LOG::Print3String("scene1");
		return;
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Escape))
		exit(0);

	Scene::Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
	Scene::Draw(window);	
}