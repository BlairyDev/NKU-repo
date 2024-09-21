//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#include "ATM.h"

int ATM::start() {

    string selector;
    string id;
    string pin;
    int loginAttempt = 0;
    bool transactionFinished = false;

    while(!transactionFinished) {

        cout << endl;

        cout << "Please enter your command" << endl;
        cout << "Q - quit/exit" << endl;
        cout << "L - login to account" << endl;

        cin >> selector;

        if(selector == "L") {

            while(loginAttempt < 3 && !transactionFinished) {

                cout << "Please enter Account ID:";
                cin >> id;

                cout << "Please enter Account PIN:";
                cin >> pin;

                cout << endl;

                Account &bankAcct = bk.findAcct(id, pin);

                if(bankAcct.getAccountID() == "" && bankAcct.getAccountPIN() == "") {
                    cout << "Sorry - no match" << endl;
                    loginAttempt++;
                }
                else {
                    cout << "Account Found" << endl;
                    transaction(bankAcct);
                    loginAttempt = 0;
                    transactionFinished = true;
                }
            }

            if(loginAttempt == 3) {
                return 1;
            }

            transactionFinished = false;
        }
        else if(selector == "Q") {
            return 0;
        }
        else {
            cout << "Unrecognized command " << selector << endl;
        }
    }


}

void ATM::transaction(Account& acct) {

    char selector;
    int amt;
    bool exitMenu = false;

    while(exitMenu != true) {
        cout << "Please enter your selection or Q to quite" << endl;
        cout << "W - withdraw funds"  << endl;
        cout << "D - deposit funds" << endl;
        cout << "B - check balance" << endl;
        cout << "Q - quit/exit" << endl;

        cin >> selector;

        switch(selector) {
            case 'W':
                cout << "Please entera amount of withdrawal" << endl;
                cin >> amt;
                acct.Withdraw(amt);
                break;
            case 'D':
                cout << "Please entera amount of deposit" << endl;
                cin >> amt;
                acct.Deposit(amt);
                break;
            case 'B':
                acct.printBalance();
                break;
            case 'Q':
                exitMenu = true;
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unrecognized command " << selector << endl;
                break;
        }

        cout << endl;
    }
}