#include "Map.h"
#include <iostream>

// Constructor implementation
template <typename Key, typename Value>
Map<Key, Value>::Map(const Key &aKey, const Value &aValue) noexcept : fKey(aKey), fValue(aValue)
{
}

// Getter for the key
template <typename Key, typename Value>
const Key &Map<Key, Value>::key() const noexcept
{
    return fKey;
}

// Getter for the value
template <typename Key, typename Value>
const Value &Map<Key, Value>::value() const noexcept
{
    return fValue;
}

// Type conversion operator
template <typename Key, typename Value>
template <typename U>
Map<Key, Value>::operator U() const noexcept
{
    return static_cast<U>(fValue);  // Convert the Value to type U
}

// Overload the input stream operator >>
template <typename Key, typename Value>
std::istream &operator>>(std::istream &aIStream, Map<Key, Value> &aMap)
{
    std::cout << "Enter the key: ";
    aIStream >> aMap.aKey;
    std::cout << "Enter the value: ";
    aIStream >> aMap.aValue;
    return aIStream;
}

// Overload the output stream operator <<
template <typename Key, typename Value>
std::ostream &operator<<(std::ostream &aOStream, const Map<Key, Value> &aMap)
{
    aOStream << "{" << aMap.aKey << ", " << aMap.aValue << "}";
    return aOStream;
}

// Explicit template instantiation for the types you will use (int for example)
template class Map<int, int>;
template std::istream &operator>>(std::istream &aIStream, Map<int, int> &aMap);
template std::ostream &operator<<(std::ostream &aOStream, const Map<int, int> &aMap);
