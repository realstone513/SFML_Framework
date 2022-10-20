#include "SceneDev2.h"
#include "../Frameworks.h"

SceneDev2::SceneDev2()
	: Scene(Scenes::Dev2)
{
	LOG::Print3String("scene2 create");
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Init()
{
	LOG::Print3String("scene2 init");

	for ( auto obj : objList )
	{
		obj->Init();
	}
}

void SceneDev2::Release()
{
}

void SceneDev2::Enter()
{
	LOG::Print3String("scene2 enter");
}

void SceneDev2::Exit()
{
	LOG::Print3String("scene2 exit");
}

void SceneDev2::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Key::Space))
	{
		SCENE_MGR->ChangeScene(Scenes::Dev1);
		return;
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::F1))
	{
		LOG::Print3String("scene2");
		return;
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Escape))
		exit(0);

	Scene::Update(dt);
}

void SceneDev2::Draw(RenderWindow& window)
{
	Scene::Draw(window);
}