#include "BankAccount.h"

BankAccount::BankAccount(int number, double balance, double interestRate) : Account(number, balance),interestRate(interestRate);

void BankAccount::addInterest()
{

    double interest;
    interest = getBalance() * interestRate;
    deposit(interest);
}