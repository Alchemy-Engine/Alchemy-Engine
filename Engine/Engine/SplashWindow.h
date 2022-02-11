#pragma once

#include "PCH/pch.h"
#include "Core/Window/Window.h"

namespace Alchemy
{

class SplashWindow : public Window
{
public:
    SplashWindow();
    virtual ~SplashWindow();

    virtual void Initialize() override;

    static void Open();

    static void Close();

    static void AddMessage(const WCHAR* message);

    virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

private:
    static SplashWindow* splashWindow;
    static WCHAR         splashMessage[1024];
};
    
} // namespace Alchemy
