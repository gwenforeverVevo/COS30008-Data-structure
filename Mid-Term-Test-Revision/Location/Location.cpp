#include <iostream>
#include <Location.h>
#include <string>

using namespace std;

Location::Location(const string aId, const string aName) : fId(aId), fName(aName)
{

}

const string Location::getLocationId() const
{
    return fId;
}