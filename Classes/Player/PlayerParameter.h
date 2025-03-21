//
// PlayerParameter.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SpriteManager.h"
#include "Collider.h"

using namespace DirectX;

class PlayerParameter {
public:
	struct Params {
		int hp = 100;
		int offence = 10;
		SimpleMath::Vector2 position = SimpleMath::Vector2(DXTK->SwapChain.Viewport.Width / 2,
														   DXTK->SwapChain.Viewport.Height / 2);
		float velocity = 3;
		SimpleMath::Vector2 StartcolliderSize = SimpleMath::Vector2(80, 85);
	};
private:
	Params m_currentParams;
	Params m_maxParams;
	PlayerParameter() {}
public:
	static PlayerParameter& GetInstance() {
		static PlayerParameter instance; 
		return instance;
	}
	PlayerParameter(const PlayerParameter&) = delete;
	PlayerParameter& operator=(const PlayerParameter&) = delete;

	Params& GetParams() {
		return m_currentParams;
	}

	const Params& GetMaxParams() {
		return m_maxParams;
	}

	void SetHP(int hp){
		m_maxParams.hp = std::max(hp, 0);
		m_currentParams.hp = std::min(m_currentParams.hp + hp, m_maxParams.hp);
	}

	void SetOffence(int offence) {
		m_maxParams.offence = std::max(offence, 1);
		m_currentParams = m_maxParams;
	}

	void SetPosition(SimpleMath::Vector2 position) {
		m_maxParams.position = position;
		m_currentParams = m_maxParams;
	}

	void SetVelocity(float velocity) {
		m_maxParams.velocity = std::max(velocity, 0.1f);
		m_currentParams = m_maxParams;
	}

	void Damage(int damage);
	void Recover(int Num);
private:
	int m_currentDamage = m_maxParams.hp - m_currentParams.hp;
};