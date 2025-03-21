//
// ShiroMaru.h
//

#pragma once

#include "..\..\Base\pch.h"
#include "..\..\Base\dxtk.h"
#include "EnemyBase.h"
#include "..\Timer.h"
#include "..\Camera.h"

#include "..\Manager\PlayerManager.h"
#include "..\Player\PlayerParameter.h"


using namespace DirectX;


enum class ShiroMaruState {
	Move,
};

class ShiroMaru : public EnemyBase{
	
private:



	ShiroMaruState m_state = ShiroMaruState::Move;
public:
	ShiroMaru() {}
	void Initialize() override;
	void Update() override;
	void HandleShiroMaruState(ShiroMaruState State);
	void Move();
	void Attack();
	void UpdateCollider();
	void Render() override;
	Collider::ColliderRect GetCollider() const override;
	void AffectDamage(int offence) override;
};