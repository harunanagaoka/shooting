//
// BattleUI.cpp
//

#include "BattleUI.h"

using namespace SimpleMath;

void BattleUI::Initialize(wstring content, SimpleMath::Vector2 Position)
{

}

void BattleUI::Render()
{
	int StageNum = StageManager::GetInstance().CurrentStage();
	wstring currentStage = std::to_wstring(StageNum + 1);
	m_nowStage.Render(m_stage + currentStage, m_stageUIPos);

	wstring playerHP = std::to_wstring(PlayerParameter::GetInstance().GetMaxParams().hp);
	wstring currentHP = std::to_wstring(PlayerParameter::GetInstance().GetParams().hp);
	m_nowHP.Render(currentHP + L"/" + playerHP, m_hpUIPos);

	int maxene = StageManager::GetInstance().GetStageData().enemyCount;
	int nowene = maxene - BattleManager::GetInstance().GetDestroiedEnemy();
	wstring maxEnemy = std::to_wstring(maxene);
	wstring nowEnemy = std::to_wstring(nowene);
	m_enemyes.Render(nowEnemy + L"/" + maxEnemy,m_enemyUIPos);
}



