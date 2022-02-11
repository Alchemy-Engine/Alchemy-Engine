#pragma once

#include "PCH/pch.h"

namespace Alchemy
{

enum class EngineMode : int
{
    CLIENT,
    EDITOR,
    SERVER,
};

class Engine
{
public:
    Engine();

    ~Engine();

    void Init();

    void Tick();

    void Exit();

    static void SetEngineMode(EngineMode mode);
    static EngineMode GetEngineMode();
    static std::wstring EngineModeToString();

private:
    static EngineMode engineMode;
};


} // namespace Alchemy