#pragma once

#include <concepts>
#include <string_view>
#include <tuple>


namespace Alchemy::Meta::Detail
{

template<size_t Index = 0, typename Callable, typename TTuple, size_t TupleSize = std::tuple_size_v<std::remove_reference_t<TTuple>>>
constexpr void ForEach(Callable&& func, TTuple&& tuple)
{
    if constexpr ( Index < TupleSize )
    {
        std::forward<Callable>(func)(std::get<Index>(std::forward<TTuple>(tuple)));
        ForEach<Index + 1>(std::forward<Callable>(func), std::forward<TTuple>(tuple));
    }
}

template<size_t Index = 0, typename TTarget, typename TTuple, size_t TupleSize = std::tuple_size_v<std::remove_reference_t<TTuple>>>
constexpr size_t FindElement(TTuple&& tuple)
{
    if constexpr ( Index < TupleSize )
    {
        using ElementType = decltype(std::get<Index>(std::forward<TTuple>(tuple)));
        return std::is_same_v<std::decay_t<TTarget>, ElementType>
            ? Index : FindElement<Index + 1, TTarget>(std::forward<TTuple>(tuple));
    }
    else
    {
        return Index;
    }
}

template<size_t Index = 0, typename TTarget, typename TTuple, size_t TupleSize = std::tuple_size_v<std::remove_reference_t<TTuple>>>
constexpr bool FindType(TTuple&& tuple)
{
    if constexpr ( Index < TupleSize )
    {
        using ElementType = decltype(std::get<Index>(std::forward<TTuple>(tuple)));
        return std::is_same_v<std::decay_t<TTarget>, ElementType>
            ? true : FindType<Index + 1, TTarget>(std::forward<TTuple>(TupleSize));
    }
    else
    {
        return false;
    }
}

template<size_t Index = 0, typename TTuple, size_t TupleSize = std::tuple_size_v<std::remove_reference_t<TTuple>>>
constexpr auto CollectVirtualBases(TTuple&& tuple)
{
    if constexpr ( Index < TupleSize )
    {
        auto subVirtualBases = CollectVirtualBases<Index + 1>(std::forward<TTuple>(tuple));

        using ElementType = decltype(std::get<Index>(std::forward<TTuple>(tuple)));
        if constexpr ( ElementType::IsVirtualBase and not FindType<ElementType>(subVirtualBases) )
        {
            return std::tuple_cat(subVirtualBases, std::get<Index>(std::forward<TTuple>(tuple)));
        }
        else
        {
            return subVirtualBases;
        }
    }
    else
    {
        return std::tuple<>();
    }
}


}

template<typename... TElement>
class MetaElements
{
public:
    constexpr MetaElements(TElement&&... elements)
        : Elements(std::forward<TElement>(elements)...)
    {}

    template<typename Callable>
    constexpr void ForEach(Callable&& func) const
    {
        Alchemy::Meta::Detail::ForEach(std::forward<Callable>(func), Elements);
    }

    std::tuple<TElement...> Elements;
};

