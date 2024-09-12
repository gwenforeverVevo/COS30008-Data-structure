
#include <iostream>
using namespace std;

class JobBid
{
private:
    int bidNo;
    double price;

public:
    JobBid() friend istream &operator(istream &, JobBid &);
    friend ostream &operator(ostream &, const JobBid &);
    bool operator<(const JobBid &)
    
};


