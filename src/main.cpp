#include <iostream>
#include "Bank.h"
using namespace std;

int main() {
    Bank bank;
    int opt;

    do {
        cout << "\n=== My ATM ===\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Show All Accounts\n";
        cout << "0. Exit\n";
        cout << "Option: ";
        cin >> opt;

        switch(opt) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.login();
                break;
            case 3:
                bank.showAllAccounts();
                break;
            case 0:
                cout << "Bye!" << endl;
                break;
            default:
                cout << "Try again :)" << endl;
        }
    } while(opt != 0);

    return 0;
}
