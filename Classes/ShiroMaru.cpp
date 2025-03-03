//
// ShiroMaru.cpp
//

#include "ShiroMaru.h"
#include<random>

using namespace SimpleMath;

void ShiroMaru::Initialize()
{
	m_hp = 100;
	
	m_initPos = Vector2(rand() % 1000, rand() % 1000);
	m_position = m_initPos;
	m_velocity = 100;
	m_spriteOffset_x = -50;
	m_spriteOffset_y = 0;
}

void ShiroMaru::Update()
{
	HandleShiroMaruState(m_state);
}


void ShiroMaru::AffectDamage(int offence)
{
	m_hp -= offence;

	if (m_hp < 0)
	{
		m_hp = 0;
	}
}


void ShiroMaru::HandleShiroMaruState(ShiroMaruState State)
{
	switch (State) {
	case ShiroMaruState::Move:

		Move();
		UpdateCollider();
		break;

	default:
		break;
	}
}

void ShiroMaru::Move()
{

	//ŽålŒö‚É‚Ü‚Á‚·‚®‚Â‚¢‚Ä‚­‚é
	SimpleMath::Vector2 playerPos = PlayerParameter::GetInstance().GetParams().position - Camera::GetInstance().GetOffset();
	SimpleMath::Vector2 direction = playerPos - m_position;
	direction.Normalize();
	m_position += direction * m_velocity * DXTK->Time.deltaTime;
}


void ShiroMaru::Attack() 
{

}

void ShiroMaru::Render()
{

	SpriteManager::GetInstance().Render(SpriteName::Shiromaru, m_position + Camera::GetInstance().GetOffset());
	int i = 1;
	
}

Collider::ColliderRect ShiroMaru::GetCollider() const
{

	return m_collider;
}

void ShiroMaru::UpdateCollider()
{
	SimpleMath::Vector2 offset = Camera::GetInstance().GetOffset();
	m_collider.x = m_position.x + offset.x + m_spriteOffset_x;
	m_collider.y = m_position.y + offset.y + m_spriteOffset_y;
	m_collider.width = m_collider.x + 100;
	m_collider.height = m_collider.y + 50;
	m_collider.type = "ShiroMaru";

}