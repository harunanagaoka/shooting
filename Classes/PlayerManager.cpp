//
// PlayerManager.cpp
//

#include "PlayerManager.h"


using namespace SimpleMath;

void PlayerManager::Update()//std::vector<EnemyBase*>& enemies
{
	UpdateParams();

	m_playerCollider.x = m_currentParams.position.x - 40;
	m_playerCollider.y = m_currentParams.position.y - 40;
	m_playerCollider.width = m_playerCollider.x + m_colliderx;
	m_playerCollider.height = m_playerCollider.y + m_collidery;
	m_playerCollider.type = "Player";
}


void PlayerManager::UpdateParams()
{
	m_currentParams = PlayerParameter::GetInstance().GetParams();
}

void PlayerManager::move()
{
	SimpleMath::Vector2 movePos = m_currentParams.position;

	if (InputSystem.Keyboard.isPressed.D)
	{
		movePos.x += m_velocity;
		PlayerParameter::GetInstance().SetPosition(movePos);
	}
	if (InputSystem.Keyboard.isPressed.A)
	{
		movePos.x -= m_velocity;
		PlayerParameter::GetInstance().SetPosition(movePos);
	}
	if (InputSystem.Keyboard.isPressed.W)
	{
		movePos.y -= m_velocity;
		PlayerParameter::GetInstance().SetPosition(movePos);
	}
	if (InputSystem.Keyboard.isPressed.S)
	{
		movePos.y += m_velocity;
		PlayerParameter::GetInstance().SetPosition(movePos);
	}
}

void PlayerManager::Render(DirectX::SpriteBatch* sprite_batch)
{
	///デバッグ用
	/*RECT destRect = { m_renderPos.x, m_renderPos.y, m_renderPos.x + m_colliderx, m_renderPos.y + m_collidery };
	SpriteData sprite = sm.GetSprite(SpriteName::DebugTexture);
	sprite_batch->Draw(sprite.m_sprite.handle, sprite.m_sprite.size, destRect, DirectX::Colors::Aqua);*/

	//RECT destRect = { m_playerCollider.x, m_playerCollider.y, m_playerCollider.width , m_playerCollider.height };
	//SpriteData sprite = SpriteManager::GetInstance().GetSprite(SpriteName::DebugTexture);
	//sprite_batch->Draw(sprite.m_sprite.handle, sprite.m_sprite.size, destRect, DirectX::Colors::Red);

	DirectX::SpriteBatch* sp = SpriteManager::GetInstance().GetSpriteBatch();
	SpriteManager::GetInstance().Render(SpriteName::PlayerFront, m_currentParams.position);
}

SimpleMath::Vector2 PlayerManager::Position()
{
	return position_;
}