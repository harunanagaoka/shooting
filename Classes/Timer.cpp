//
// Timer.cpp
//

#include "Timer.h"


using namespace SimpleMath;

void Timer::Initialize()
{

}


void Timer::Update()
{
	TimeUp();
}

void Timer::Set(float waitSeconds)
{
	if (m_time <= 0)
	{
		m_time = waitSeconds;
	}
}

bool Timer::TimeUp()
{
	if (m_time > 0)
	{
		m_time -= DXTK->Time.deltaTime;
		return false;
	}
	return true;
}