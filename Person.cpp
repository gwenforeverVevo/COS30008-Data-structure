#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string fName, string lName, int age)
    : firstName(fName), lastName(lName), age(age) {}

void Person::display() const {
    cout << "Name: " << firstName << " " << lastName << ", Age: " << age << endl;
}
