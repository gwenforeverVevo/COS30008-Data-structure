#ifndef COMPANY_H
#define COMPANY_H

#include "Job.h"
#include <vector>

class Company
{
private:
    std::string companyName;
    std::vector<Job> jobListings;

public:
    // Constructor
    Company(const std::string &name);

    // Add a job to the listing
    void addJob(const Job &job);

    // Display all jobs
    void displayJobs() const;

    // Overload output stream operator
    friend std::ostream &operator<<(std::ostream &os, const Company &company);
};

#endif // COMPANY_H
