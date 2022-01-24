#pragma once

// #include "BinMalloc.h"
#include "AnsiMalloc.h"

namespace Alchemy
{


/*
*  Malloc is the basic interface of memory allocation in Alchemy Engine.
*  Malloc has several implementations and you can specify one by the following using statement.
*  All Malloc implementations must include Malloc(), Realloc() and Free().
*/
using Malloc = AnsiMalloc;

    
} // namespace Alchemy
