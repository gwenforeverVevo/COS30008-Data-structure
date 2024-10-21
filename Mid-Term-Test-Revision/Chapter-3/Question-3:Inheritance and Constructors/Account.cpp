#include <iostrean>
#include "Account.h"

using namespace std;

Account::Account(int number, double balance) : accountNumber(number), accountBalance(balance) {}

void Account::deposit(double amount) { accountBalance += amount; }

double Account::getBalance() const { return accountBalance; }
