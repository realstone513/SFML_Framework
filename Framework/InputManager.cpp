#include "InputManager.h"
#include <iostream>
#include <algorithm>

vector<bool> InputManager::downList(Keyboard::KeyCount, false);
vector<bool> InputManager::ingList(Keyboard::KeyCount, false);
vector<bool> InputManager::upList(Keyboard::KeyCount, false);
vector<int> InputManager::ingIdx;
map<Axis, AxisInfo> InputManager::axisInfoMap;

void InputManager::Init()
{ 
    //Horizontal
  
    axisInfoMap.insert({ Axis::Horizontal, AxisInfo()});

    axisInfoMap[Axis::Horizontal].axis = Axis::Horizontal;
    axisInfoMap[Axis::Horizontal].positives.push_back(Keyboard::Key::D);
    axisInfoMap[Axis::Horizontal].positives.push_back(Keyboard::Key::Right);
    axisInfoMap[Axis::Horizontal].negatives.push_back(Keyboard::Key::A);
    axisInfoMap[Axis::Horizontal].negatives.push_back(Keyboard::Key::Left);
    //Vertical
    AxisInfo info2;
    info2.axis = Axis::Vertical;
    info2.positives.push_back(Keyboard::Key::S);
    info2.positives.push_back(Keyboard::Key::Down);
    info2.negatives.push_back(Keyboard::Key::W);
    info2.negatives.push_back(Keyboard::Key::Up);
    axisInfoMap.insert({ info2.axis, info2 });

}

void InputManager::ClearInput()
{
    //fill(downList.begin(), downList.end(), false);
    //fill(upList.begin(), upList.end(), false);
    for (auto idx : ingIdx)
    {
        downList[idx] = false;
        upList[idx] = false;
    }
    ingIdx.clear();

}

void InputManager::UpdateInput(Event& ev)
{
    switch (ev.type)
    {
    case Event::EventType::KeyPressed:
        if (ev.key.code != Keyboard::Unknown && !ingList[ev.key.code]) //ó���� ��������
        {
            downList[ev.key.code] = true;  //�ٿ� true    ->  ����������(while�ٽý���) ���� clear�� false�� ����
            ingList[ev.key.code] = true;   //ing true
            ingIdx.push_back(ev.key.code);
        }
        break;
    case Event::EventType::KeyReleased:
        if (ev.key.code != Keyboard::Unknown)
        {
            ingList[ev.key.code] = false;
            upList[ev.key.code] = true;
            ingIdx.push_back(ev.key.code);
        }
        break;
    }
}

bool InputManager::GetKeyDown(Keyboard::Key key)
{
    return downList[key];
}

bool InputManager::GetKey(Keyboard::Key key)
{
    return ingList[key];
}

bool InputManager::GetKeyUp(Keyboard::Key key)
{
    return upList[key];
}

float InputManager::GetAxisRaw(Axis axis)
{
    //A , <- �� Ű�� �װ�Ƽ�� �Է�, D, -> ����Ƽ�� �Է�.

    const AxisInfo& info = axisInfoMap[axis];

    for (auto key : info.negatives)
    {
        if (GetKey(key))
            return -1.f;
    }
    for (auto key : info.positives)
    {
        if (GetKey(key))
            return 1.f;
    }

    return 0;
}


/*
Ű A�� ������ ó�� ������ case Event::EventType::KeyPressed: �� �ɷ���
downList �� ingList�� ����,
main ���� GetKeyDown �� ȣ���ϸ� downList�� ��������� TRUE�� ��ȯ�ȴ�.
main �� while�� �� �����Ӹ��� down�� ing�� �ʱ�ȭ ���ִϱ�.
A�� ������ �ִ� ���� ���� �����ӿ����� downList�� A�� ������� ������
GetKeyDown�� ȣ���ص� false�� ������, GetKey�� ȣ���ϸ� ingList�� ��������ϱ� True�� ��ȯ.

AŰ�� ������ �����ÿ��� case Event::EventType::KeyReleased:�� �ɷ���
upList�� A�� �־��ְ�, ingList�� A�� remove���ش�.
�� ���Ŀ� GetKey�� ȣ���ϸ� A�� �����ϱ� False�� ��ȯ�Ǹ�,
GetKeyUp �� ȣ���ϸ� ��������ϱ� True�� ��ȯ�ȴ�.
���Ŀ� main���� clear���ִϱ� Ű�� �� ���Ŀ�
GetKey�� GetKeyUp�� ȣ���ص� �ƹ��͵� ������� �ʾƼ� false�� ��ȯ�ȴ�.

main�� while�帧��
Ű �Է� -> down,ing�� ���� -> GetKeyDwon, GetKey �� true , GetKeyUp�� false -> ����������
-> down, up Ŭ���� -> dwon, up �� false , GetKey�� true -> ����������
... Ű�� ���� -> up����, ing���� ���� -> GetKeyUp�� true, GetKeyDown GetKey�� false -> ���������� -> down, up Ŭ����
-> GetkeyDown, GetKey, GeyKeyUp �� false
*/
