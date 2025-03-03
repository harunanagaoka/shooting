//
// BGTexture.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SpriteManager.h"

using namespace DirectX;

class BGTexture {
private:
	SimpleMath::Vector2 position_ = SimpleMath::Vector2(0, 0);
	BGTexture() {};

public:
	static BGTexture& GetInstance() {
		static BGTexture instance; 
		return instance;
	}
	BGTexture(const BGTexture&) = delete;
	BGTexture& operator=(const BGTexture&) = delete;
	void Initialize();
	void Update();
private:

};