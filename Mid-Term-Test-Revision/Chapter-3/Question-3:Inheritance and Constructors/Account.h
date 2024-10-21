class Account {
public:
    Account(int number, double balance) : accountNumber(number), accountBalance(balance) {}
    void deposit(double amount) { accountBalance += amount; }
    double getBalance() const { return accountBalance; }

private:
    int accountNumber;
    double accountBalance;
};