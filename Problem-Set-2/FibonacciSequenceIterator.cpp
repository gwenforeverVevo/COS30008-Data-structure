#include "FibonacciSequenceIterator.h"
#include <cassert>
#include <limits>
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequenceGenerator &aSequenceObject, long long aStart) noexcept
    : fSequenceObject(aSequenceObject), fIndex(aStart)
{
}

const long long &FibonacciSequenceIterator::operator*() const noexcept
{
    // return fSequenceObject.id();
    // return fSequenceObject.current();
    // return fIndex.current();
    // this is the correct also, got it from following previous code in lab 6
    // return *fSequenceObject;
    // idk what why and how does this work
    return fSequenceObject.operator*();
}

FibonacciSequenceIterator&FibonacciSequenceIterator::operator++() noexcept
{
    // Check if there is a next Fibonacci number
    // if (!fSequenceObject.hasNext())
    // {

    //     ++fIndex;// fIndex = 93;  // Set the index to a value beyond the 92nd Fibonacci so that it somehow stops the ieeration
    //     return *this; // Do not increment further
    // }

    // Otherwise, move to the next Fibonacci number
    fSequenceObject.next();
    ++fIndex;
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept
{
    // postfix
    FibonacciSequenceIterator tempPrefix = *this;
    (*this)++;
    return tempPrefix;
    // fSequenceObject.next();
    // int64_t tempPre = fIndex;
    // fIndex++;
    // return *this;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator &aOther) const noexcept
{
    return fIndex == aOther.fIndex;
}
bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator &aOther) const noexcept
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

    return FibonacciSequenceIterator(fSequenceObject,93);
}
