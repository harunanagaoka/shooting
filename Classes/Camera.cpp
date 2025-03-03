//
// Camera.cpp
//

#include "Camera.h"


using namespace SimpleMath;

void Camera::Update()
{
	Move();
}

void Camera::Render(DirectX::SpriteBatch* sprite_batch)
{
	DirectX::SpriteBatch* sp = SpriteManager::GetInstance().GetSpriteBatch();
	SpriteManager::GetInstance().Render(SpriteName::Stage_Pentagon, GetOffset());
}


void Camera::Move()
{
	SimpleMath::Vector2 movePos = m_playerParams.position;

	if (InputSystem.Keyboard.isPressed.D)
	{
		m_position.x += m_velocity;
		if (m_position.x >= m_stageLimit_Right)
		{
			m_position.x = m_stageLimit_Right;
		}
	}
	if (InputSystem.Keyboard.isPressed.A)
	{
		m_position.x -= m_velocity;
		if (m_position.x <= m_stageLimit_Left)
		{
			m_position.x = m_stageLimit_Left;
		}
	}
	if (InputSystem.Keyboard.isPressed.W)
	{
		m_position.y -= m_velocity;
		if (m_position.y <= m_stageLimit_Up)
		{
			m_position.y = m_stageLimit_Up;
		}
	}
	if (InputSystem.Keyboard.isPressed.S)
	{
		m_position.y += m_velocity;
		if (m_position.y >= m_stageLimit_Down)
		{
			m_position.y = m_stageLimit_Down;
		}
	}
}