//
// PlayStateController.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "GameStateController.h"

using namespace DirectX;

enum class PlayState {
	Transition,
	GetItem,
	InitStage,
	Battle,
	GameClear
};

class PlayStateController  {
private:
	PlayStateController() {}
	~PlayStateController() {};
public:
	static PlayStateController& GetInstance() {
		static PlayStateController instance; 
		return instance;
	}
	PlayStateController(const PlayStateController&) = delete;
	PlayStateController& operator=(const PlayStateController&) = delete;

	void ChangeState(PlayState state);
	PlayState GetState();

private:
	PlayState m_state = PlayState::InitStage;
};

