//
// EnemyFactory.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include<vector>
#include "EnemyBase.h"
#include "Tri_Orange.h"
#include "ShiroMaru.h"
#include "MiyabiMaru.h"

using namespace DirectX;
using namespace std;

class EnemyFactory final {
private:
	EnemyFactory() {}
	~EnemyFactory() {};
public:
	static EnemyFactory& GetInstance() {
		static EnemyFactory instance; 
		return instance;
	}
	EnemyFactory(const EnemyFactory&) = delete;
	EnemyFactory& operator=(const EnemyFactory&) = delete;


	static vector<unique_ptr<EnemyBase>> SpawnEnemy(const EnemyName type,int count)
	{
		vector<unique_ptr<EnemyBase>> enemies;
		enemies.reserve(count);
		
		for (int i = 0; i < count; i++)
		{
			switch (type) {
			case EnemyName::TriOrange_:	enemies.push_back(std::make_unique<Tri_Orange>()); break;
			case EnemyName::ShiroMaru_:	enemies.push_back(std::make_unique<ShiroMaru>());	break;
			case EnemyName::MiyabiMaru_:enemies.push_back(std::make_unique<MiyabiMaru>());	break;
			default: return enemies;
			}
		}

		for (auto& enemy : enemies) {
			enemy->Initialize();
		}

		return enemies;
	}
};