#include "SimpleForwardIterator.h"

SimpleForwardIterator::SimpleForwardIterator( const DataWrapper* aCollection ) noexcept
    : fCollection( aCollection )
    , fIndex( 0 )
{


}

const DataMap& SimpleForwardIterator::operator*() noexcept
{
    return (*fCollection)[fIndex];
}

SimpleForwardIterator& SimpleForwardIterator::operator++() noexcept
{
    fIndex++;
    return *this;
}

SimpleForwardIterator
SimpleForwardIterator::operator++(int) noexcept
{
    SimpleForwardIterator lTemp = *this;
    ++fIndex;
    return lTemp;
}   

bool SimpleForwardIterator::operator==( const SimpleForwardIterator& aOther ) const noexcept
{
    return fCollection == aOther.fCollection && fIndex == aOther.fIndex;
}

bool SimpleForwardIterator::operator!=( const SimpleForwardIterator& aOther ) const noexcept
{
    return !(*this == aOther);
}

SimpleForwardIterator SimpleForwardIterator::begin() const noexcept
{
    return SimpleForwardIterator( fCollection );
}

SimpleForwardIterator SimpleForwardIterator::end() const noexcept
{
    return SimpleForwardIterator( fCollection, fCollection->size() );
}