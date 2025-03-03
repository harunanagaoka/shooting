//
// PlayerParameter.cpp
//

#include "PlayerParameter.h"


using namespace SimpleMath;

void PlayerParameter::Damage(int damage)
{
	m_currentParams.hp -= std::max(damage, 0);
}

void PlayerParameter::Recover(int Num)
{
	m_currentParams.hp = std::min(m_currentParams.hp + Num, m_maxParams.hp);
}
