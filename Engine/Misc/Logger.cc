#include "PCH/pch.h"
#include "Path.h"
#include <ShlObj.h>

#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

namespace Alchemy
{

Logger* Logger::logger;

Logger::Logger()
{
    logger = this;
}

Logger::~Logger()
{

}

void Logger::Log(const WCHAR* fmt, ...)
{
    WCHAR buffer[1024];
    va_list args;

    va_start(args, fmt);
    vswprintf_s(buffer, fmt, args);
    va_end(args);

    std::wfstream outFile;
    std::wstring logFilePath = std::wstring(Path::LogPath()) + L"/" + std::wstring(LogFile());
    
    if ( !std::filesystem::exists(Path::LogPath()) )
    {
        std::filesystem::create_directories(Path::LogPath());
    }

    outFile.open(logFilePath.c_str(), std::ios_base::app);

    if (outFile.is_open())
    {
        std::wstring s = buffer;
        outFile << L"[" << Clock::DataAndTime() << L"]  " << s << std::endl;
        outFile.close();
    }
    else
    {
        // MessageBox(0, L"Unable to open log file ...", L"Log Error", MB_OK);
        MessageBox(0, logFilePath.c_str(), L"Log Error", MB_OK);
    }
}

std::wstring Logger::LogFile()
{
    WCHAR file[1024];
    wcscpy_s(file, L"Alchemy"); // Alchemy should be replaced by game name
    wcscat_s(file, Clock::DataAndTime(true).c_str());
    wcscat_s(file, L".log");

    return file;
}


} // namespace Alchemy

