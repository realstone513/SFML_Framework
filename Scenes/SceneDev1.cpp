#include "SceneDev1.h"
#include "SceneMgr.h"
#include "../Framework/InputManager.h"
#include "../Framework/ResourceManager.h"
#include "../Framework/SoundManager.h"
#include "../Framework/Framework.h"
#include "../GameObject/TextObject.h"

SceneDev1::SceneDev1()
	:Scene(Scenes::Dev1)
{
    TextObject* ui = new TextObject(
        *RESOURCES_MGR->GetFont("fonts/zombiecontrol.ttf"),
        "Scene1", 800, 0, Color::Blue, 100);
    uiObjList.push_back(ui);
    player = new Player();
    objList.push_back(player);
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Enter()
{
}

void SceneDev1::Exit()
{
    SOUND_MGR->StopAll();
}

void SceneDev1::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Key::Space))
		SCENE_MGR->ChangeScene(Scenes::Dev2);

    //cout << InputManager::GetAxis(Axis::Horizontal).value << endl;
    Scene::Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
    Scene::Draw(window);
}