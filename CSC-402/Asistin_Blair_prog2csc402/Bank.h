//
// Created by blairasistin on 9/17/24.
//

#pragma once;
#include <iostream>
#include <vector>
#include <fstream>
#include "Account.h"


class Bank {

protected:
    vector<Account> bank;
    Account dummyAccount = Account();

public:
    Account& findAcct(string id, string pin);
    void addAcct(Account& acct);
    void loadAccounts(ifstream& inf);
};


