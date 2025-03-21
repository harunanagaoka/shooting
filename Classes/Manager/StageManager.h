//
// StageManager.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include <vector>
#include "..\Enemy\EnemyBase.h"
#include "BattleManager.h"
#include "..\StateController\PlayFlowController.h"

using namespace DirectX;



class StageManager {
private:
	StageManager() {}
	
public:
	static StageManager& GetInstance() {
		static StageManager instance;
		return instance;
	}
	StageManager(const StageManager&) = delete;
	StageManager& operator=(const StageManager&) = delete;

	void Initialize();

	struct StageData {
		int enemyCount;   // “G‚Ì‘”
		EnemyName nameone;
		
	};

	void AddStage();
	int CurrentStage() { return m_myCurrentStage; }
	void MakeStageData();
	void SpawnEnemy();
	bool IsLastStage() { return m_myCurrentStage == m_allStage; }
	StageData GetStageData();
	void InitStageData();
	

private:
	int m_myCurrentStage = 0;

	int m_allStage = -1;

	float m_velocity = 5.0;

	SimpleMath::Vector2 m_renderPos;

	std::vector<StageData> m_stageData;

	bool m_isLastStage = false;

	
};