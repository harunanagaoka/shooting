//
// BattleManager.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include<vector>
#include "PlayerAttack.h"
#include "SpriteManager.h"
#include "PlayerManager.h"
#include "StageManager.h"
#include "PlayStateController.h"
#include "CreateUI.h"
#include "UIFactory.h"
#include "EnemyBase.h"
#include "EnemyFactory.h"

using namespace DirectX;

class PlayerAttack;

class BattleManager  {
private:
	BattleManager() {}
	~BattleManager();
public:
	static BattleManager& GetInstance() {
		static BattleManager instance; 
		return instance;
	}
	BattleManager(const BattleManager&) = delete;
	BattleManager& operator=(const BattleManager&) = delete;

	void Initialize();
	void Update();
	void Render(DirectX::SpriteBatch* sprite_batch);
	void SpawnEnemy( int count) ;
	void OccurrenceATK();
	void CheckHit(PlayerAttack* atk);
	void DeleteFinishAtk();
	void DeleteAllATK();
	void DeleteisDeadEnemy();
	void DeleteAllEnemy();
	void UpdateEnemy();
	void UpdateAtk();
	bool CheckTitleHit(Collider::ColliderRect other);
	void EraseNullVector();
	void AllEnemyDestroied();
	void InitEnemyInfo();
	int GetDestroiedEnemy()
	{
		return m_destroiedEnemy;
	}

	void SpawnEnemies(EnemyName enemy,int count);

private:
	vector<EnemyBase*> m_enemies;//“G‚ÌƒŠƒXƒg
	vector<unique_ptr<EnemyBase>> m_enemytest;
	vector<PlayerAttack*> m_attack;
	

	int m_initEnemyNum = 0;
	int m_destroiedEnemy = 0;

	bool isAllEnemyDestroied = false;

};

