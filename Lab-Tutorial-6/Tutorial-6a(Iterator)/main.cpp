#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "EmployeeIterator.h"

using namespace std;

int main() {
    Employee employees[] = {
            Employee(1, "adasdd", 50000),
        Employee(2, "gasdd", 60000),
        Employee(3, "ada", 55000),
        
    };

    int size = sizeof(employees) / sizeof(employees[0]);
    EmployeeIterator iterator(employees, size);
    double totalSalary = 0;

    // for (EmployeeIterator it = iterator.begin(); it != iterator.end(); ++it) {
    //     totalSalary += (*it).getSalary();
    // }

while(iterator!=iterator.end()){
    employee rec = *
}

    cout << "Total Salary of all employees: $" << totalSalary << endl;

    return 0;
}