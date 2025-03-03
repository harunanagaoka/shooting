//
// RenderBase.h
//

#pragma once

#include<vector>
#include "..\Base\pch.h"
#include "..\Base\dxtk.h"
#include "SpriteManager.h"

using namespace DirectX;
using namespace std;

class RenderBase  {
public:
	virtual void Render(SpriteName spriteName, SimpleMath::Vector2 position) = 0;

private:


};