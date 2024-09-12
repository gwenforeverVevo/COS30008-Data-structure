
#include <iostream>
#include <string>
using namespace std;

class bankAccount
{
private:
    string accountNo;
    double balance;

public:
    
    
    
    bankAccount(const string,double);

    friend ostream &operator<<(ostream &, const bankAccount &);
    // friend ostream &operator (ostream &, const bankAccount &);
    bankAccount& operator+(double);
    bankAccount& operator-(double);
    bool operator<(const bankAccount &);
    bool operator>(const bankAccount &)
    // int operator+(const bankAccount &)
    // int operator-(const bankAccount &)
    bool operator==(const bankAccount &)
    

};


