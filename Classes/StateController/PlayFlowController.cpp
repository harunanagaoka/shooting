//
// PlayFlowController.cpp
//タイトルでスタートを押すとメインゲームへ、初期状態はInitStage()

#include "PlayFlowController.h"

void PlayFlowController::Initialize()
{
	StageManager::GetInstance().MakeStageData();

}

void PlayFlowController::Update()
{

	PlayState state = PlayStateController::GetInstance().GetState();
	switch (state)
	{
	case PlayState::InitStage:
	{	
		
		StageManager::GetInstance().SpawnEnemy();
		BattleManager::GetInstance().Initialize();
		break;
	}
	case PlayState::GetItem:

		break;

	case PlayState::Battle:
		PlayerManager::GetInstance().Update();
		Camera::GetInstance().Update();
		BattleManager::GetInstance().Update();
		UIFactory::GetInstance().Update();

		break;

	case PlayState::Transition:
		UIFactory::GetInstance().StartTransition();
		UIFactory::GetInstance().UpdateStageClear();

		break;

	case PlayState::GameClear:
		GameStateController::GetInstance().ChangeState(GameState::Result);
		break;

	default:
		break;
	}
}

void PlayFlowController::Render()
{
	PlayState state = PlayStateController::GetInstance().GetState();
	DirectX::SpriteBatch* sp = SpriteManager::GetInstance().GetSpriteBatch();
	switch (state)
	{

	case PlayState::InitStage:
		
		break;
	
	case PlayState::GetItem:

		break;

	case PlayState::Battle:
		
		Camera::GetInstance().Render(sp);
		PlayerManager::GetInstance().Render(sp);
		BattleManager::GetInstance().Render(sp);
		BattleUI::GetInstance().Render();
		UIFactory::GetInstance().Render();

		break;

	case PlayState::Transition:
		UIFactory::GetInstance().RenderStageClear();
		break;

	default:
		break;
	}
}