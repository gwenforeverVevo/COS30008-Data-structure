#include "FibonacciSequenceGenerator.h"
#include <string>
#include <cassert>

FibonacciSequenceGenerator::FibonacciSequenceGenerator(const std::string &aID) noexcept
    : fID(aID), fPrevious(0), fCurrent(1) {}

// Get sequence ID
const std::string &FibonacciSequenceGenerator::id() const noexcept
{
    return fID;
}

// Get current Fibonacci number
const long long &FibonacciSequenceGenerator::operator*() const noexcept
{
    return fCurrent;
}

// Type conversion to bool
FibonacciSequenceGenerator::operator bool() const noexcept
{
    // Returns true if the next fibonacci number is not negative
    if (hasNext())
        return true;
    return false;
}

// Reset sequence generator to first Fibonacci number
void FibonacciSequenceGenerator::reset() noexcept
{
    // Reset to the initial values
    fPrevious=0;
    fCurrent=1;
}

// Check if it can be computed in 64 bit system without causing buffer overflow
bool FibonacciSequenceGenerator::hasNext() const noexcept
{
    // Maximum value a long long integer can have
    long long maxValue  = 9223372036854775807;

    // Subtract current integer value from the max value to find the remaining space left
    // If remaining space is more than the value to be added (fPrevious), then the 'next' value can be computed in syste,
    return (maxValue - fCurrent) >= fPrevious;
}

// Advance to next Fibonacci number, and perform overflow assertion check
void FibonacciSequenceGenerator::next() noexcept
{
    // If evaluates to true, the code continues to execute, else the error message will be printed
    assert(hasNext() && "Error: The next number in the Fibonacci Sequence will cause an overflow");

    long long next = fCurrent + fPrevious;
    fPrevious = fCurrent;
    fCurrent=next;
}
