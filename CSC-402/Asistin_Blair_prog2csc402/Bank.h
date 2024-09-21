//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#pragma once;
#include <vector>
#include <fstream>
#include "Account.h"


class Bank {

protected:
    vector<Account> bank; //Stores all Account objects in a vector
    Account dummyAccount = Account(); //Stores the Default constructor which has null values for the attributes

public:
    Account& findAcct(string id, string pin); //Finds the specific account on the vector of Account objects
    void addAcct(Account& acct); //Pushes the new account to the vector of Account objects
    void loadAccounts(ifstream& inf); //Loop and read through the file to store it in the vector of Account objects
};


