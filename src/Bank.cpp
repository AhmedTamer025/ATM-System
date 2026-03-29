#include <iostream>
#include "Bank.h"
using namespace std;

// find account pointer
Account* Bank::findAccount(int accNum) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccNumber() == accNum) {
            return &accounts[i];
        }
    }
    return nullptr;
}

// create new account
void Bank::createAccount() {
    string n;
    int a, p;
    double b;

    cout << "Enter name: ";
    cin >> ws;
    getline(cin, n);
    cout << "Enter account number: ";
    cin >> a;
    cout << "Set your PIN: ";
    cin >> p;
    cout << "Initial deposit: ";
    cin >> b;

    accounts.push_back(Account(n, a, p, b));
    cout << "Account created :) " << endl;
}

// login to account
void Bank::login() {
    int a, p;
    cout << "Enter account number: ";
    cin >> a;
    cout << "Enter PIN: ";
    cin >> p;

    Account* user = findAccount(a);
    if (user && user->getPin() == p) {
        cout << "Welcome " << user->getName() << endl;
        int choice;
        do {
            cout << "\n--- ATM ---\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Transfer\n";
            cout << "5. Show Info\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    cout << "Balance: " << user->getBalance() << endl;
                    break;
                case 2: {
                    double amt;
                    cout << "Deposit amount: ";
                    cin >> amt;
                    user->deposit(amt);
                    break;
                }
                case 3: {
                    double amt;
                    cout << "Withdraw amount: ";
                    cin >> amt;
                    user->withdraw(amt);
                    break;
                }
                case 4: {
                    int target;
                    double amt;
                    cout << "Target account #: ";
                    cin >> target;
                    cout << "Amount: ";
                    cin >> amt;
                    Account* t = findAccount(target);
                    if (t) user->transfer(*t, amt);
                    else cout << "Account not found" << endl;
                    break;
                }
                case 5:
                    user->showInfo();
                    break;
                case 0:
                    cout << "Bye :)" << endl;
                    break;
                default:
                    cout << "Wrong input" << endl;
            }
        } while(choice != 0);
    } else {
        cout << "Wrong account number or PIN!" << endl;
    }
}

// show all accounts (admin)
void Bank::showAllAccounts() {
    cout << "--- All Accounts ---" << endl;
    for (int i = 0; i < accounts.size(); i++) {
        accounts[i].showInfo();
        cout << "--------" << endl;
    }
}
