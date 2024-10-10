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
    return fSequenceObject;
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
    fSequenceObject.next();
    // int64_t tempPre = fIndex;
    // fIndex++;
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept
{
    FibonacciSequenceIterator temp = *this;
    ++(*this);
    return temp;
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
    return FibonacciSequenceIterator(fSequenceObject, 0);
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept
{
    //     if (numeric_limits<int64_t>::max();- fPrevious >= fCurrent) 
    // {
    //     return true;
    // }
    // return false;
    int64_t maximum = numeric_limits<int64_t>::max();
    return FibonacciSequenceIterator(maximum);
}


#include "FibonacciSequenceIterator.h"
#include <cassert>
#include <limits>
#include <iostream>

using namespace std;

FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequenceGenerator& aSequenceObject, long long aStart) noexcept
    : fSequenceObject(aSequenceObject), fIndex(aStart)
{
}

const long long& FibonacciSequenceIterator::operator*() const noexcept
{
    return fSequenceObject.current();
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept
{
    fSequenceObject.next();
    ++fIndex;
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept
{
    FibonacciSequenceIterator temp = *this;
    ++(*this);
    return temp;
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
    return FibonacciSequenceIterator(fSequenceObject, 1);
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept
{
    return FibonacciSequenceIterator(fSequenceObject, numeric_limits<long long>::max());
}