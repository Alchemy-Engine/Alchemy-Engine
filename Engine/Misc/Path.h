#pragma once

#include "config.h"
#include <string>

namespace Alchemy
{

class Path
{
public:
    static const std::wstring EnginePath()
    {
        return ENGINE_ROOT_DIR;
    }

    static const std::wstring ProjectPath();

    static const std::wstring ContentPath()
    {
        return EnginePath() + L"/Content";
    }

    static const std::wstring SavePath()
    {
        return EnginePath() + L"/Save";
    }

    static const std::wstring LogPath()
    {
        return SavePath() + L"/Log";
    }
};
    
} // namespace Alchemy
