//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#pragma once;
#include <iostream>
#include "Bank.h"
#include "Account.h"
using namespace std;

class ATM {
public:
    Bank bk;//stores the Bank object

    //Constructor  that stores the Bank object
    ATM(Bank &bk) {
        this->bk = bk;
    }

    int start();// Starts the menu for user interface

    void transaction(Account & acct);// Selection of operations for the user to decide
};


