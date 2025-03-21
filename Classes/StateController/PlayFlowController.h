//
// PlayFlowController.h
//
//メインシーンで呼ぶ。メインゲームの管理を担当する。
#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "GameStateController.h"
#include "PlayStateController.h"
#include "SpriteManager.h"
#include "StageManager.h"
#include "BattleManager.h"
#include "PlayerManager.h"
#include "Camera.h"
#include "BattleUI.h"
#include "UIFactory.h"

using namespace DirectX;

class PlayFlowController  {
private:
	PlayFlowController() {}
	~PlayFlowController() {};
public:
	static PlayFlowController& GetInstance() {
		static PlayFlowController instance; 
		return instance;
	}

	PlayFlowController(const PlayFlowController&) = delete;
	PlayFlowController& operator=(const PlayFlowController&) = delete;

	void Initialize();
	void Update();
	void Render();
};

