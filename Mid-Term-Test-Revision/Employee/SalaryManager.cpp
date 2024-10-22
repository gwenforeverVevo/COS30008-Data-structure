#include "SalaryManager.h"
#include <iostream>

using namespace std;

void SalaryManager::addEmployee(const Employee &employee)
{
    employees.push_back(employee);
}

double SalaryManager::calculateTotalSalary() const
{
    double total = 0;
    for (const Employee &employee : employees)
    {
        total += employee.getSalary();
    }

    // or
    int size = employee.size() for (int i = 0; i < size; i++)
    {
        total += employee.getSalary();
    }

    return total;
}

void SalaryManager::displayAll() const
{
    for (const Employee &employee : employees)
    {
        employee.display();
    }

    // or
    for (int i = 0; i < size; i++)
    {
        employee.display();
    }
}
