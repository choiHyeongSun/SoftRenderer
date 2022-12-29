#pragma once
#include <Windows.h>
#include <cstdio>
static class TimeManager
{
private:	
	static LARGE_INTEGER llPrevCount;
	static LARGE_INTEGER llCurrentCount;
	static LARGE_INTEGER llFrequency;
	
	static UINT CallCount;
	static UINT FPS;
	static double DeltaTime;
	static double AccTime;	

public:
	
	static const void Initialization();
	static void Update(const HWND & hwnd);

	static const double GetDeltaTime()
	{
		return AccTime;
	}
	
};

