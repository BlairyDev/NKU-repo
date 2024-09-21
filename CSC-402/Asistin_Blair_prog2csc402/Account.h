//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#pragma once
#include <string>
using namespace std;

class Account {
protected:
    string accountID;
    string accountPIN;
    double accountBalance;

public:
    Account(); //Default Constructor
    Account(const string &accountID, const string &accountPIN, const double &accountBalance);//Constructor that stores accountID, accountPIN, and accountBalance

    //Getters and Setters for AccountID
    string getAccountID();
    void setAccountID(const string &accountID);

    //Getters and Setters for AccountPIN
    string getAccountPIN();
    void setAccountPIN(const string &accountPIN);

    //Getters and Setters for AccountBalance
    double getAccountBalance();
    void setAccountBalance(const double &accountBalance);

    void printBalance();//Prints the Balance of the account
    void Deposit(double amt);//Deposits the Balance of the account
    void Withdraw(double amt);//Withdraw the Balance of the account

};




