//
// Created by blairasistin on 9/17/24.
//

#include "Bank.h"
using namespace std;

Account& Bank::findAcct(string id, string pin) {

    for(int i = 0; i <bank.size()-1; i++) {
        if(bank[i].getAccountID() == id && bank[i].getAccountPIN() == pin) {
            return bank[i];
        }
    }

    return dummyAccount;
}
void Bank::addAcct(Account& acct) {

    bank.push_back(acct);

}

void Bank::loadAccounts(ifstream& inf) {

    string id;
    string pin;
    double balance;

    while(inf >> id >> pin >> balance) {

        Account acct(id, pin, balance);

        addAcct(acct);

    }

}