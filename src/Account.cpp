#include <iostream>
#include "Account.h"
using namespace std;

// constructor
Account::Account(string n, int a, int p, double b) {
    name = n;
    accNumber = a;
    pin = p;
    balance = b;
}

// getters
int Account::getAccNumber() { return accNumber; }
int Account::getPin() { return pin; }
string Account::getName() { return name; }
double Account::getBalance() { return balance; }

// deposit money
void Account::deposit(double amt) {
    if (amt > 0) {
        balance += amt;
        cout << "You deposited: " << amt << endl;
        cout << "New balance: " << balance << endl;
    } else {
        cout << "Amount invalid" << endl;
    }
}

// withdraw money
void Account::withdraw(double amt) {
    if (amt > 0 && amt <= balance) {
        balance -= amt;
        cout << "You withdrew: " << amt << endl;
        cout << "New balance: " << balance << endl;
    } else {
        cout << "Not enough money or invalid amount" << endl;
    }
}

// transfer money to another account
void Account::transfer(Account &to, double amt) {
    if (amt > 0 && amt <= balance) {
        balance -= amt;
        to.balance += amt;
        cout << "Transferred " << amt << " to " << to.getName() << endl;
    } else {
        cout << "Cannot transfer, check balance or amount" << endl;
    }
}

// show account info
void Account::showInfo() {
    cout << "Name: " << name << endl;
    cout << "Account #: " << accNumber << endl;
    cout << "Balance: " << balance << endl;
}
