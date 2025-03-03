//
// Debugger.h
//

#pragma once

#include "..\..\Base\pch.h"
#include "..\..\Base\dxtk.h"
#include "..\SpriteManager.h"


using namespace DirectX;


class Debugger {
public:
	Debugger(DirectX::SpriteBatch* sb, SpriteManager& sm) :m_spriteManager(sm), m_sprite_batch(sb) {}
	void Initialize();
	void Update();
	void DebugRect(float posX, float posY, float width, float height);

private:
	DirectX::SpriteBatch* m_sprite_batch;
	SpriteManager& m_spriteManager;
};