#include "SavingAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(int number, double balance, double interestRate, double minBalance) : Account(number, balance), BankAccount(interestRate), SavingAccount(minBalance){};