#include "TimeManager.h"



LARGE_INTEGER TimeManager::llPrevCount;
LARGE_INTEGER TimeManager::llCurrentCount;
LARGE_INTEGER TimeManager::llFrequency;

UINT TimeManager::CallCount;
UINT TimeManager::FPS;

double TimeManager::DeltaTime;
double TimeManager::AccTime;


void const TimeManager::Initialization()
{
	QueryPerformanceCounter(&llPrevCount);
	QueryPerformanceFrequency(&llFrequency);
}



void TimeManager::Update(const HWND & hwnd)
{
	QueryPerformanceCounter(&llCurrentCount);
	DeltaTime = static_cast<double>(llCurrentCount.QuadPart - llPrevCount.QuadPart) / static_cast<double>(llFrequency.QuadPart);
	llPrevCount = llCurrentCount;
	++CallCount;

	AccTime += DeltaTime;

	if (AccTime > 1.0f)
	{
		FPS = CallCount;
		WCHAR Buff[101];
		swprintf_s(Buff, L"FPS : %d, DT : %.10f", FPS, DeltaTime);
		SetWindowTextW(hwnd, Buff);

		CallCount = 0;
		AccTime = 0;
	}

}