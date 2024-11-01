#include <iostream>
#include <LocationIndexer.h>

#include <string>

using namespace std;

LocationIndexer::LocationIndexer(const Location aLocation[], size_t aSize) : fList(aLocation), size(aSize)
{
}

const Location &LocationIndexer::operator[](size_t aIndex) const
{
    if (aIndex < fSize)
    {
        return fList[aIndex];
    }
    else
    {
        throw out_of_range("Index out of range");
    }
}