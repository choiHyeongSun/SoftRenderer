#include "InputManager.h"
#include <Windows.h>

bool const InputManager::IsKeyDown(KeyCode KeyCode)
{   
    return GetAsyncKeyState(KeyCode) & 0x0001;
}

bool const InputManager::IsKeyUp(KeyCode KeyCode)
{   
    return GetAsyncKeyState(KeyCode) & 0x8000 ? 0 : 1;    
}

bool const InputManager::IsKey(KeyCode KeyCode)
{
    return GetAsyncKeyState(KeyCode) & 0x8000 ? 1 : 0;
}
