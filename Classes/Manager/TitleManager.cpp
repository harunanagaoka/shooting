//
// TitleManager.cpp
//タイトルでスタートを押すとメインゲームへ、初期状態はInitStage()

#include "TitleManager.h"

void TitleManager::Initialize()
{

}

void TitleManager::Update()
{
	PlayerManager::GetInstance().Update();
	Camera::GetInstance().Update();
	MakeUICollider();
	BattleManager::GetInstance().Update();
}

void TitleManager::Render()
{
	

	DirectX::SpriteBatch* sp = SpriteManager::GetInstance().GetSpriteBatch();
	Camera::GetInstance().Render(sp);
	PlayerManager::GetInstance().Render(sp);
	BattleManager::GetInstance().Render(sp);

	MakeUI();
}

void TitleManager::MakeUI()
{
	SpriteManager& sp = SpriteManager::GetInstance();
	//6つのUIの準備をする
	
	
	




	if (m_hp_1 > 0)
	{
		sp.Render(SpriteName::Title_1, m_UIPos_1);
	}


	if (m_hp_2 > 0)
	{
		sp.Render(SpriteName::Title_2, m_UIPos_2);
	}

	if (m_hp_3 > 0)
	{
		sp.Render(SpriteName::Title_3, m_UIPos_3);
	}
	if (m_hp_4 > 0)
	{
		sp.Render(SpriteName::Title_4, m_UIPos_4);
	}
	if (m_hp_5 > 0)
	{
		sp.Render(SpriteName::HowToShot, m_UIPos_5);
	}
	if (m_hp_6 > 0)
	{
		sp.Render(SpriteName::HowToMove, m_UIPos_6);
	}

	sp.Render(SpriteName::StartBottom, m_UIPos_7);
}

void TitleManager::MakeUICollider()
{
	BattleManager& bm = BattleManager::GetInstance();

	if (bm.CheckTitleHit(m_rect_1))
	{
		m_hp_1 -= 1;
	}


	if (bm.CheckTitleHit(m_rect_2))
	{
		m_hp_2 -= 1;
	}

	if(bm.CheckTitleHit(m_rect_3))
	{
		m_hp_3 -= 1;
	}

	if (bm.CheckTitleHit(m_rect_4))
	{
		m_hp_4 -= 1;
	}
	if (bm.CheckTitleHit(m_rect_5))
	{
		m_hp_5 -= 1;
	}
	if (bm.CheckTitleHit(m_rect_6))
	{
		m_hp_6 -= 1;
	}
	if (bm.CheckTitleHit(m_rect_7))
	{
		m_pushStart = true;
	}
}