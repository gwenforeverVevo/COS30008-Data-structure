#include "Company.h"
#include <iostream>

using namespace std;

// Constructor to initialize company name
Company::Company(const string &name) : companyName(name) {}

// Add a job to the company's job listings
void Company::addJob(const Job &job)
{
    jobListings.push_back(job);
}

// Display all jobs in the company
void Company::displayJobs() const
{
    for (size_t i = 0; i < jobListings.size(); i++)
    {
        cout << jobListings[i] << endl;
    }
}

// Overload output stream operator to print company details and all jobs
ostream &operator<<(ostream &os, const Company &company)
{
    os << "Company: " << company.companyName << endl;
    os << "Job Listings:" << endl;
    for (const auto &job : company.jobListings)
    {
        os << job << endl;
    }
    return os;
}
