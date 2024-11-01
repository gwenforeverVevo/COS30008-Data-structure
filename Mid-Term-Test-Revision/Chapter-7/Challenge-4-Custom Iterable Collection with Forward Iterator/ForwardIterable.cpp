#include "ForwardIterable.h"

using namespace std;

ForwardIterable::ForwardIterable(const list<int> &list) : data(list)
{
}

Iterator ForwardIterable::begin()
{
    return Iterator(data.begin());
}
Iterator ForwardIterable::end()
{
    return Iterator(data.end());
}