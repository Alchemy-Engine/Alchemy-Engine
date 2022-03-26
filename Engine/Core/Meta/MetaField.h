#pragma once

#include "MetaAttributeList.h"
#include <string>


template<typename T, typename TAttributeList = MetaAttributeList<>>
class MetaField
{
public:
    constexpr MetaField(std::string_view name, T value, TAttributeList attrs = {})
        : Name(name), value(value), Attributes(attrs)
    {}

    std::string_view Name;
    T value;
    TAttributeList Attributes;
};




