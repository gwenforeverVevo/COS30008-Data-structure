#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(const string &id, const string &name, int age) : fId(id), fName(name), fAge(age)
{
}

const string &Person::getID() const
{

    return fID;
}

const string &Person::getName() const{
    return fName;
}

int Person::getAge() const
{
    return fAge;
}

void Person::display() const
{
    cout << fName << fId << fAge;
}