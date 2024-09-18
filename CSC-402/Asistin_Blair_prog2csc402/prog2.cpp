#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Account.h"
#include "Bank.h"
using namespace std;

int main() {


    // Account account1("blair", "test", 203);
    //
    // //cout << account1.getAccountBalance() << endl;
    //
    // account1.printBalance();
    //
    // account1.Deposit(100);
    // cout << account1.getAccountBalance() << endl;
    //
    // account1.Withdraw(200);
    // cout << account1.getAccountBalance() << endl;;

    Bank bk;

    string path;

    cout << "Enter the path of the file:";
    cin >> path;

    ifstream inf (path);

    if(!inf) {
        cout << "Error opening file" << path << endl;
    }

    bk.loadAccounts(inf);


    // string s;
    //
    // while(getline(inf, s)) {
    //     cout << s << endl;
    // }

    inf.close();

    return 0;
}
