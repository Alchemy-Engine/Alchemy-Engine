#include "Utils.h"
#include <fstream>

namespace Alchemy
{
    
bool AddBitmap(const WCHAR* url, HDC hdc, int x, int y)
{
    BITMAP qBitmap;
    HDC hLocalDC = CreateCompatibleDC(hdc);

    HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, url, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    if ( hBitmap == NULL )
    {
        Logger::Log(L"Missing Image: %s", url);
        return false;
    }
    GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP), reinterpret_cast<LPVOID>(&qBitmap));

    SelectObject(hLocalDC, hBitmap);

    if ( !BitBlt(hdc, x, y, qBitmap.bmWidth, qBitmap.bmHeight, hLocalDC, 0, 0, SRCCOPY) )
    {
        Logger::Log(L"Blit Failed");
        return false;
    }

    ::DeleteDC(hLocalDC);
    ::DeleteObject(hBitmap);

    return true;
}

} // namespace Alchemy

