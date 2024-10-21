class BankAccount : public Account {
public:
    BankAccount(int number, double balance, double interestRate) : Account(number, balance), interestRate(interestRate) {}

    // Modify this function to use the override keyword
    bool withdraw(double amount) override;

private:
    double interestRate;
};