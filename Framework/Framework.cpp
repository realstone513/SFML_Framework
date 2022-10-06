#include "Framework.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "../3rd/SingleTon.h"
#include "../Scenes/SceneMgr.h"
#include "../DataTable/DataTableMGR.h"

Framework::Framework(int width, int height)
    :windowSize(width, height), timeScale(1.f)
{
    window.create(VideoMode(windowSize.x, windowSize.y), "Game");
}

Framework::~Framework()
{
}

float Framework::GetDT() const
{
    return deltaTime.asSeconds() * timeScale;
}

float Framework::GetRealDT() const
{
    return deltaTime.asSeconds();
}

bool Framework::Init()
{
    InputManager::Init();
  
    RESOURCES_MGR->LoadAll();
    SCENE_MGR->Init();
    DATATABLE_MGR->Init();
    
    return true;
}

bool Framework::Do()
{
    while (window.isOpen())
    {
        deltaTime = clock.restart();
        float dt = GetDT();
        InputManager::ClearInput();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            InputManager::UpdateInput(event);
        }

        window.clear();
        SCENE_MGR->Update(dt);
        SCENE_MGR->Draw(window);
        window.display();
    }

    return true;
}

#define DATATABLE_MGR (DataTableMgr::GetInstance())