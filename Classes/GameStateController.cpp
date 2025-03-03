//
// GameStateController.cpp
//

#include "GameStateController.h"

void GameStateController::ChangeState(GameState state)
{
	m_state = state;
}

GameState GameStateController::GetState()
{
	return m_state;
}
