//
// Tri_Orange.cpp
//

#include "Tri_Orange.h"
#include<random>

using namespace SimpleMath;

void Tri_Orange::Initialize()
{
	m_hp = 100;
	
	m_initPos = Vector2(rand() % 400, rand() % 400);
	m_position = m_initPos;
	m_velocity = 200;
	m_spriteOffset_x = -64;
	m_spriteOffset_y = -64;
	m_rotate = 1;
	m_moveTimer_Right.Set(m_toLeftTime);

}

void Tri_Orange::Update()
{
	HandleTri_OrangeState(m_state);
	UpdateCollider();
}


void Tri_Orange::AffectDamage(int offence)
{
	m_hp -= offence;
	if (m_hp < 0)
	{
		m_hp = 0;
	}
}


void Tri_Orange::HandleTri_OrangeState(Tri_OrangeState State)
{
	switch (State) {
	case Tri_OrangeState::Move:
		Move();

		if ( m_isright == true)
		{
			if (m_moveTimer_Right.TimeUp())
			{
				m_isleft = true;
				m_isright = false;
				m_state = Tri_OrangeState::Stay_Left;
			}
			break;
		}
		if(m_isleft == true)
		{
			if (m_moveTimer_Right.TimeUp())
			{
				m_isleft = false,
					m_isright = true;
				m_state = Tri_OrangeState::Stay_Right;
			}
		}

		break;

	case Tri_OrangeState::Stay_Right:

		UpdateMoveDirection();
		m_moveTimer_Right.Set(m_toRightTime);
		m_state = Tri_OrangeState::Move;
		break;

	case Tri_OrangeState::Stay_Left:
		UpdateMoveDirection();
		m_moveTimer_Right.Set(m_toLeftTime);
		m_state = Tri_OrangeState::Move;
		break;

	default:
		break;
	}
	
}

void Tri_Orange::Move()
{
	//主人公にまっすぐ突進
	m_position += m_moveDirection * m_velocity * DXTK->Time.deltaTime;
	m_position += m_shakeDirection * m_shakeVelocity * DXTK->Time.deltaTime;
}

void Tri_Orange::UpdateMoveDirection()
{
	SimpleMath::Vector2 playerPos = PlayerParameter::GetInstance().GetParams().position - Camera::GetInstance().GetOffset();
	m_moveDirection = playerPos - m_position;
	m_moveDirection.Normalize();

	if (m_isleft)
	{
		m_shakeDirection = SimpleMath::Vector2(-m_moveDirection.x, m_moveDirection.y);
	}
	if (m_isright)
	{
		m_shakeDirection = SimpleMath::Vector2(m_moveDirection.x, -m_moveDirection.y);
	}
}

void Tri_Orange::Attack() 
{

}

void Tri_Orange::Render()
{
	DirectX::SpriteBatch* sp = SpriteManager::GetInstance().GetSpriteBatch();
	
	float ragian = m_rotate;
	SpriteData sprite = SpriteManager::GetInstance().GetSprite(SpriteName::TriOrange);
	RECT spriteRect = { 0,0,128,128 };
	sp->Draw(sprite.m_sprite.handle,
		sprite.m_sprite.size,
		m_position + Camera::GetInstance().GetOffset(),	//pos
		nullptr,
		DirectX::Colors::White,			//色
		DirectX::XMConvertToRadians(ragian),						//回転
		SimpleMath::Vector2(64, 64),		
		1.0,							//Scale
		DirectX::SpriteEffects_None,	//エフェクト
		1.0f);							//レイヤー


	m_rotate += 1;

}

Collider::ColliderRect Tri_Orange::GetCollider() const
{

	return m_collider;
}

void Tri_Orange::UpdateCollider()
{
	SimpleMath::Vector2 offset = Camera::GetInstance().GetOffset();
	m_collider.x = m_position.x + offset.x + m_spriteOffset_x;
	m_collider.y = m_position.y + offset.y + m_spriteOffset_y;
	m_collider.width = m_collider.x + 128;
	m_collider.height = m_collider.y + 128;
	m_collider.type = "Tri_Orange";

}