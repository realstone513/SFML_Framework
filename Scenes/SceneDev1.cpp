#include "SceneDev1.h"
#include "SceneMgr.h"
#include "../Framework/InputManager.h"
#include "../Framework/ResourceManager.h"
#include "../Framework/SoundManager.h"
#include "../GameObject/SpriteObject.h"
#include "../GameObject/TextObject.h"

SceneDev1::SceneDev1()
	:Scene(Scenes::Dev1)
{
    SpriteObject* obj = new SpriteObject();
    obj->SetTexture(*RESOURCES_MGR->GetTexture("graphics/player3.png"));
    objList.push_back(obj);

    TextObject* ui = new TextObject(
        *RESOURCES_MGR->GetFont("fonts/KOMIKAP_.ttf"),
        "Scene1", 800, 0, Color::Blue, 100);
    uiObjList.push_back(ui);
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Enter()
{
    SOUND_MGR->Play("sounds/Hennesis.ogg");
}

void SceneDev1::Exit()
{
    SOUND_MGR->StopAll();
}

void SceneDev1::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Key::Space))
		SCENE_MGR->ChangeScene(Scenes::Dev2);

    Scene::Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
    Scene::Draw(window);
}