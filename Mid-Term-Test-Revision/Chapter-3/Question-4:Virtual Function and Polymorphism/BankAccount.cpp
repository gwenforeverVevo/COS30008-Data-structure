#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount(int number, double balance, double interestRate) : Account(number, balance), interestRate(interestRate) {}

bool BankAccount::withdraw(double amount) override
{

    if (amount <= accountBalance)
    {
        accountBalance -= amount; // Deduct amount from balance
        cout << "Withdrawal successful! New balance: " << accountBalance << endl;
        return true;
    }
    else
    {
        cout << "Insufficient funds for withdrawal." << endl;
        return false;
    }
}