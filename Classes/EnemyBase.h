//
// EnemyBase.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SpriteManager.h"
#include "Collider.h"

using namespace DirectX;

enum class EnemyName {
	Debug,
	BLACKRECT_,
	BrueAngle_,
	CuteStar_,
	MiyabiMaru_,
	PentaGon_,
	ShiroMaru_,
	SperStar_,
	TriMagenta_,
	TriOrange_,
	WHITEREC_T
};

class EnemyBase {
public:
	EnemyBase() {}
	virtual ~EnemyBase() {};
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual Collider::ColliderRect GetCollider() const = 0;
	virtual void AffectDamage(int offence) = 0;

	bool IsDead() const 
	{ 
		if (m_hp <= 0)
		{
			return true;
		}
		return false;
	}

	SimpleMath::Vector2 GetPosition()
	{
		return m_position;
	}
	
protected:
	int m_hp;
	int m_attack;
	float m_velocity;

	SimpleMath::Vector2 m_position;
	SimpleMath::Vector2 m_initPos;

	Collider::ColliderRect m_collider;

	float m_spriteOffset_x;
	float m_spriteOffset_y;
};