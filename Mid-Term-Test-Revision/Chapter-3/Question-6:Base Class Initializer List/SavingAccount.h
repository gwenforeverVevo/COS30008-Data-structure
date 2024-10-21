class SavingsAccount : public BankAccount {
public:
    // Complete the constructor with the initializer list
    SavingsAccount(int number, double balance, double interestRate, double minBalance);

private:
    double minBalance;
};
