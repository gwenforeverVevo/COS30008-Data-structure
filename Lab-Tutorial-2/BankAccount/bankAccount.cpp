#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

BankAccount::BankAccount(const string no, double initialAmt) : accNo(no)
{
	balance = initialAmt;
}

ostream& operator<<(ostream& out, const BankAccount& acc)
{
	out << "Account No: " << acc.accNo << " has RM" << acc.balance << " balance." << endl;
	return out;
}

BankAccount& BankAccount::operator+(double amount)
{
	if (amount > 0)
		balance += amount;
	return *this;
}
BankAccount& BankAccount::operator-(double amount)
{
	if (balance - amount > 10)
		balance -= amount;
	return *this;
}

bool operator<(const BankAccount&);
bool operator>(const BankAccount&);

bool BankAccount::operator==(const BankAccount& otherAcc)
{
	if (this->accNo == otherAcc.accNo)
		return true;
	return false;
}