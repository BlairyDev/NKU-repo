#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Account.h"
#include "Bank.h"
#include "ATM.h"
using namespace std;

int main() {

    Bank bk;

    string path;

    cout << "Enter the path of the file:";
    cin >> path;

    ifstream inf (path);

    if(!inf) {
        cout << "Error opening file" << path << endl;
    }

    bk.loadAccounts(inf);

    ATM atm(bk);

    int result = atm.start();

    inf.close();

    return 0;
}
