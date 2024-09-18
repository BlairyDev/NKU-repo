//
// Created by blairasistin on 9/17/24.
//
#include <iostream>
#include "Account.h"
using namespace std;

Account::Account() {
    accountID = "";
    accountPIN = "";
    accountBalance = 0.0;
}

Account::Account(const string &accountID, const string &accountPIN, const double &accountBalance) {
    //Add checker if accountID has only 9 characters and AccountPIN is only a digit and 4 character"
    setAccountID(accountID);
    setAccountPIN(accountPIN);
    setAccountBalance(accountBalance);

}

string Account::getAccountID() {
    return accountID;
}

void Account::setAccountID(const string &accountID) {
    this->accountID = accountID;
}

string Account::getAccountPIN() {
    return accountPIN;
}

void Account::setAccountPIN(const string &accountPIN) {
    this->accountID = accountPIN;
}

double Account::getAccountBalance() {
    return accountBalance;
}

void Account::setAccountBalance(const double &accountBalance) {
    this->accountBalance = accountBalance;
}

void Account::printBalance() {
    cout << getAccountBalance() << endl;
}

void Account::Deposit(double amt) {
    setAccountBalance(accountBalance + amt);
}

void Account::Withdraw(double amt) {
    setAccountBalance(accountBalance - amt);
}



