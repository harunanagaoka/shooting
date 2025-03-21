//
// UIFactory.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"

#include "Timer.h"
#include "FontManager.h"
#include "DamageUI.h"
#include "PlayStateController.h"
#include "StageManager.h"


using namespace DirectX;
using namespace std;

class DamageUI;

class UIFactory {
private:
	UIFactory() {};
	~UIFactory() {};
public:
	static UIFactory& GetInstance() {
		static UIFactory instance;
		return instance;
	}
	UIFactory(const UIFactory&) = delete;
	UIFactory& operator=(const UIFactory&) = delete;

	void Initialize();
	void Update();
	void Move();
	void Render();
	void MakeDamageUI(SimpleMath::Vector2 pos, float damage);
	void UpdateDamageUI();
	void RenderDamageUI();
	void DeleteEndUI();
	void DeleteAllUI();
	void EraseNullVector();
	void StartTransition();
	void RenderStageClear();
	void UpdateStageClear();

private:
	bool isTransition = false;

	float m_velocity = 1;
	vector<DamageUI*>  m_damageUI;

	SimpleMath::Vector2 m_clearTextpos = SimpleMath::Vector2(DXTK->SwapChain.Viewport.Width / 2 -100,
															 DXTK->SwapChain.Viewport.Height / 2);
	Timer m_clearTextTimer;
	float m_clearTextTime = 2;
	bool m_isClearText = false;
	bool m_isClearText_two = false;
	bool m_nextStage = false;
	wstring m_clearText = L"Stage Clear!";
	wstring m_clearText_Two = L"Next Stage";
};