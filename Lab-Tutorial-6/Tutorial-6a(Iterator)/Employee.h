#include <iostream>
#include <string>
class Employee
{
private:
    int id;
    string name;
    double salary;

public:
    Employee();
    Employee(int, string, double);
    double getSalary();
    friend ostream &operator<<(ostream &, const Employee &);
};