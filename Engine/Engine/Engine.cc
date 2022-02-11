#include "Engine.h"


namespace Alchemy
{
EngineMode Engine::engineMode;

Engine::Engine()
{
#if defined(CLIENT)
    mEngineMode = EngineMode::CLIENT;
#elif defined(EDITOR)
    mEngineMode = EngineMode::EDITOR;
#elif defined(SERVER)
    mEngineMode = EngineMode::SERVER;
#endif
}


Engine::~Engine()
{

}

void Engine::Init()
{
    Logger::Log(L"Engine Starting...");
    Logger::Log(L"Boot Time: %s", Clock::DataAndTime().c_str());
    Logger::Log(L"Engine Mode: %s", EngineModeToString().c_str());
}

void Engine::Tick()
{

}

void Engine::Exit()
{

}

void Engine::SetEngineMode(EngineMode mode)
{
    engineMode = mode;
}

EngineMode Engine::GetEngineMode()
{
    return engineMode;
}

std::wstring Engine::EngineModeToString()
{
    return [](EngineMode mode){
        switch (mode)
        {
        case EngineMode::CLIENT:
            return std::wstring(L"CLIENT");
        case EngineMode::EDITOR:
            return std::wstring(L"EDITOR");
        case EngineMode::SERVER:
            return std::wstring(L"SERVER");
        default:
            return std::wstring(L"UNKOWN");
        }
    }(engineMode);
}
    
} // namespace Alchemy
