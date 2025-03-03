//
// PlayerAttack.cpp
//

#include "PlayerAttack.h"


using namespace SimpleMath;

void PlayerAttack::Initialize()
{
	m_cameraPos = Camera::GetInstance().GetOffset();
	m_currentPos = m_playerPos - m_cameraPos;
	m_direction = m_atkDirection - m_currentPos;
	MakeCollider();
}

void PlayerAttack::Update()
{

	if (m_isAttack)
	{
		m_cameraPos = Camera::GetInstance().GetOffset();
		UpdatePos();
		MakeCollider();
		AttackDuration();
	}

	//敵のインスタンスを受け取り当たり判定

}

void PlayerAttack::Attack(SimpleMath::Vector2 direction)
{
	m_isAttack = true;
	//m_playerPos = playerPos;
	MakeCollider();

	m_currentAtkTime = m_attackDuration;
}

void PlayerAttack::MakeCollider()
{
	SimpleMath::Vector2 camerapos = Camera::GetInstance().GetOffset();
	m_collider.x = m_currentPos.x - m_colliderX / 2 + m_cameraPos.x; //いにっとポジション
	m_collider.y = m_currentPos.y - m_colliderY / 2 + m_cameraPos.y;
	m_collider.width = m_collider.x + m_colliderX;
	m_collider.height = m_collider.y + m_colliderY;
	m_collider.type = "Attack";
}

void PlayerAttack::UpdatePos()
{

	m_direction = m_atkDirection - m_playerPos;
	m_direction.Normalize();
	m_currentPos += m_velocity * m_direction;
}

void PlayerAttack::AttackDuration()
{
	if (m_currentAtkTime >= 0)
	{
		m_currentAtkTime -= DXTK->Time.deltaTime;
	}
	else
	{
		m_isAttack = false;
	}
}

void PlayerAttack::HitProcess(EnemyBase* enemy)
{
	if (m_hitEnemies.count(enemy))
	{
		return;
	}

	enemy->AffectDamage(m_offence_);
	m_hitEnemies.insert(enemy);
	UIFactory::GetInstance().MakeDamageUI(enemy->GetPosition(), m_offence_);
	m_isAttack = false;
}

void PlayerAttack::CheckHit(EnemyBase* enemies)
{
	if (enemies == nullptr)//enemies.empty()
	{
		return;
	}

	//for (int i = 0; i < enemies.size(); i++)
	//{
		if (m_collider.intersects(enemies->GetCollider()))
		{
			HitProcess(enemies);
		}
	//}
}

bool PlayerAttack::CheckHit(Collider::ColliderRect other)
{
	return m_collider.intersects(other);
}

void PlayerAttack::Render(DirectX::SpriteBatch* sprite_batch, SpriteManager& sm)
{
	if (!m_isAttack)
		return;

	//デバッグ用
	//RECT destRect = { m_collider.x, m_collider.y, m_collider.width , m_collider.height};
	//SpriteData sprite = SpriteManager::GetInstance().GetSprite(SpriteName::DebugTexture);
	//sprite_batch->Draw(sprite.m_sprite.handle, sprite.m_sprite.size, destRect, DirectX::Colors::Red);

	SpriteManager::GetInstance().Render(SpriteName::PlShot, m_currentPos + Camera::GetInstance().GetOffset());
	// SimpleMath::Vector2(m_collider.x, m_collider.y)
}