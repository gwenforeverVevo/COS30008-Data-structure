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
const string& FibonacciSequenceGenerator::id() const noexcept
{
    return fID;
}

const long long& FibonacciSequenceGenerator::operator*() const noexcept
{
    return fCurrent;
}

FibonacciSequenceGenerator::operator bool() const noexcept
{
    return fCurrent > 0;
}

void FibonacciSequenceGenerator::reset() noexcept
{
    fPrevious = 0;
    fCurrent = 1;
}

bool FibonacciSequenceGenerator::hasNext() const noexcept
{   //int64_t tempHasNext = 
    // temp = fPrevious + fCurrent;
    if (numeric_limits<int64_t>::max();- fPrevious >= fCurrent) 
    {
        return true;
    }
    return false;
}

void FibonacciSequenceGenerator::next() noexcept
{
    int64_t temp;   
    temp = fPrevious + fCurrent;
    fPrevious = fCurrent;
    fCurrent = temp;
    assert(fCurrent < fPrevious);
}


