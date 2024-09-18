//
// Created by blairasistin on 9/17/24.
//

#include "Bank.h"
using namespace std;

Account& Bank::findAcct(string id, string pin) {

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