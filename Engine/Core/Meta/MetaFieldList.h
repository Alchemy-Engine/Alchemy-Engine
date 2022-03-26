#pragma once

#include <concepts>
#include <tuple>


template<typename... TField>
class MetaFieldList
{
public:
    constexpr MetaFieldList(TField&&... fields)
        : Fields(std::forward<TField>(fields)...)
    {}

    template<typename Func>
    constexpr void ForEach(Func&& func) const
    {
        std::apply(std::forward<Func>(func), Fields);
    }

    std::tuple<TField...> Fields;
};
