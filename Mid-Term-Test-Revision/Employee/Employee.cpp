#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(const std::string &id, const std::string &name, double salary)
    : fID(id), fName(name), fSalary(salary) {}

const std::string &Employee::getID() const
{
    return fID;
}

const std::string &Employee::getName() const
{
    return fName;
}

double Employee::getSalary() const
{
    return fSalary;
}

void Employee::setSalary(double salary)
{
    fSalary = salary;
}

void Employee::display() const
{
    cout << "Employee ID: " << fID << ", Name: " << fName << ", Salary: " << fSalary << endl;
}
