#include "DequeIterator.h"
#include <iostream>

using namespace std;

// Constructor for DequeIterator
DequeIterator::DequeIterator(const deque<int> &dq) : deque(dq) {}

// Begin and End functions to return custom iterators
DequeIterator::Iterator DequeIterator::begin()
{
    return Iterator(deque.begin());
}

DequeIterator::Iterator DequeIterator::end()
{
    return Iterator(deque.end());
}

// Constructor for nested Iterator class
DequeIterator::Iterator::Iterator(deque<int>::iterator it) : current(it) {}

// Dereference operator
int &DequeIterator::Iterator::operator*() const
{
    return *current;
}

// Pre-increment operator (++it)
DequeIterator::Iterator &DequeIterator::Iterator::operator++()
{
    ++current;
    return *this;
}

// Pre-decrement operator (--it)
DequeIterator::Iterator &DequeIterator::Iterator::operator--()
{
    --current;
    return *this;
}

// Equality operator
bool DequeIterator::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

// Inequality operator
bool DequeIterator::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}
