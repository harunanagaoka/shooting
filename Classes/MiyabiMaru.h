//
// MiyabiMaru.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "EnemyBase.h"
#include "Timer.h"
#include "Camera.h"

#include "PlayerManager.h"
#include "PlayerParameter.h"
#include "SpriteManager.h"

using namespace DirectX;


enum class MiyabiMaruState {
	Move,
	Stay
};

class MiyabiMaru : public EnemyBase{
public:
	MiyabiMaru() {}
	void Initialize() override;
	void Update() override;
	void HandleMiyabiMaruState(MiyabiMaruState State);
	void Move();
	void UpdateMoveDirection();
	void Attack();
	void UpdateCollider();
	void Render() override;
	Collider::ColliderRect GetCollider() const override;
	void AffectDamage(int offence) override;

private:
	MiyabiMaruState m_state = MiyabiMaruState::Move;
	Timer m_moveTimer;
	Timer m_stayTimer;
	float m_moveTime;
	float m_stayTime;

	SimpleMath::Vector2 m_moveDirection;
};