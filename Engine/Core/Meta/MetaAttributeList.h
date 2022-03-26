#pragma once

#include <concepts>
#include <tuple>


template<typename... TAttr>
class MetaAttributeList
{
public:
    constexpr MetaAttributeList(TAttr&&... attrs)
        : Attributes(std::forward<TAttr>(attrs)...)
    {}

    template<typename Func>
    constexpr void ForEach(Func&& func) const
    {
        std::apply(
            std::forward<Func>(func), Attributes);
    }

    const std::tuple<TAttr...> Attributes;
};
