
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
    // {
    //     bid = 10;
    //     price = 10.9;
    // }
    // JobBid(int a)
    // {
    //     bid = a;
    //     price = 10.9;
    // }
    // JobBid(int a, double b)
    // {
    //     bid = a;
    //     price = b;
    // }
    // it;
    // int getPrice()
    // {nt getBid()
    // {
    //     return bid;
    // } cons
    //     return price;
    // } const;
};


