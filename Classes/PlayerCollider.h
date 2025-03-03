//
// PlayerCollider.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SpriteManager.h"
#include "Collider.h"

using namespace DirectX;

class PlayerCollider : Collider{
private:
	ColliderRect m_collider;
	PlayerCollider() : m_collider{} {}
	PlayerCollider(float x, float y, float width, float height)
		:m_collider{ x,y,width,height } {}

public:
	static PlayerCollider& GetInstance() {
		static PlayerCollider instance;  
		return instance;
	}

	const ColliderRect& GetCollider() {
		return m_collider;
	}

	PlayerCollider(const PlayerCollider&) = delete;
	PlayerCollider& operator=(const PlayerCollider&) = delete;

	bool IsCollision(ColliderRect& other);

	void SetNewWidth(float width)
	{
		m_collider.width = std::max(width, m_collider.x);
	}

	void SetNewHeight(float height)
	{
		m_collider.height = std::max(height, m_collider.y);
	}

	void Initialize() {};
	void Update() {};
	void Render();
};