//
// DamageUI.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"

#include "Timer.h"
#include "FontManager.h"
#include "Camera.h"


using namespace DirectX;
using namespace std;

class DamageUI {
public:
	DamageUI(SimpleMath::Vector2 pos,int damage):m_position(pos),m_damage(damage){
		m_damagetext = std::to_wstring(m_damage);
		m_displayTimer.Set(m_displayTime);
	}
	void Initialize();
	void Update();
	void Move();
	void Render();

	bool GetIsEnd()
	{
		return m_isEnd;
	}
private:
	int m_damage;
	wstring m_damagetext;
	SimpleMath::Vector2 m_position;
	SimpleMath::Vector2 m_up = SimpleMath::Vector2(0, -1);
	bool m_isEnd = false;
	Timer m_displayTimer;
	float m_displayTime = 1.0f;

	float m_velocity = 100;
};