#include "BidirectionalIterator.h"

using namespace std;

BidirectionalIterator::BidirectionalIterator(Node *startNode) : current(startNode)
{
}

int &BidirectionalIterator::operator*() const
{
    return current->value;
}

BidirectionalIterator &BidirectionalIterator::operator++()
{
    current = current->next;
    return *this;
}

BidirectionalIterator &BidirectionalIterator::operator--()
{
    current = current->prev;
    return *this;
}

BidirectionalIterator BidirectionalIterator::operator++(int)
{
    BidirectionalIterator temp = *this;
    current = current->next;
    return temp;
}
BidirectionalIterator BidirectionalIterator::operator--(int)
{
    BidirectionalIterator temp = *this;
    current = current->prev;
    return temp;
}

bool operator==(const BidirectionalIterator &other) const
{
    return current == other.current;
}
bool operator!=(const BidirectionalIterator &other) const
{
    return !(current == other.current);
}