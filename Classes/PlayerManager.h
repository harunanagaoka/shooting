//
// PlayerManager.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "EnemyBase.h"
#include "SpriteManager.h"
#include "Collider.h"
#include "PlayerParameter.h"

using namespace DirectX;

class PlayerManager {
private:
	PlayerManager() {}
	SimpleMath::Vector2 position_;

	const PlayerParameter::Params& m_initParams = PlayerParameter::GetInstance().GetMaxParams();
	PlayerParameter::Params& m_currentParams = PlayerParameter::GetInstance().GetParams();

public:
	static PlayerManager& GetInstance() {
		static PlayerManager instance; // スレッドセーフな静的ローカル変数
		return instance;
	}
	// コピーコンストラクタと代入演算子を削除
	PlayerManager(const PlayerManager&) = delete;
	PlayerManager& operator=(const PlayerManager&) = delete;

	void Update();//std::vector<EnemyBase*>& enemies
	void UpdateParams();
	void move();
	void Render(DirectX::SpriteBatch* sprite_batch);
	SimpleMath::Vector2 Position();

private:
	
	int hp_ = 100;
	int offence_ = 10;

	float m_velocity = 3;
	float m_jumpPower = 5  ;
	float m_gravity = 2;

	bool m_isGround = false;
	bool m_isUp = false;
	bool m_isDown = false;

	float m_colliderx = 80;
	float m_collidery = 85;

	DirectXTK::Sprite   sprite_;
	
	SimpleMath::Vector2 m_jumpTop;

	Collider m_collider;
	
	bool m_iscollision = false;
	Collider::ColliderRect m_playerCollider;

	SimpleMath::Vector2 m_renderPos = SimpleMath::Vector2(position_.x - m_colliderx / 2, position_.y - m_collidery);
};