#include "Player.h"
#include "../Framework/InputManager.h"
#include "../Framework/ResourceManager.h"
#include "../Framework/Framework.h"

Player::Player()
	: speed(750)
{
	SetTexture(*RESOURCES_MGR->GetTexture("graphics/player.png"));
	Init();
}

Player::~Player()
{
}

void Player::Init()
{
	SetOrigin(Origins::MC);
	Vector2i windowSize = FRAMEWORK->GetWindowSize();
	SetPosition({ windowSize.x * 0.5f, windowSize.y * 0.5f });

}

void Player::Update(float dt)
{
	SpriteObject::Update(dt);

	direction.x = InputManager::GetAxis(Axis::Horizontal);
	direction.y = InputManager::GetAxis(Axis::Vertical);
	direction = Utils::Normalize(direction);

	Translate(direction * speed * dt);
}

void Player::Draw(RenderWindow& window)
{
	SpriteObject::Draw(window);
}