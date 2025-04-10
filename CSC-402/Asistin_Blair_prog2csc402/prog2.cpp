//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods

//Program Description:
//This is a simple Bank ATM system where the user can log in, withdraw, deposit, and check balance implemented by using C++ File/IO, Object-Oriented Programming and Header Files.
//It has an Account class which stores details of an account, a Bank Class where it maintains/store all the accounts generated by the file path provided, an ATM class that acts
//as a user interface that allows user to interact with their account by checking, depositing, or withdrawing. At the start of the program it will ask for an input path file to be
//able to fetch the file which has multiple accounts consist of an AccountID, AccountPIN, and AccountBalance.

#include <iostream>
#include <fstream>
#include <string>
#include "Bank.h"
#include "ATM.h"
using namespace std;

int main() {

    Bank bk;

    string path;

    cout << "Enter the path for information:";//Asks the user for the input file path (if file cannot be found try something like this:
    cin >> path;                          // "/home/blairasistin/CLionProjects/Asistin_Blair402prog2/test.txt)"

    ifstream inf (path);

    //Checks if file(inf) has been opened successfully
    if(!inf) {
        cout << "Error opening file" << path << endl;
    }

    //Pass the file to the Bank Class to load accounts and store it in a vector
    bk.loadAccounts(inf);

    //Passed bk to ATM class to be able to use for interactions.
    ATM atm(bk);

    //Starts the menu for user interface.
    int result = atm.start();

    switch(result) {
        case 0:
            cout << "Normal Exit";
            break;
        case 1:
            cout << "Account not found - system shutting down";
            break;
    }

    inf.close();

    return 0;
}