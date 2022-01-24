#pragma once

#include "AnsiMalloc.h"
#include <cstdlib>

namespace Alchemy
{

AnsiMalloc::AnsiMalloc()
{
}

AnsiMalloc::~AnsiMalloc()
{
}

void* AnsiMalloc::Malloc(size_t size)
{
    return malloc(size);
}

void* AnsiMalloc::Realloc(void* ptr, size_t newSize)
{
    return realloc(ptr, newSize);
}

void AnsiMalloc::Free(void* ptr)
{
    free(ptr);
}

    
} // namespace Alchemy
