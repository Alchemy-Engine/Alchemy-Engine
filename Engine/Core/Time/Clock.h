#pragma once

#include <chrono>
#include <string>

namespace Alchemy
{

class Clock
{
public:
    // Get the milliseconds of the real world time
    static std::wstring Time(bool stripped = false);

    // Get the data of real world
    static std::wstring Date(bool stripped = false);

    // Get the data and time
    static std::wstring DataAndTime(bool stripped = false);
};

} // namespace Alchemy
