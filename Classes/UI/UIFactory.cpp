//
// UIFactory.cpp
//

#include "UIFactory.h"


using namespace SimpleMath;



void UIFactory::Initialize()
{
	
}


void UIFactory::Update()
{
	UpdateDamageUI();
	DeleteEndUI();
	EraseNullVector();
}

void UIFactory::Move()
{

}

void UIFactory::Render()
{
	RenderDamageUI();
}

void UIFactory::MakeDamageUI(SimpleMath::Vector2 pos, float damage)
{
	DamageUI* ui = new DamageUI(pos, damage);
	m_damageUI.push_back(ui);
}

void UIFactory::UpdateDamageUI()
{
	for (int i = 0; i < m_damageUI.size(); i++)
	{
		if (m_damageUI[i] == nullptr)
		{
			continue;
		}

		m_damageUI[i]->Update();
	}
}

void UIFactory::RenderDamageUI()
{
	for (int i = 0; i < m_damageUI.size(); i++)
	{
		if (m_damageUI[i] == nullptr)
		{
			continue;
		}

		m_damageUI[i]->Render();
	}
}

void UIFactory::DeleteEndUI()
{
		if (m_damageUI.size() <= 0)
		{
			return;
		}

		for (auto& ui : m_damageUI) {
			if (ui->GetIsEnd()) {
				delete ui;
				ui = nullptr;
			}
		}
	
}

void UIFactory::DeleteAllUI()
{
	if (m_damageUI.size() <= 0)
	{
		return;
	}

	for (int i = 0; i < m_damageUI.size(); i++)
	{
		delete  m_damageUI[i];
		m_damageUI[i] = nullptr;
	}
}

void UIFactory::EraseNullVector()
{
	auto nullvector = std::find(m_damageUI.begin(), m_damageUI.end(), nullptr);
	if (nullvector != m_damageUI.end())
	{
		auto new_end = std::remove(m_damageUI.begin(), m_damageUI.end(), nullptr);
		m_damageUI.erase(new_end, m_damageUI.end());
	}
}

void UIFactory::StartTransition()
{
	if (isTransition)
	{
		return;
	}
	isTransition = true;
	m_isClearText = true;
	m_clearTextTimer.Set(m_clearTextTime);
}

void UIFactory::RenderStageClear()
{

	if (m_isClearText && !m_isClearText_two)
	{
		FontManager& fm = FontManager::GetInstance();
		DirectX::SpriteBatch* sp = fm.GetSpriteBatch();
		struct std::unique_ptr<FontData>& font = fm.GetFont(FontName::msgothic);
		font.get()->m_font.get()->DrawString(
			sp,
			m_clearText.c_str(),
			m_clearTextpos,
			DirectX::Colors::Black,
			0.0f,
			XMFLOAT2(0.0f, 0.0f),
			1.0f
		);
	}

	if (m_isClearText_two)
	{
		FontManager& fm = FontManager::GetInstance();
		DirectX::SpriteBatch* sp = fm.GetSpriteBatch();
		struct std::unique_ptr<FontData>& font = fm.GetFont(FontName::msgothic);
		font.get()->m_font.get()->DrawString(
			sp,
			m_clearText_Two.c_str(),
			m_clearTextpos,
			DirectX::Colors::Black,
			0.0f,
			XMFLOAT2(0.0f, 0.0f),
			1.0f
		);
	}

}

void UIFactory::UpdateStageClear()
{
	if (StageManager::GetInstance().IsLastStage() == true && PlayStateController::GetInstance().GetState() == PlayState::Transition)
	{
		PlayStateController::GetInstance().ChangeState(PlayState::GameClear);
		return;
	}

	if (m_nextStage)
	{
		PlayStateController::GetInstance().ChangeState(PlayState::InitStage);
	}
	if (m_clearTextTimer.TimeUp() && m_isClearText && !m_isClearText_two)
	{
		m_isClearText_two = true;
		m_clearTextTimer.Set(m_clearTextTime);
	}
	if (m_clearTextTimer.TimeUp() && m_isClearText && m_isClearText_two)
	{
		m_nextStage = true;
	}
}