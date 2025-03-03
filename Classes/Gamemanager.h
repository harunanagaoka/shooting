//
// Gamemanager.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include<vector>
#include "SpriteManager.h"
#include "PlayerManager.h"
#include "BattleManager.h"
#include "StageManager.h"
#include "EnemyBase.h"
#include "Slime.h"
#include "Camera.h"


using namespace DirectX;

class Gamemanager  {
private:
	Gamemanager() {}
public:
	static Gamemanager& GetInstance() {
		static Gamemanager instance; 
		return instance;
	}
	Gamemanager(const Gamemanager&) = delete;
	Gamemanager& operator=(const Gamemanager&) = delete;
	void Initialize();
	void Update();
	void Render(DirectX::SpriteBatch* sprite_batch);

private:
};

