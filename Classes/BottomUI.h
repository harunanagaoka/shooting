//
// BottomUI.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"

#pragma once

#include "SpriteManager.h"
#include "Collider.h"

using namespace DirectX;


class BottomUI {
public:
	void Initialize(float x, float y, float width, float height);
	bool IsBottunClicked();
	void ButtonRender(DirectX::SpriteBatch* sprite_batch);
private:
	Collider::ColliderRect m_Button;
};

//	if (m_testButtom.IsBottunClicked())
//{
//	èàóùì‡óe
//}