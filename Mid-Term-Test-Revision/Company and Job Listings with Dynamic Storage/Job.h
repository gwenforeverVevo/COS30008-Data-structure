#ifndef JOB_H
#define JOB_H

#include <string>

class Job
{
private:
    std::string title;
    std::string company;
    double salary;

public:
    // Constructor
    Job(const std::string &title, const std::string &company, double salary);

    // Accessors
    const std::string &getTitle() const;
    const std::string &getCompany() const;
    double getSalary() const;

    // Overload output stream operator
    friend std::ostream &operator<<(std::ostream &os, const Job &job);
};

#endif // JOB_H
