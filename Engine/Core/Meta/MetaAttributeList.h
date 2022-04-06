#pragma once

#include <concepts>
#include <tuple>
#include "MetaElements.h"


template<typename... TAttr>
class MetaAttributeList
{
public:
    constexpr MetaAttributeList(TAttr&&... attrs)
        : AttributeList(std::forward<TAttr>(attrs)...)
    {}

    template<typename Callable>
    constexpr void ForEach(Callable&& func) const
    {
        AttributeList.template ForEach<Callable>(std::forward<Callable>(func));
    }

    MetaElements<TAttr...> AttributeList;
};
