//
// TitleManager.h
//
//メインシーンで呼ぶ。メインゲームの管理を担当する。
#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "..\StateController\GameStateController.h"
#include "..\StateController\PlayFlowController.h"
#include "Sprite,Font/SpriteManager.h"
#include "StageManager.h"
#include "BattleManager.h"
#include "PlayerManager.h"
#include "..\Camera.h"
#include "..\Collider.h"

using namespace DirectX;

class TitleManager  {
private:
	TitleManager() {}
	~TitleManager() {};
public:
	static TitleManager& GetInstance() {
		static TitleManager instance; 
		return instance;
	}

	TitleManager(const TitleManager&) = delete;
	TitleManager& operator=(const TitleManager&) = delete;

	void Initialize();
	void Update();
	void Render();

	void MakeUI();
	void MakeUICollider();
	bool GetPushStart()
	{
		return m_pushStart;
	}
private:
	int m_hp_mini = 100;
	int m_hp_big = 150;
	bool m_pushStart = false;

	SimpleMath::Vector2 m_UIPos_1 = SimpleMath::Vector2(100, 100);
	Collider::ColliderRect m_rect_1 = { 100,100,300,300 };
	int m_hp_1 = m_hp_mini;

	SimpleMath::Vector2 m_UIPos_2 = SimpleMath::Vector2(300, 100);
	Collider::ColliderRect m_rect_2 = { 300,100,600,300 };
	int m_hp_2 = m_hp_mini;

	SimpleMath::Vector2 m_UIPos_3 = SimpleMath::Vector2(500, 100);
	Collider::ColliderRect m_rect_3 = { 500,100,800,300 };
	int m_hp_3 = m_hp_mini;

	SimpleMath::Vector2 m_UIPos_4 = SimpleMath::Vector2(1000, 100);
	Collider::ColliderRect m_rect_4 = { 1000,100,1600,300 };
	int m_hp_4 = m_hp_big;

	SimpleMath::Vector2 m_UIPos_5 = SimpleMath::Vector2(950, 650);
	Collider::ColliderRect m_rect_5 = { 950,650,1078,778 };
	int m_hp_5 = m_hp_mini;

	SimpleMath::Vector2 m_UIPos_6 = SimpleMath::Vector2(1150, 650);
	Collider::ColliderRect m_rect_6 = { 1150,650,1278,778 };
	int m_hp_6 = m_hp_mini;

	SimpleMath::Vector2 m_UIPos_7 = SimpleMath::Vector2(230, 620);
	Collider::ColliderRect m_rect_7 = { 0,600,710,770 };


};

