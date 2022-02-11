#include "PCH/pch.h"
#include "Launcher/Launcher.h"


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
    Alchemy::Logger logger;

    Alchemy::EngineEntry();
    return 0;
}