//
// BattleUI.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "StageManager.h"
#include "SpriteManager.h"
#include "Collider.h"
#include "FontManager.h"
#include "CreateUI.h"
#include "PlayerParameter.h"
#include "BattleManager.h"

using namespace DirectX;


class BattleUI {
private:
	BattleUI() {}
public:
	static BattleUI& GetInstance() {
		static BattleUI instance;
		return instance;
	}

	BattleUI(const BattleUI&) = delete;
	BattleUI& operator=(const BattleUI&) = delete;

	void Initialize(wstring content, SimpleMath::Vector2 Position);
	void Render();
private:
	CreateUI m_nowStage;
	SimpleMath::Vector2 m_stageUIPos = SimpleMath::Vector2(10, 10);
	wstring m_stage = L"Stage";

	CreateUI m_nowHP;
	SimpleMath::Vector2 m_hpUIPos = SimpleMath::Vector2(200, 10);

	CreateUI m_enemyes;
	SimpleMath::Vector2 m_enemyUIPos = SimpleMath::Vector2(500, 10);
};