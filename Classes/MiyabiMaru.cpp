//
// MiyabiMaru.cpp
//

#include "MiyabiMaru.h"
#include<random>

using namespace SimpleMath;

void MiyabiMaru::Initialize()
{
	m_hp = 100;
	
	m_initPos = Vector2(rand() % 400, rand() % 400);
	m_position = m_initPos;
	m_velocity = 1000;
	m_spriteOffset_x = -50;
	m_spriteOffset_y = 0;
	m_moveTime = 1;
	m_stayTime = 2;
}

void MiyabiMaru::Update()
{
	HandleMiyabiMaruState(m_state);
	UpdateCollider();
}


void MiyabiMaru::AffectDamage(int offence)
{
	m_hp -= offence;
	if (m_hp < 0)
	{
		m_hp = 0;
	}
}


void MiyabiMaru::HandleMiyabiMaruState(MiyabiMaruState State)
{
	switch (State) {
	case MiyabiMaruState::Move:

		Move();

		if (m_moveTimer.TimeUp())
		{
			m_state = MiyabiMaruState::Stay;
			m_stayTimer.Set(m_stayTime);
		}

		break;

	case MiyabiMaruState::Stay:
		
		if (m_stayTimer.TimeUp())
		{
			UpdateMoveDirection();
			m_state = MiyabiMaruState::Move;
			m_moveTimer.Set(m_moveTime);
		}

		break;

	default:
		break;
	}
	
}

void MiyabiMaru::Move()
{
	//ŽålŒö‚É‚Ü‚Á‚·‚®“Ëi
	m_position += m_moveDirection * m_velocity * DXTK->Time.deltaTime;
}

void MiyabiMaru::UpdateMoveDirection()
{
	SimpleMath::Vector2 playerPos = PlayerParameter::GetInstance().GetParams().position - Camera::GetInstance().GetOffset();
	m_moveDirection = playerPos - m_position;
	m_moveDirection.Normalize();
}

void MiyabiMaru::Attack() 
{

}

void MiyabiMaru::Render()
{

	SpriteManager::GetInstance().Render(SpriteName::miyabimaru, m_position + Camera::GetInstance().GetOffset());

}

Collider::ColliderRect MiyabiMaru::GetCollider() const
{

	return m_collider;
}

void MiyabiMaru::UpdateCollider()
{
	SimpleMath::Vector2 offset = Camera::GetInstance().GetOffset();
	m_collider.x = m_position.x + offset.x + m_spriteOffset_x;
	m_collider.y = m_position.y + offset.y + m_spriteOffset_y;
	m_collider.width = m_collider.x + 100;
	m_collider.height = m_collider.y + 50;
	m_collider.type = "MiyabiMaru";

}