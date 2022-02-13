#include "Window.h"

namespace Alchemy
{

Window::Window(std::wstring name, std::wstring title, HICON icon, int width, int height)
    : mName(name),
      mTitle(title),
      mIcon(icon),
      mWidth(width),
      mHeight(height)
{

}

Window::~Window()
{
    if ( mHandle != 0 )
    {
        SendMessage(mHandle, WM_SYSCOMMAND, SC_CLOSE, 0);
    }
}

void Window::RegisterWindowClass()
{
    WNDCLASSEX wc;
    
    wc.cbSize           = sizeof(WNDCLASSEX);
    wc.style            = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra       = 0;
    wc.cbWndExtra       = 0;

    wc.hIcon            = mIcon;
    wc.hIconSm          = mIcon;
    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground    = (HBRUSH)CreateSolidBrush(RGB(36, 36, 36));

    wc.lpszMenuName     = nullptr;
    wc.lpszClassName    = mName.c_str();

    wc.hInstance        = HInstance();
    wc.lpfnWndProc      = SetupMessageHandler;

    RegisterClassEx(&wc);
}

void Window::Initialize()
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);

    RECT R = {0, 0, mWidth, mHeight};
    AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
    int width = R.right - R.left;
    int height = R.bottom - R.top;

    mHandle = CreateWindow(mName.c_str(), mTitle.c_str(), WS_OVERLAPPEDWINDOW, (desktop.right / 2 - mWidth / 2), 
        (desktop.bottom / 2 - mHeight / 2), mWidth, mHeight, nullptr, nullptr, HINSTANCE(), (void*)this);
    
    if ( !mHandle )
    {
        MessageBox(0, L"Failed to initialize window!", 0, 0);
        PostQuitMessage(0);
    }

    ShowWindow(mHandle, SW_SHOW);
    UpdateWindow(mHandle);
}

LRESULT CALLBACK Window::WindowProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}
    

LRESULT CALLBACK Window::SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if ( msg == WM_NCCREATE )
    {
        const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
        Window* const pWnd = static_cast<Window*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
        SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Window::AssignMessageHandler));

        return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT Window::AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    Window* const pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
}

LRESULT Window::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch ( msg )
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT Window::CommonMessageHanlder(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hWnd, msg, wParam, lParam);
}


} // namespace Alchemy
