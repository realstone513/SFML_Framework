#include "SceneMgr.h"
#include "../../Scenes/TitleScene.h"
#include "../../Scenes/EquipmentScene.h"
#include "../../Scenes/BattleScene.h"
//#include "SceneDev1.h"
//#include "SceneDev2.h"

Scenes SceneMgr::GetCurrScene() const
{
	return currScene;
}

Scene* SceneMgr::GetScene(Scenes scene)
{
	return sceneMap[scene];
}

bool SceneMgr::Init()
{
	/*sceneMap[Scenes::Dev1] = new SceneDev1();
	sceneMap[Scenes::Dev2] = new SceneDev2();*/
	sceneMap[Scenes::Title] = new TitleScene();
	sceneMap[Scenes::Equipment] = new EquipmentScene();
	sceneMap[Scenes::Battle] = new BattleScene();

	for (auto i : sceneMap)
		i.second->Init();

	currScene = Scenes::Title;
	sceneMap[currScene]->Enter();
	return false;
}

void SceneMgr::ChangeScene(Scenes scene)
{
	sceneMap[currScene]->Exit();
	currScene = scene;
	sceneMap[currScene]->Enter();
}

void SceneMgr::Update(float dt)
{
	sceneMap[currScene]->Update(dt);
}

void SceneMgr::Draw(RenderWindow& window)
{
	sceneMap[currScene]->Draw(window);
}