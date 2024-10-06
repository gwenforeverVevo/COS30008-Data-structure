#include "Employee.h"
#include <string>

Employee::Employee()
{
    id = 0;
    name = "";
    salary = 0;
}

Employee::Employee(int Id, string Name, double Salary)
{
    this->id = Id;
    this->name = Name;
    this->salary = Salary;
}

double Employee::getSalary()
{
    return salary;
}

ostream &operator<<(ostream out, const &Employee emp){
    out<< "ID: " << emp.id << " Name: " << emp.name << " Salary: " << emp.salary << endl;
    return out;
}