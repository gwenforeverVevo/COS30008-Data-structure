#include "Job.h"
#include <iostream>

using namespace std;

// Constructor to initialize the Job object
Job::Job(const string &title, const string &company, double salary)
    : title(title), company(company), salary(salary) {}

// Get the job title
const string &Job::getTitle() const
{
    return title;
}

// Get the company name
const string &Job::getCompany() const
{
    return company;
}

// Get the job salary
double Job::getSalary() const
{
    return salary;
}

// Overload output stream operator to print job details
ostream &operator<<(ostream &os, const Job &job)
{
    os << "Title: " << job.title << ", Company: " << job.company << ", Salary: " << job.salary;
    return os;
}
