//
// Collider.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SpriteManager.h"

using namespace DirectX;

class Collider {
private:
	enum class CollisionSide {
		None,
		Top,
		Bottom,
		Left,
		Right
	};

public:
	void Initialize() {};
	void Update() {};
	void Load(DirectXTK::Sprite& sprite);
	void Render(DirectX::SpriteBatch* sprite_batch);

private:

	bool isCollision = false;

	XMVECTOR m_thisApex;//xyzw z-右下のx w-右下のy 
	XMVECTOR m_yourApex;

	//当たり判定を利用する時、このクラスをincludeすること
public:
	struct ColliderRect {
		float x, y, width, height;
		string type;

		const string& GetType() const { return type; }

		bool intersects(const ColliderRect& other) const{ //true→衝突している
			float wi = width - x;
			float hei = height - y;
			bool Iscollision = 
				x          < other.width  &&
				x + wi  > other.x				&&
				y          < other.height &&
				y + hei > other.y;

			return Iscollision;
		}

		bool IsClick(SimpleMath::Vector2 mouthPos)
		{
			bool isClick =
				x          < mouthPos.x &&
				x + width  > mouthPos.x &&
				y          < mouthPos.y &&
				y + height > mouthPos.y;
			return isClick;
		}
	};
	
	DirectXTK::Sprite   sprite_;
	SimpleMath::Vector2 m_thisCollider;


	CollisionSide CollisionSide(const ColliderRect& Timer, const ColliderRect& wall)
	{
		float dx = (Timer.x + Timer.width / 2)  - (wall.x + wall.width / 2);
		float dy = (Timer.y + Timer.height / 2) - (wall.y + wall.height / 2);

		float width  = (Timer.width + wall.width)   / 2;
		float height = (Timer.height + wall.height) / 2;

		if (std::abs(dx) <= width && std::abs(dy) <= height) {
			float overlapX = width - std::abs(dx);
			float overlapY = height - std::abs(dy);

			if (overlapX > overlapY) {
				//縦方向の衝突
				if (dy > 0) {
					return CollisionSide::Top; // 壁の上側
				}
				else {
					return CollisionSide::Bottom; // 壁の下側
				}
			}
			else {
				// 横方向の衝突
				if (dx > 0) {
					return CollisionSide::Left; // 壁の左側
				}
				else {
					return CollisionSide::Right; // 壁の右側
				}
			}
		}
		return CollisionSide::None; //衝突なし
	}
};