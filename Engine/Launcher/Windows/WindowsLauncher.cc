#include <Windows.h>
#include "Launcher/Launcher.h"

static HWND HWnd = NULL;
LPCTSTR WindowName = (LPCTSTR)"asd";
LPCTSTR WindowTitle = (LPCTSTR)"asd";

bool InitializeWindow(HINSTANCE hInstance, int ShowWnd, int width, int height, bool fullScreen)
{
    if (fullScreen)
    {
        HMONITOR hmon = MonitorFromWindow(HWnd, MONITOR_DEFAULTTONEAREST);
        MONITORINFO monitorInfo = { sizeof(monitorInfo) };
        GetMonitorInfo(hmon, &monitorInfo);

        width = monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
        height = monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top;
    }

    WNDCLASSEX wc;
    
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    // wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = NULL;
    wc.cbWndExtra = NULL;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wc.lpszMenuName = NULL;
    // wc.lpszClassName = WindowName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wc);

    HWnd = CreateWindowEx(NULL,
        WindowName,
        WindowTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        NULL,
        NULL,
        hInstance,
        NULL);

    if (fullScreen)
    {
        SetWindowLong(HWnd, GWL_STYLE, 0);
    }

    ShowWindow(HWnd, ShowWnd);
    UpdateWindow(HWnd);

    return true;
}

int WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    if (!InitializeWindow(hInstance, nCmdShow, 800, 600, false))
    {

    }

    Alchemy::EngineEntry();
    return 0;
}