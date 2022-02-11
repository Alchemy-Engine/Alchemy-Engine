#pragma once
#include "PCH/pch.h"

namespace Alchemy
{

class Window
{
public:
    Window(std::wstring name, std::wstring title, HICON icon, int width, int height);

    virtual ~Window();

    virtual void RegisterWindowClass();
    virtual void Initialize();
    LRESULT WindowProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    HWND GetHandle() { return mHandle; }

protected:
    static  LRESULT CALLBACK SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static  LRESULT          AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    virtual LRESULT          MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    virtual LRESULT          CommonMessageHanlder(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
    std::wstring    mName;
    std::wstring    mTitle;
    HICON           mIcon;
    HWND            mHandle;
    int             mWidth;
    int             mHeight;
};
    
} // namespace Alchemy
