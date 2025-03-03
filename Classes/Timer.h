//
// Timer.h
//

#pragma once

#include "..\Base\pch.h"
#include "..\Base\dxtk.h"


using namespace DirectX;


class Timer {
public:
	void Initialize();
	void Update();
	void Set(float waitSeconds);
	bool TimeUp();
private:
	float m_time = 0;
};