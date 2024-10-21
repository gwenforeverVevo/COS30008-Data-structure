class Account {
public:
    Account(int number, double balance) : accountNumber(number), accountBalance(balance) {}

    // Declare a virtual withdraw function
    virtual bool withdraw(double amount);

    double getBalance() const { return accountBalance; }

protected:
    int accountNumber;
    double accountBalance;
};