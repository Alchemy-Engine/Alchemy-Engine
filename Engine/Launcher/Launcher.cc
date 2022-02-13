#include "PCH/pch.h"

#include "Launcher.h"
#include "Engine/Engine.h"
#include "Engine/SplashWindow.h"
#include <memory>

namespace Alchemy
{

Engine* GEngine = nullptr;


void EngineEntry()
{
    SplashWindow::Open();

    EngineInit();

    Sleep(855);

    SplashWindow::Close();

    auto wnd = new Window(L"Alchemy", L"Alchemy Engine", NULL, 1200, 900);
    wnd->RegisterWindowClass();
    wnd->Initialize();

    EngineLoop();

    EngineExit();
    delete wnd;
}

void EngineInit()
{
    GEngine = new Engine();
    GEngine->Init();
}

void EngineLoop()
{
    MSG msg = { 0 };
    while ( true )
    {
        if ( PeekMessage(&msg, 0, 0, 0, PM_REMOVE) )
        {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            GEngine->Tick();
        }
    }
}

void EngineExit()
{
    GEngine->Exit();
    delete GEngine;
    Logger::Log(L"Stop Engine");
}

} // namespace Alchemy
