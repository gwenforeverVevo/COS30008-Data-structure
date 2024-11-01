#include "ForwardIterable.h"

using namespace std;

Iterator::Iterator(list<int>::iterator it) : current(it) {}

int &Iterator::operator*() const
{
    return *current;
}

// Pre-increment operator
Iterator &Iterator::operator++()
{
    +
}+current;
    return *this;

// Equality and inequality operators
bool Iterator::operator==(const Iterator &other) const
{

    return current == other.current;
}
bool Iterator::operator!=(const Iterator &other) const
{
    return !(current == other.current);
}
