#include "EmployeeIterator.h"

EmployeeIterator::EmployeeIterator(const Employee aEmpList[], const int aSize, int aStart)
    : fEmpList(aEmpList), fSize(aSize), fIndex(aStart)
{
}

const Employee &EmployeeIterator::operator*() const
{
    return fEmpList[fIndex];
}

EmployeeIterator &EmployeeIterator::operator++()
{
    ++fIndex;
    return *this;
}

EmployeeIterator &EmployeeIterator::operator++(int)
{
    EmployeeIterator temp = *this;
    ++(*this);
    return temp;
}

bool EmployeeIterator::operator==(const EmployeeIterator &aOther) const
{
    // return fEmpList == aOther.fEmpList && fIndex == aOther.fIndex;
    if (fEmpList == aOther.fEmpList && fIndex == aOther.fIndex)
    {
        return true;
    }
    return false;
}

bool EmployeeIterator::operator!=(const EmployeeIterator &aOther) const
{
    return !(*this == aOther);
}

EmployeeIterator EmployeeIterator::begin() const
{
    return EmployeeIterator(fEmpList, fSize);
}

EmployeeIterator EmployeeIterator::end() const
{
    return EmployeeIterator(fEmpList, fSize, fSize);
}