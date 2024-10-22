#include "CollectionIterator.h"

using namespace std;

CollectionIterator::Iterator::Iterator(vector<int>::iterator it) : current(it) {}

int &CollectionIterator::Iterator::operator*() const
{
    return *current;
}

CollectionIterator::Iterator &CollectionIterator::Iterator::operator++()
{
    ++current;
    return *this;
}

// Equality and inequality operators
bool CollectionIterator::Iterator::operator==(const Iterator &other) const
{

    return current == other.current;
}
bool CollectionIterator::Iterator::operator!=(const Iterator &other) const
{
    return !(current == other.current);
}
