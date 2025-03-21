//
// StageManager.cpp
//

#include "StageManager.h"


void StageManager::Initialize()
{
	InitStageData();
	MakeStageData();
}

void StageManager::InitStageData()
{
	m_myCurrentStage = 0;
}

void StageManager::AddStage()
{
	m_myCurrentStage += 1;
}

StageManager::StageData StageManager::GetStageData()
{
	return m_stageData[m_myCurrentStage];
}

void StageManager::MakeStageData()
{
	m_allStage = 2;

	StageData Stage_one;
	Stage_one.enemyCount = 10000;
	m_stageData.push_back(Stage_one);

	StageData Stage_two;
	Stage_two.enemyCount = 10;
	m_stageData.push_back(Stage_two);
}

void StageManager::SpawnEnemy()
{
	BattleManager& bm = BattleManager::GetInstance();
	PlayStateController& state = PlayStateController::GetInstance();

	int enemyCount = GetStageData().enemyCount;
	if (m_myCurrentStage == 0) //ステージ１
	{
		int enemyone = 10000;
		int enemytwo = 0;

			bm.SpawnEnemies(EnemyName::TriOrange_, enemyone);

			//bm.SpawnEnemies(EnemyName::MiyabiMaru_, enemytwo);

		state.ChangeState(PlayState::Battle);
	}

	if (m_myCurrentStage == 1)//ステージ2
	{
		for (int i = 0; i < enemyCount; i++)
		{
			bm.SpawnEnemies(EnemyName::TriOrange_, 1);
		}
		state.ChangeState(PlayState::Battle);
	}

}