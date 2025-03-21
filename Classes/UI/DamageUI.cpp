//
// DamageUI.cpp
//

#include "DamageUI.h"


using namespace SimpleMath;

void DamageUI::Initialize()
{
	
}


void DamageUI::Update()
{
	 Move();
	if (m_displayTimer.TimeUp())
	{
		m_isEnd = true;
	}
}

void DamageUI::Move()
{
	m_up.Normalize();
	m_position += m_up * m_velocity * DXTK->Time.deltaTime;
}

void DamageUI::Render()
{
	SimpleMath::Vector2 offset = Camera::GetInstance().GetOffset();
	FontManager& fm = FontManager::GetInstance();
	DirectX::SpriteBatch* sp = fm.GetSpriteBatch();
	struct std::unique_ptr<FontData>& font = fm.GetFont(FontName::msgothic);
	font.get()->m_font.get()->DrawString(
		sp,
		m_damagetext.c_str(),
		m_position + offset,
		DirectX::Colors::Black,
		0.0f,
		XMFLOAT2(0.0f, 0.0f),
		1.0f
);
}
