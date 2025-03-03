//
// GameStateController.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"

using namespace DirectX;

enum class GameState {
	Title,
	MainGame,
	GameOver,
	Result
};

class GameStateController  {
private:
	GameStateController() {}
	~GameStateController() {};
public:
	static GameStateController& GetInstance() {
		static GameStateController instance; 
		return instance;
	}
	GameStateController(const GameStateController&) = delete;
	GameStateController& operator=(const GameStateController&) = delete;

	void ChangeState(GameState state);
	GameState GetState();

private:
	GameState m_state = GameState::Title;
};

