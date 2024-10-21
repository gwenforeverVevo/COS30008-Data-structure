#include "Account.h"

using namespace std;

Account::Account(int number, double balance) : accountNumber(number), accountBalance(balance) {}

// Declare a virtual withdraw function
virtual bool Account::withdraw(double amount)
{
    if (accountBalance >= amount)
    {
        accountBalance -=amount;
        return true
    }
    else
    {
        return false;
    }
}

double getBalance() const { return accountBalance; }