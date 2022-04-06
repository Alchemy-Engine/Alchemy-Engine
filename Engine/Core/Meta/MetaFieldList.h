#pragma once

#include <concepts>
#include <tuple>
#include "MetaElements.h"


template<typename... TField>
class MetaFieldList
{
public:
    constexpr MetaFieldList(TField&&... fields)
        : FieldList(std::forward<TField>(fields)...)
    {}

    template<typename Callable>
    constexpr void ForEach(Callable&& func) const
    {
        FieldList.template ForEach<Callable>(std::forward<Callable>(func));
    }

    MetaElements<TField...> FieldList;
};
