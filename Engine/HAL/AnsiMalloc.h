#pragma once


namespace Alchemy
{

class AnsiMalloc
{
public:
    AnsiMalloc();

    ~AnsiMalloc();

    void* Malloc(size_t size);

    void* Realloc(void* ptr, size_t newSize);

    void Free(void* ptr);
};
    
} // namespace Alchemy
