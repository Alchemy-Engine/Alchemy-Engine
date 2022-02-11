#include "SplashWindow.h"
#include "Engine/Engine.h"
#include "HAL/Windows/Utils.h"
#include "Misc/Path.h"

#define WM_OUTPUTMESSAGE (WM_USER + 0x0001)

namespace Alchemy
{

SplashWindow* SplashWindow::splashWindow = nullptr;
WCHAR  SplashWindow::splashMessage[1024];

SplashWindow::SplashWindow()
    : Window(L"Alchemy", L"Alchemy Engine", NULL, 633, 413)
{
    RegisterWindowClass();
    Initialize();
}

SplashWindow::~SplashWindow()
{

}


void SplashWindow::Initialize()
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);

    RECT R = {0, 0, mWidth, mHeight};
    AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
    int width = R.right - R.left;
    int height = R.bottom - R.top;

    mHandle = CreateWindow(mName.c_str(), mTitle.c_str(), WS_POPUP, (desktop.right / 2 - mWidth / 2), 
        (desktop.bottom / 2 - mHeight / 2), mWidth, mHeight, nullptr, nullptr, HINSTANCE(), (void*)this);
    
    if ( !mHandle )
    {
        MessageBox(0, L"Failed to initialize window!", 0, 0);
        PostQuitMessage(0);
    }

    ShowWindow(mHandle, SW_SHOW);
    UpdateWindow(mHandle);
}

void SplashWindow::Open()
{
    if (splashWindow == nullptr)
    {
        splashWindow = new SplashWindow();
    }
}

void SplashWindow::Close()
{
    if (splashWindow != nullptr)
    {
        delete splashWindow;
        splashWindow = nullptr;
    }
}

void SplashWindow::AddMessage(const WCHAR* message)
{
    PostMessage(splashWindow->GetHandle(), WM_OUTPUTMESSAGE, (WPARAM)message, 0);
}

LRESULT SplashWindow::MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static std::wstring imagePath = Path::ContentPath() + L"/Images/SplashScreen/Alchemy.bmp";

    switch (message)
    {
    case WM_PAINT:
        HBITMAP hBitmap;
        HDC hdc, hmemdc;
        PAINTSTRUCT ps;

        hdc = BeginPaint(hWnd, &ps);

        AddBitmap(imagePath.c_str(), hdc);

        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(255, 255, 255));

        if ( Engine::GetEngineMode() != EngineMode::CLIENT )
        {
            std::wstring engineModeText = Engine::EngineModeToString() + L" Mode";
            SetTextAlign(hdc, TA_RIGHT);
            TextOut(hdc, mWidth - 15, 15, engineModeText.c_str(), wcslen(engineModeText.c_str()));
        }

        SetTextAlign(hdc, TA_CENTER);

        wcscpy_s(splashMessage, L"Engine Starting");
        TextOut(hdc, mWidth / 2, mHeight - 30, splashMessage, wcslen(splashMessage));
        EndPaint(hWnd, &ps);
        break;
    case WM_OUTPUTMESSAGE:
        WCHAR* msg = (WCHAR*) wParam;
        wcscpy_s(splashMessage, msg);
        RedrawWindow(GetHandle(), NULL, NULL, RDW_INVALIDATE);
        return 0;
    }

    return CommonMessageHanlder(hWnd, message, wParam, lParam);
}
    
} // namespace Alchemy
