//
// Created by blairasistin on 9/17/24.
//

#pragma once
#include <string>
using namespace std;

class Account {
protected:
    string accountID;
    string accountPIN;
    double accountBalance;

public:
    Account();
    Account(const string &accountID, const string &accountPIN, const double &accountBalance);

    string getAccountID();
    void setAccountID(const string &accountID);

    string getAccountPIN();
    void setAccountPIN(const string &accountPIN);

    double getAccountBalance();
    void setAccountBalance(const double &accountBalance);

    void printBalance();
    void Deposit(double amt);
    void Withdraw(double amt);

};




