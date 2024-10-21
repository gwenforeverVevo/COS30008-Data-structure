#ifndef CUSTOM_ITERATOR_ADAPTER_H
#define CUSTOM_ITERATOR_ADAPTER_H

#include <iterator>

// Custom Iterator Adapter to wrap an existing iterator
template <typename Iterator>
class CustomIteratorAdapter
{
private:
    Iterator it;  // Wrapped iterator

public:
    CustomIteratorAdapter(Iterator iterator);  // Constructor

    // Dereference operator
    typename std::iterator_traits<Iterator>::reference operator*() const;

    // Pre-increment and pre-decrement operators
    CustomIteratorAdapter &operator++();
    CustomIteratorAdapter &operator--();

    // Equality and inequality operators
    bool operator==(const CustomIteratorAdapter &other) const;
    bool operator!=(const CustomIteratorAdapter &other) const;
};

#endif // CUSTOM_ITERATOR_ADAPTER_H
