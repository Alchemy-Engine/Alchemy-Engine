#pragma once


#ifdef BUILD_DLL
    #define Alchemy_API __declspec(dllexport)
#else
    #define Alchemy_API __declspec(dllimport)
#endif

const int MAX_NAME_STRING = 256;

#define HInstance() GetModuleHandle(NULL)