//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#include <iostream>
#include "Account.h"
using namespace std;

//Default Constructor to be used if accounts are not found.
Account::Account() {
    accountID = "";
    accountPIN = "";
    accountBalance = 0.0;
}

Account::Account(const string &accountID, const string &accountPIN, const double &accountBalance) {

    bool isDigit = true;

    //This loops accountPIN char by char to check if it truly only has 0-9 Digits
    for(char c : accountPIN) {
        if(c < '0' || c > '9') {
            isDigit = false;
            break;
        }
    }

    //This checks if accountID has only 8 characters, accountPIN has only 4 characters and 0-9 digits, and accountBalance is greater than equal to 0.0
    if(accountID.size() == 8 && accountPIN.size() == 4 && isDigit && accountBalance >= 0.0){
        setAccountID(accountID);
        setAccountPIN(accountPIN);
        setAccountBalance(accountBalance);
    }
    else {
        Account();
    }

}

//Getter and Setter for AccountID
string Account::getAccountID() {
    return accountID;
}
void Account::setAccountID(const string &accountID) {
    this->accountID = accountID;
}

//Getter and Setter for AccountPIN
string Account::getAccountPIN() {
    return accountPIN;
}
void Account::setAccountPIN(const string &accountPIN) {
    this->accountPIN = accountPIN;
}

//Getter and Setter for AccountBalance
double Account::getAccountBalance() {
    return accountBalance;
}
void Account::setAccountBalance(const double &accountBalance) {
    this->accountBalance = accountBalance;
}

//Prints the account balance
void Account::printBalance() {
    cout << getAccountBalance() << endl;
}

//Deposits account balance
void Account::Deposit(double amt) {
    setAccountBalance(accountBalance + amt);
}

//Withdraws the account balance
void Account::Withdraw(double amt) {
    setAccountBalance(accountBalance - amt);
}



