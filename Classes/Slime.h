//
// Slime.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "EnemyBase.h"
#include "Timer.h"
#include "Camera.h"

#include "PlayerManager.h"

using namespace DirectX;


enum class SlimeState {
	Idle,
	LockOn,
	Attack
};

class Slime : public EnemyBase{
	
private:
	SimpleMath::Vector2 m_position;
	SimpleMath::Vector2 m_initPos;
	bool m_isIdleTimerSet = false;
	Timer m_idleTimer;
	bool m_isGoRight = false;
	bool m_isGoLeft = true;
	float m_idleTime = 5;
	float m_idleVelosity = 100;
	float m_idleArea = 50;
	float m_idleAreaLeft_x = 0;
	float m_idleArearight_x = 0;

	Timer m_LockOnTimer;
	float m_lockOnTime = 2;
	bool m_isLockOnTimeSet = false;
	SimpleMath::Vector2 m_atkDirection;

	SlimeState m_state = SlimeState::Idle;
public:
	Slime() {}
	void Initialize() override;
	void Update() override;
	void HandleSlimeState(SlimeState State);
	void Move();
	SimpleMath::Vector2 Position();
	void LockOn();
	void Attack();
	void Render() override;
	Collider::ColliderRect GetCollider() const override;
	void AffectDamage(int offence) override;
};