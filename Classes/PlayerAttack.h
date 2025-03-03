//
// PlayerAttack.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SpriteManager.h"
#include "PlayerParameter.h"
#include "Collider.h"
#include "EnemyBase.h"
#include "Camera.h"
#include <unordered_set>
#include "UIFactory.h"

using namespace DirectX;

class PlayerAttack {
private:

SimpleMath::Vector2 m_atkDirection;
SimpleMath::Vector2 m_playerPos;
public:
	PlayerAttack(SimpleMath::Vector2 direction) :m_atkDirection(direction),m_playerPos(PlayerParameter::GetInstance().GetParams().position){}
	void Initialize();
	void Update();
	void Attack(SimpleMath::Vector2 direction);
	void MakeCollider();
	void AttackDuration();
	void CheckHit(EnemyBase* enemies);
	bool CheckHit(Collider::ColliderRect other);
	void HitProcess(EnemyBase* enemy);
	void UpdatePos();
	void Render(DirectX::SpriteBatch* sprite_batch, SpriteManager& sm);
	bool IsFinish() const
	{
		if (!m_isAttack)
		{
			return true;
		}
		return false;
	}

private:
	

	int m_offence_ = 50;

	float m_velocity = 3;

	float m_colliderX = 50;
	float m_colliderY = 50;

	bool m_isAttack = true;

	DirectXTK::Sprite   sprite_;
	
	SimpleMath::Vector2 m_jumpTop;

	Collider::ColliderRect m_collider;
	
	bool m_iscollision = false;

	float m_attackDuration = 2;
	float m_currentAtkTime = m_attackDuration;
	

    unordered_set<EnemyBase*> m_hitEnemies;
	unordered_set<Collider::ColliderRect*> m_hitUI;

	

 //Getinstanceでヘッダーで初期化するとバグることがある
	SimpleMath::Vector2 m_cameraPos = SimpleMath::Vector2(0, 0);
	SimpleMath::Vector2 m_specialOffset = SimpleMath::Vector2(0,0);

	SimpleMath::Vector2 m_currentPos = m_playerPos;

	SimpleMath::Vector2 m_direction;
};