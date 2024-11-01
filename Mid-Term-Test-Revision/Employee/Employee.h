#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
private:
    std::string fID;
    std::string fName;
    double fSalary;

public:
    // Constructor
    Employee(const std::string &id, const std::string &name, double salary);

    // Accessors
    const std::string &getID() const;
    const std::string &getName() const;
    double getSalary() const;

    // Modify salary
    void setSalary(double salary);

    // Display Employee details
    void display() const;
};

#endif // EMPLOYEE_H
