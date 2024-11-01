#include "SimpleInputIterator.h"

using namespace std;

SimpleInputIterator::SimpleInputIterator(const vector<int> &collection) : data(collection), position(0)
{
}

const int &SimpleInputIterator::operator*() const
{
    return data[position];
}

SimpleInputIterator &SimpleInputIterator::operator++()
{

    ++position;
    return *this;
}

bool SimpleInputIterator::operator==(const SimpleInputIterator &other) const
{
    // return data[position] == other[position];
    return position == other.position;
}

bool operator!=(const SimpleInputIterator &other) const
{
    // return data[position] != other[position];
    return !(position == other.position);
}
