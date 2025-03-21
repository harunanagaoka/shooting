//
// Tri_Orange.h
//

#pragma once

#include <random>
#include <iostream>

#include "..\..\Base\pch.h"
#include "..\..\Base\dxtk.h"
#include "EnemyBase.h"
#include "..\Timer.h"
#include "..\Camera.h"

#include "..\Manager\PlayerManager.h"
#include "..\Player\PlayerParameter.h"
#include "..\Manager\Sprite,Font\SpriteManager.h"

using namespace DirectX;


enum class Tri_OrangeState {
	Move,
	Stay_Right,
	Stay_Left,
};

class Tri_Orange : public EnemyBase{
public:
	Tri_Orange() {}
	void Initialize() override;
	void Update() override;
	void HandleTri_OrangeState(Tri_OrangeState State);
	void Move();
	void UpdateMoveDirection();
	void Attack();
	void UpdateCollider();
	void Render() override;
	Collider::ColliderRect GetCollider() const override;
	void AffectDamage(int offence) override;
	std::mt19937& GetRandEngine();
	float MakeRandomNum(float min, float max);

private:
	Tri_OrangeState m_state = Tri_OrangeState::Stay_Right;
	Timer m_moveTimer_Right;
	Timer m_moveTimer_Left;
	Timer m_stayTimer;

	SimpleMath::Vector2 m_moveDirection;
	SimpleMath::Vector2 m_shakeDirection;

	float m_rotate;
	float m_shakeVelocity = 200;
	float m_MoveTime = 0;
	float m_toRightTime_Max = 2;
	float m_toRightTime_Min = 0.5;
	float m_toLeftTime_Max = 2;
	float m_toLeftTime_Min = 0.5;

	bool m_isleft = false;
	bool m_isright = true;




};