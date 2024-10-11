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
{ // int64_t tempHasNext =
    // temp = fPrevious + fCurrent;
    // if (numeric_limits<int64_t>::max() -fPrevious >= fCurrent)
    // {
    //     return true;
    // }
    // if (fCurrent >= 0)
    // {
    //     return true;
    // }
    if(fCurrent <= numeric_limits<int64_t>::max())
    {
        return true;
    }
    return false;
}

void FibonacciSequenceGenerator::next() noexcept
{
    if (!hasNext())
    {
       exit;
    }

    // Calculate the next Fibonacci number
    long long next = fPrevious + fCurrent;
    fPrevious = fCurrent;
    fCurrent = next;
    // over for problem set 2
    // if (fCurrent >= numeric_limits<int64_t>::max() - fPrevious) // overflow
    // {
    //     // cout << "Urm Overflow has occurred and the number has exceed the long threshold" << endl;
    //     // Fibonacci sequence generated successfully
    //     cout << "Fibonacci sequence generated successfully" << endl;
    //     // return false;
    // }

    // int64_t tempOverflow;
    // tempOverflow = fPrevious + fCurrent;
    // fPrevious = fCurrent;
    // fCurrent = tempOverflow;
    // assert(fCurrent >= fPrevious);
    // assert(numeric_limits<int64_t>::max() -fPrevious >= fCurrent);
    // assert(fCurrent >= numeric_limits<int64_t>::max() - fPrevious);
}
