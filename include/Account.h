#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

// This is the Account class
class Account {
private:
    string name;
    int accNumber;
    int pin;
    double balance;

public:
    // constructor
    Account(string n, int a, int p, double b = 0.0);

    int getAccNumber();
    int getPin();
    string getName();
    double getBalance();

    void deposit(double amt);
    void withdraw(double amt);
    void transfer(Account &to, double amt);
    void showInfo();
};

#endif
