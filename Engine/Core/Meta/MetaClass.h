#pragma once

#include <string>
#include <tuple>
#include "MetaElements.h"

template<typename T, bool VirtualBase = false>
class MetaInheritedBase
{
public:
    static constexpr bool IsVirtualBase = VirtualBase;
    using Type = T;
};

template<typename... TBaseClass>
class MetaClassBase
{
public:
    template<typename Callable>
    static constexpr void ForEach(Callable&& func)
    {
        BaseClasses.template ForEach<Callable>(std::forward<Callable>(func));
    }

    static constexpr auto VirtualBases()
    {
        return std::tuple<>();
    }

    static constexpr MetaElements<TBaseClass...> BaseClasses = {TBaseClass{}...};
};

template<typename T>
class MetaClass;



