#include "Map.h"
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

template <typename Key, typename Value>
Map<Key, Value>::Map(const Key &aKey, const Value &aValue) noexcept : fKey(aKey), fValue(aValue)
{
}

template <typename Key, typename Value>
const Key &Map<Key, Value>::key() const noexcept
{
    return fKey;
}

template <typename Key, typename Value>
const Value &Map<Key, Value>::value() const noexcept
{
    return fValue;
}

template <typename Key, typename Value>
template <typename U>
Map<Key, Value>::operator U() const noexcept
{
    return static_cast<U>(fValue);
}

template <typename Key, typename Value>
istream &operator>>(istream &aIStream, Map<Key, Value> &aMap)
{
    std::cout << "Enter the key of the Map: " << std::endl;
    aIStream >> aMap.fKey;

    std::cout << "Enter the value of the Map: " << std::endl;
    aIStream >> aMap.fValue;

    return aIStream;
}

template <typename Key, typename Value>
ostream &operator<<(ostream &aOStream, const Map<Key, Value> &aMap)
{
    aOStream << "{" << aMap.fKey << "," << aMap.fValue << "}" << std::endl;
    return aOStream;
}
