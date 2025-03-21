//
// BottomUI.cpp
//

#include "BottomUI.h"

using namespace SimpleMath;

void BottomUI::Initialize(float x, float y, float width, float height)
{
	m_Button.x = x;
	m_Button.y = y;
	m_Button.width = width;
	m_Button.height = height;
}

bool BottomUI::IsBottunClicked()
{
	if (InputSystem.Mouse.was.leftButton == InputSystem.Mouse.was.PRESSED && m_Button.IsClick(InputSystem.Mouse.position))
	{
		return true;
	}
	return false;
}

void BottomUI::ButtonRender(DirectX::SpriteBatch* sprite_batch)
{
	SpriteManager& spriteManager = SpriteManager::GetInstance();
	spriteManager.Render(spriteManager.GetSprite(SpriteName::PlayerSide), SimpleMath::Vector2(m_Button.x, m_Button.y), sprite_batch);
}



