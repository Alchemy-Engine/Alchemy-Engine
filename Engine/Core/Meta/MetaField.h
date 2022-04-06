#pragma once

#include <string>
#include "MetaAttributeList.h"


template<typename T, typename TAttributeList = MetaAttributeList<>>
class MetaField
{
public:
    constexpr MetaField(std::string_view name, T&& value, TAttributeList&& attrs = {})
        : Name(name), Value(std::forward<T>(value)), AttributeList(std::forward<TAttributeList>(attrs))
    {}

    std::string_view Name;
    T Value;
    TAttributeList AttributeList;
};




