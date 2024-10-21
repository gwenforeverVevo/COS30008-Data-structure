class Account {
public:
    Account(int number, double balance) : accountNumber(number), accountBalance(balance) {}

    virtual bool withdraw(double amount) { /* Implementation */ }
    
private:
    int accountNumber;
    double accountBalance;
};