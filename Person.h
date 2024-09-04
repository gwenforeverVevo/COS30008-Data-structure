#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int age;

public:
    Person(string fName, string lName, int age);
    void display() const;
};

#endif
