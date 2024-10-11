#include "FibonacciSequenceIterator.h"
#include <cassert>
#include <limits>
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequenceGenerator& aSequenceObject, long long aStart) noexcept
    : fSequenceObject(aSequenceObject), fIndex(aStart)
{
}

const long long& FibonacciSequenceIterator::operator*() const noexcept
{
    // return fSequenceObject.id();
    // return fSequenceObject.current();
    // return fIndex.current();
    // return *fSequenceObject;
    return fSequenceObject.operator*();
}
// FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept
// {
//     fSequenceObject.next();
//     tempPre = fIndex;
//     fIndex++;
//     tempPre ->*this;
//     return *this;
// }


FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept
{
    //prefix
    fSequenceObject.next();
    // int64_t tempPre = fIndex;
    ++fIndex;
    return *this;
    // fSequenceObject.next();
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept
{
    //postfix
    FibonacciSequenceIterator tempPrefix = *this;
    (*this)++;
    return tempPrefix;
    // fSequenceObject.next();
    // int64_t tempPre = fIndex;
    // fIndex++;
    // return *this;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept
{
    return fIndex == aOther.fIndex;
}
bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const noexcept
{
    return fIndex != aOther.fIndex;
}
FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept
{   
    // return FibonacciSequenceIterator(fSequenceObject, 0);
    return FibonacciSequenceIterator(fSequenceObject, 1);
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept
{
    //     if (numeric_limits<int64_t>::max();- fPrevious >= fCurrent) 
    // {
    //     return true;
    // }
    // return false;
    // int64_t maximum = numeric_limits<int64_t>::max();
    return FibonacciSequenceIterator(fSequenceObject, numeric_limits<long long>::max());
}


