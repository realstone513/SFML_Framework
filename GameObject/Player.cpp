#include "Player.h"
#include "../Framework/InputManager.h"
#include "../Framework/ResourceManager.h"
#include "../Framework/Framework.h"

Player::Player()
	: velocity(0), accelation(0), deaccelation(0)
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
	velocity = 0;
}

void Player::Update(float dt)
{
	SpriteObject::Update(dt);
	/*
	direction.x = InputMgr::GetAxis(Axis::Horizontal);
	direction.y = InputMgr::GetAxis(Axis::Vertical);
	if (Utils::Magnitude(direction) > 1.f)
	{
		direction = Utils::Normalize(direction);
	}
	*/

	direction.x = InputManager::GetAxisRaw(Axis::Horizontal);
	direction.y = InputManager::GetAxisRaw(Axis::Vertical);

	// 가속
	velocity += direction * accelation * dt;
	if (Utils::Magnitude(velocity) > velocity)
	{
		velocity = Utils::Normalize(velocity) * velocity;
	}

	// 감속
	//if (Utils::Magnitude(direction) == 0.f)
	//{
	//	velocity = { 0.f, 0.f };
	//}


	if (direction.x == 0.f)
	{
		if (velocity.x > 0.f)
		{
			velocity.x -= deaccelation * dt;
			if (velocity.x < 0.f)
				velocity.x = 0.f;
		}
		if (velocity.x < 0.f)
		{
			velocity.x += deaccelation * dt;
			if (velocity.x > 0.f)
				velocity.x = 0.f;
		}
	}

	if (direction.y == 0.f)
	{
		if (velocity.y > 0.f)
		{
			velocity.y -= deaccelation * dt;
			if (velocity.y < 0.f)
				velocity.y = 0.f;
		}
		if (velocity.y < 0.f)
		{
			velocity.y += deaccelation * dt;
			if (velocity.y > 0.f)
				velocity.y = 0.f;
		}
	}

	Translate(velocity * dt);

}

//void Player::Update(float dt)
//{
//	SpriteObject::Update(dt);
//
//	direction.x = InputManager::GetAxisRaw(Axis::Horizontal);
//	direction.y = InputManager::GetAxisRaw(Axis::Vertical);
//
//	direction = Utils::Normalize(direction);
//	
//	if (Utils::Magnitude(direction))
//	{
//		direction2 = direction;
//		speed += dt * 500;
//		if (speed >= 1000.f)
//			speed = 1000.f;
//	}
//	else
//	{
//		//direction2 = Utils::Lerp(direction2, direction, 0.05f);
//		speed -= dt * 1500;
//		if (speed <= 0.f)
//			speed = 0.f;
//
//		/*velo = Utils::Lerp(velo, velo * 0.8f, 0.5f);
//		if (velo < 0.01f)
//			velo = 0;*/
//	}
//	
//	cout << speed << endl;
//
//	Translate(direction * speed * dt);
//}

void Player::Draw(RenderWindow& window)
{
	SpriteObject::Draw(window);
}