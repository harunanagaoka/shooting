//
// PlayStateController.cpp
//

#include "PlayStateController.h"

void PlayStateController::ChangeState(PlayState state)
{
	m_state = state;
}

PlayState PlayStateController::GetState()
{
	return m_state;
}