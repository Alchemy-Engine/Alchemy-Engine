#pragma once

#include "PCH/pch.h"

namespace Alchemy
{
class Logger
{
private:
    static Logger* logger;

public:
    Logger();

    ~Logger();

public:
    static Logger* Instance()
    { 
        return logger; 
    }

    static void Log(const WCHAR* fmt, ...);

private:
    static std::wstring LogFile();
};
    
} // namespace Alchemy
