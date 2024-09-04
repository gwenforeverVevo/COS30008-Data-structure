#include "JobBid.h"
#include <iostream>
using namespace std;

JobBid::JobBid()
{
    bidNo = 0;
    price = 0:
}

istream &operator>(istream in, JobBid &job)
{
    cout << "Enter bid number: ";
    in >> job.bidNo;
    cout << "Enter bid price : RM";
    in >> job.price;
}

istream &operator>(istream out, const &job)
{
    out << "Bid no: " << job.bidNo << ". THe price is at RM: " << job.price << endl;

    return out;
}

bool Jobbid::operator(const JobBid &anotherJob)
{
    if (this->price < anotherJob.price)
    {
        return true;
    }

    return false;
}