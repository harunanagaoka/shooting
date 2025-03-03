//
// PlayerCollider.cpp
//

#include "PlayerCollider.h"

using namespace SimpleMath;

void PlayerCollider::Render()
{

}

bool PlayerCollider::IsCollision(ColliderRect& other)
{
	if (m_collider.intersects(other))
	{
		return true;
	}
	return false;
}


