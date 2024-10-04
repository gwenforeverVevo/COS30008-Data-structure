#include "SimpleForwardIterator.h"

SimpleForwardIterator::SimpleForwardIterator(const DataWrapper *aCollection) noexcept
    : fCollection(aCollection), fIndex(0)
{
    assert(fCollection != nullptr);
}

const DataMap &SimpleForwardIterator::operator*() noexcept
{
    return (*fCollection)[fIndex];
}

SimpleForwardIterator &SimpleForwardIterator::operator++() noexcept
{
    //prefix
    fIndex++;
    return *this;
}

SimpleForwardIterator
SimpleForwardIterator::operator++(int) noexcept
{
    //postfix tbh idk why we need this
    SimpleForwardIterator Temp = *this;
    ++(*this);
    return Temp;
}

bool SimpleForwardIterator::operator==(const SimpleForwardIterator &aOther) const noexcept
{
    return fCollection == aOther.fCollection && fIndex == aOther.fIndex;
}

bool SimpleForwardIterator::operator!=(const SimpleForwardIterator &aOther) const noexcept
{
    return !(*this == aOther);
}

SimpleForwardIterator SimpleForwardIterator::begin() const noexcept
{
    return SimpleForwardIterator(fCollection);
}

SimpleForwardIterator SimpleForwardIterator::end() const noexcept
{
    return SimpleForwardIterator(fCollection, fCollection->size());
}