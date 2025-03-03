//
// Camera.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "EnemyBase.h"
#include "SpriteManager.h"
#include "Collider.h"
#include "PlayerParameter.h"

using namespace DirectX;

class Camera {
private:
	Camera() {}
	SimpleMath::Vector2 m_position = SimpleMath::Vector2(0,0);

public:
	static Camera& GetInstance() {
		static Camera instance;
		return instance;
	}
	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;
	void Initialize();
	void Update();
	void Move();
	void Render(DirectX::SpriteBatch* sprite_batch);

	SimpleMath::Vector2 GetOffset() {
		return -m_position;  // プレイヤーを基準にオフセット
	}

private:
	float m_velocity = 5.0;
	float m_stageLimit_Left = -2000;
	float m_stageLimit_Right = 700;
	float m_stageLimit_Up = -2040;
	float m_stageLimit_Down = 1000;

	SimpleMath::Vector2 m_renderPos;
	PlayerParameter::Params& m_playerParams = PlayerParameter::GetInstance().GetParams();
};