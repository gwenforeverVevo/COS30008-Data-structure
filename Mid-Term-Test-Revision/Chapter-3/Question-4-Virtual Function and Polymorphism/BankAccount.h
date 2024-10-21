#include "Account.h"

class BankAccount : public Account {
public:
    BankAccount(int number, double balance, double interestRate) : Account(number, balance), interestRate(interestRate) {}

    // Override the withdraw method for BankAccount
    bool withdraw(double amount) override;

private:
    double interestRate;
};