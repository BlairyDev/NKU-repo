//
// Created by blairasistin on 9/17/24.
//

#include "ATM.h"

int ATM::start() {

    string selector;
    string id;
    string pin;

    cout << "Please enter your command" << endl;
    cout << "Q - quit/exit" << endl;
    cout << "L - login to account" << endl;

    cin >> selector;

    if(selector == "L") {

        cout << "Please enter Account ID:";
        cin >> id;

        cout << "Please enter Account PIN:";
        cin >> pin;

        transaction(bk.findAcct(id, pin));

        return 0;
    }
    else if(selector == "Q") {
        return 1;
    }

}

void ATM::transaction(Account& acct) {

    string selector;
    int amt;
    cout << "Please enter your selection or Q to quite" << endl;
    cout << "W - withdraw funds"  << endl;
    cout << "D - deposit funds" << endl;
    cout << "B - check balance" << endl;
    cout << "Q - quit/exit" << endl;

    switch(selector) {
        case 'W':
            cin >> amt;
            acct.Withdraw(amt);
        case 'D':
            cin >> amt;
            acct.Deposit(amt);
        case 'B':
            acct.printBalance();

    }

}
