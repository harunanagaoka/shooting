//
// CreateUI.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"

#pragma once

#include "SpriteManager.h"
#include "Collider.h"
#include "FontManager.h"

using namespace DirectX;


class CreateUI {
public:
	void Initialize(wstring content,SimpleMath::Vector2 Position);
	void Render();
	void Render(wstring content, SimpleMath::Vector2 Position);
private:
	SimpleMath::Vector2 m_position = SimpleMath::Vector2(0, 0);
	wstring m_content;
};

//	if (m_testButtom.IsBottunClicked())
//{
//	èàóùì‡óe
//}