#include "SceneDev2.h"
#include "SceneMgr.h"
#include "../Framework/InputManager.h"
#include "../Framework/ResourceManager.h"
#include "../Framework/SoundManager.h"
#include "../GameObject/SpriteObject.h"
#include "../GameObject/TextObject.h"

SceneDev2::SceneDev2()
	:Scene(Scenes::Dev2)
{
    TextObject* ui = new TextObject(
        *RESOURCES_MGR->GetFont("fonts/zombiecontrol.ttf"), "Scene2",
        800, 0, Color::Red, 100);
    uiObjList.push_back(ui);
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Enter()
{
}

void SceneDev2::Exit()
{
    SOUND_MGR->StopAll();
}

void SceneDev2::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Key::Space))
		SCENE_MGR->ChangeScene(Scenes::Dev1);

    Scene::Update(dt);
}

void SceneDev2::Draw(RenderWindow& window)
{
    Scene::Draw(window);
}