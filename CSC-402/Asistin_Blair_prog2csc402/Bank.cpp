//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#include "Bank.h"
#include <iostream>
using namespace std;

//Finds the specific account in the vector of Account objects
Account& Bank::findAcct(string id, string pin) {

    for(int i = 0; i <bank.size()-1; i++) {
        if(bank[i].getAccountID() == id && bank[i].getAccountPIN() == pin) {
            return bank[i];
        }
    }

    return dummyAccount; //returns the default constructor of Account
}

//This function adds a new account on the vector of Account objects
void Bank::addAcct(Account& acct) {

    bank.push_back(acct);

}

//This function loads and loops through the file to be added on the vector of Account objects
void Bank::loadAccounts(ifstream& inf) {

    string id;
    string pin;
    double balance;
    int countLoaded = 0; //tracks how many accounts have been loaded

    cout << "Loading Data..." << endl;

    //Loops through the file to store id, pin and balance
    while(inf >> id >> pin >> balance) {
        Account acct(id, pin, balance);
        addAcct(acct);

    }

    cout << countLoaded << " Accounts loaded." << endl;
    cout << endl;

}