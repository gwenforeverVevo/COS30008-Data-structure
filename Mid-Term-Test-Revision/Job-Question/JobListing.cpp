#include <iostream>
#include <JobListing.h>

using namespace std;

JobListing::JobListing(const string aYear, int aMaxList, int aTotalList) : fYear(aYear), fMaxList(aMaxList)
{

    // fTotalList = 0;
    fJobList = new Job[aMaxList];
}

JobListing::~JobListing()
{
    delete[] fJobList;
}

ostream& operator<<(ostream &ostream, const JobListing &aJobListing)
{

    ostream << "Year: " << aJobListing.fYear << endl;
    ostream << "Max List: " << aJobListing.fMaxList << endl;
    ostream << "Total List: " << aJobListing.fTotalList << endl;
    for (int i = 0; i < aJobListing.fTotalList; i++)
    {
        ostream << aJobListing.fJobList[i] << endl;
    }
    return ostream
}

istream& operator<<(istream &istream, const JobListing &aJobListing)
{

    cout << "Enter year: ";
    istream >> aJobListing.fYear;
    cout << "Enter total list: ";
    istream >> aJobListing.fTotalList;
    for (int i = 0; i < aJobListing.fTotalList; ++i)
    {
        cout << "Enter job " << i + 1 << ":" << endl;
        in >> aJobListing.fJobList[i];
    }
    return istream;
}

JobListing &JobListing::operator+(const Job& aJob)
{
    if (fTotalList < fMaxList)
    {
        fTotalList++;
        fJoblist[fTotalList] = aJob;  // Add job to the list
    }
    return *this;
}

JobListing &JobListing::operator-(const Job& aJob)
{
    for (int i = 0; i < fTotalList; i++)
    {
        if (fJobList[i] == aJob)
        {
            // Replace the job at index i with the last job in the list
            fJobList[i] = fJobList[fTotalList - 1];
            fTotalList--;
             break;;  // Exit the loop once the job is removed
        }
    }
    return *this;
}
