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
    SpriteObject* obj = new SpriteObject();
    obj->SetTexture(*RESOURCES_MGR->GetTexture("graphics/player5.png"));
    objList.push_back(obj);

    TextObject* ui = new TextObject(
        *RESOURCES_MGR->GetFont("fonts/DS-DIGI.ttf"), "Scene2",
        800, 0);
    uiObjList.push_back(ui);
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Enter()
{
    SOUND_MGR->Play("sounds/Cunningcity.ogg");
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