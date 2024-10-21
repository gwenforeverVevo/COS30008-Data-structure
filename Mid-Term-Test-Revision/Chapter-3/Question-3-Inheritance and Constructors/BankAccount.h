#include "Account.h"

class BankAccount : public Account {
public:
    BankAccount(int number, double balance, double interestRate);

    // Complete this function
    void addInterest();

private:
    double interestRate;
};