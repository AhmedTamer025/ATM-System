#ifndef BANK_H
#define BANK_H
#include <vector>
#include "Account.h"
using namespace std;

class Bank {
private:
    vector<Account> accounts;

    // find account by number
    Account* findAccount(int accNum);

public:
    void createAccount();
    void login();
    void showAllAccounts();
};

#endif
