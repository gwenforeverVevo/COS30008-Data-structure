#include <iostream>
#include <Job.h>

using namespace std;

Job::Job(const string aTitle, const string aCompanyName, double aBaiscPay) : fTitle(aTitle), fCompanyName(aCompanyName), fBasicPay(aBaiscPay) {
}
{

}

ostream& Job::operator<<(ostream& ostream, const Job& aJob) {

    ostream << "Title: " << aJob.fTitle << endl;
    ostream << "Company Name: " << aJob.fCompanyName << endl;
    ostream << "Basic Pay: " << aJob.fBasicPay << endl;
    return ostream
}

istream& Job::operator>>(istream& istream, Job& aJob) {

    cout << "Title: " << endl;
    istream >> aJob.fTitle << endl;
    cout << "Company Name: " << endl;
    istream >> aJob.fCompanyName << endl;
    cout << "Basic Pay: " << endl;
    istream >> aJob.fBasicPay << endl;
    return istream;

}

bool Job::operator == (const Job& aJob) const {
    return fTitle == aJob.fTitle && fCompanyName == aJob.fCompanyName && fBasicPay == aJob.fBasicPay;
}