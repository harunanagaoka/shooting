//
// Debugger.cpp
//

#include "Debugger.h"


using namespace SimpleMath;

void Debugger::Initialize()
{

}

void Debugger::DebugRect(float posX,float posY,float width,float height)
{
	RECT destRect = { posX, posY, posX + width, posY + height };
	SpriteData sprite = m_spriteManager.GetSprite(SpriteName::DebugTexture);
	m_sprite_batch->Draw(sprite.m_sprite.handle, sprite.m_sprite.size, destRect, DirectX::Colors::Aqua);

  
}

void Debugger::Update()
{

}
