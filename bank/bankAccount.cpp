#include "bankAccount.h"
#include <iostream>
#include <string>
using namespace std;

bankAccount::bankAccount(const string no, double intialAmt) : accNo(no)
{
    balance = intialAmt;
}

ostream &operator<<(ostream out,const bankAccount & account)
{
    // cout << "Enter account number: ";
    // in >> account.accountNo;
    // cout << "Enter acount balance price : RM";
    // in >> account.balance;;
    out << "you account number is : " << account.accountNo << ". Your balance is RM: " << account.balance << endl;

    return out;
}

bankAccount& bankAccount::operator+(double amount){
    if(balance > 0)
        balance-= amount
    return *this;
}

bankAccount& bankAccount::operator-(double amount){
    if(balance - amount > 10)
        balance-= amount
    return *this;
}

// istream &operator>(istream out, const bankAccount & account)
// {
//     out << "you account number is : " << account.accountNo << ". Your balance is RM: " << account.balance << endl;

//     return out;
// }

// bool Jobbid::operator(const JobBid &anotherJob)
// {
//     if (this->price < anotherJob.price)
//     {
//         return true;
//     }

//     return false;
// }