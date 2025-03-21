//
// CreateUI.cpp
//

#include "CreateUI.h"

using namespace SimpleMath;


void CreateUI::Initialize(wstring content, SimpleMath::Vector2 Position)
{
	m_content = content;
	m_position = Position;
}

void CreateUI::Render()
{
	FontManager& fm = FontManager::GetInstance();
	fm.Render(m_position, m_content);
}

void CreateUI::Render(wstring content, SimpleMath::Vector2 Position)
{
	m_content = content;
	m_position = Position;
	FontManager& fm = FontManager::GetInstance();
	fm.Render(m_position, m_content);
}


