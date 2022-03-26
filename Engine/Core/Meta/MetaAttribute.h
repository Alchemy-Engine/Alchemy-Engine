#pragma once

#include <functional>
#include <string>


template<typename T>
class MetaAttribute
{
public:
    constexpr MetaAttribute(std::string_view attr, T value)
        : Name(attr), Value(value)
    {}

    std::string_view Name;
    T Value;
};

template<>
class MetaAttribute<void>
{
public:
    constexpr MetaAttribute(std::string_view attr)
        : Name(attr)
    {}

    std::string_view Name;
};
