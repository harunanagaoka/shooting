//
// Slime.cpp
//

#include "Slime.h"
#include<random>

using namespace SimpleMath;

void Slime::Initialize()
{
	m_hp = 100;
	
	m_initPos = Vector2(rand() % 400, rand() % 400);
	m_position = m_initPos;
	m_idleAreaLeft_x = m_initPos.x - m_idleArea;
	m_idleArearight_x = m_initPos.x + m_idleArea;
}

void Slime::Update()
{
	HandleSlimeState(m_state);
}


void Slime::AffectDamage(int offence)
{
	m_hp -= offence;
	if (m_hp < 0)
	{
		m_hp = 0;
	}
}


SimpleMath::Vector2 Slime::Position()
{
	return m_position;
}

void Slime::HandleSlimeState(SlimeState State)
{
	switch (State) {
	case SlimeState::Idle:

		if (!m_isIdleTimerSet)
		{
			m_idleTimer.Set(m_idleTime);
			m_isIdleTimerSet = true;
		}
		
		if (!m_idleTimer.TimeUp())
		{
			Move();
		}
		else
		{
			State = SlimeState::LockOn;
		}
		break;

	case SlimeState::LockOn:
		if (!m_isLockOnTimeSet)
		{
			m_LockOnTimer.Set(m_lockOnTime);
			m_isLockOnTimeSet = true;
		}
		if (!m_LockOnTimer.TimeUp())
		{
			Move();
		}
		else
		{
			State = SlimeState::Attack;
		}

		break;

	case SlimeState::Attack:

		break;

	default:
		break;
	}
}

void Slime::Move()
{

	if (m_isGoRight && m_position.x < m_idleArearight_x)
	{
		m_position.x += m_idleVelosity * DXTK->Time.deltaTime;

		if (m_isGoRight && m_position.x >= m_idleArearight_x)
		{
			m_isGoRight = false;
			m_isGoLeft = true;
		}
	}
	if(m_isGoLeft && m_position.x >= m_idleAreaLeft_x)
	{
		m_position.x -= m_idleVelosity * DXTK->Time.deltaTime;

		if (m_isGoLeft && m_position.x < m_idleAreaLeft_x)
		{
			m_isGoRight = true;
			m_isGoLeft = false;
		}
	}

}

void Slime::LockOn()
{
	
}

void Slime::Attack() 
{

}

void Slime::Render()
{
	//SimpleMath::Vector2 offset = Camera::GetInstance().GetOffset();
	//RECT destRect = { m_position.x + offset.x, m_position.y + offset.y, m_position.x + 128 + offset.x, m_position.y + 128 + offset.y};
	//SpriteData sprite = SpriteManager::GetInstance().GetSprite(SpriteName::DebugTexture);
	//sprite_batch->Draw(sprite.m_sprite.handle, sprite.m_sprite.size, destRect, DirectX::Colors::Aqua);

	SpriteManager::GetInstance().Render(SpriteName::slime, m_position + Camera::GetInstance().GetOffset());
	
	//if (a % 3 == 2)
	//{
	//	spriteManager.Render(spriteManager.GetSprite(Descriptors::Player2), m_position, sprite_batch);
	//}
	//if (a % 3 == 0)
	//{
	//	spriteManager.Render(spriteManager.GetSprite(Descriptors::sword), m_position, sprite_batch);
	//}
}

Collider::ColliderRect Slime::GetCollider() const
{

	SimpleMath::Vector2 offset = Camera::GetInstance().GetOffset();
	Collider::ColliderRect collider;
	collider.x = m_position.x + offset.x;
	collider.y = m_position.y + offset.y;
	collider.width = collider.x + 128 ;
	collider.height = collider.y + 128;
	collider.type = "Slime";
	return collider;
}
