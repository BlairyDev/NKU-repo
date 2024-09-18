//
// Created by blairasistin on 9/17/24.
//

#pragma once;
#include "Bank.h"
#include "Account.h"
using namespace std;

class ATM {
public:
    Bank bk;

    ATM(Bank &bk) {
        this->bk = bk;
    }

    int start();

    void transaction(Account & acct);
};


