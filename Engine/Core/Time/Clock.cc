#include "PCH/pch.h"
#include "Clock.h"
#include <iomanip>
#include <sstream>

namespace Alchemy
{

/*
** Time format: '00:00:00'
** Stripped format: '000000'
*/
std::wstring Clock::Time(bool stripped)
{
    auto current = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(current);

    std::wstringstream wstream;
    wstream << std::put_time(std::localtime(&currentTime), L"%T");

    std::wstring timestamp = wstream.str();

    if ( stripped )
    {
        std::wstring delimiters = L":";
        for ( WCHAR delimiter : delimiters)
        {
            timestamp.erase(std::remove(timestamp.begin(), timestamp.end(), delimiter), timestamp.end());
        }
    }

    return timestamp;
}

/*
** Time format: '00-00-00'
** Stripped format: '000000'
*/
std::wstring Clock::Date(bool stripped)
{
    auto current = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(current);

    std::wstringstream wstream;
    wstream << std::put_time(std::localtime(&currentTime), L"%F");

    std::wstring timestamp = wstream.str();

    if ( stripped )
    {
        std::wstring delimiters = L"-";
        for ( WCHAR delimiter : delimiters)
        {
            timestamp.erase(std::remove(timestamp.begin(), timestamp.end(), delimiter), timestamp.end());
        }
    }

    return timestamp;

}

std::wstring Clock::DataAndTime(bool stripped)
{
    std::wstring timestamp = Clock::Date(stripped) + L" " + Clock::Time(stripped);

    if (stripped)
    {
        std::wstring delimiters = L" ";
        for (WCHAR delimiter : delimiters)
        {
            timestamp.erase(std::remove(timestamp.begin(), timestamp.end(), delimiter), timestamp.end());
        }
    }

    return timestamp;
}

} // namespace Alchemy
