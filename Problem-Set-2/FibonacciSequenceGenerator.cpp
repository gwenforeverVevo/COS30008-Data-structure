#include "FibonacciSequenceGenerator.h"
#include <cassert>
#include <limits>
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

FibonacciSequenceGenerator::FibonacciSequenceGenerator(const string &aID) noexcept
    : fID(aID), fPrevious(0), fCurrent(1)
{
}
const string &FibonacciSequenceGenerator::id() const noexcept
{
    return fID;
}

const long long &FibonacciSequenceGenerator::operator*() const noexcept
{
    // if(fCurrent < 0)
    //     {
    //         return fCurrent;
    //     }
    return fCurrent;
}

FibonacciSequenceGenerator::operator bool() const noexcept
{

    // Checking if the current number is greater than 0
    // return fCurrent > 0 && fCurrent <= numeric_limits<int64_t>::max();
    // WHAT IS THE DIFFERENCE BETWEEN THIS AND THE ONE ABOVE
    return hasNext();
}

void FibonacciSequenceGenerator::reset() noexcept
{
    fPrevious = 0;
    fCurrent = 1;
}

bool FibonacciSequenceGenerator::hasNext() const noexcept
{
    // Check for potential overflow before it happens
    if (fCurrent > numeric_limits<int64_t>::max() - fPrevious)
    {
        return false;
    }
    return true;
}
void FibonacciSequenceGenerator::next() noexcept
{
    // I HATE THIS FUNCTION
    if(!hasNext())
    {
        return;
    }
    assert(hasNext());
    // long long temp = fCurrent;
    // fCurrent += fPrevious;
    // fPrevious = temp;
    long long tempNext = fCurrent + fPrevious;
    fPrevious = fCurrent;
    fCurrent = tempNext;
}