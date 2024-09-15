//Name: Blair Asistin
//CSC 402 Advanced Programming Methods

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

//Function Prototypes
void processData(ifstream& inf, vector<int>& CPPStack, int* ptr_CStack, int size);
void push(int* ptr_CStack, int size, int &numelts, int currentNumber);
void pop(int* ptr_CStack, int &numelts);
void top(int* ptr_CStack, int numelts);

int main() {
    string inputFilePath;
    int* CStack;
    vector<int> CPPStack;
    int size;

    //Asks the user for path of the file
    cout << "Enter path of the input file:"; // (e.g input): /home/blairasistin/CLionProjects/Asistin_Blair_prog1.cpp/t1.in
    cin >> inputFilePath;

    ifstream inf (inputFilePath);

    //Checks whether file successfully opened or not
    if(!inf) {
        cout << "Error opening file " << inputFilePath;
        return -1;
    }

    //Gets the very first line of file which is the inputSize of CStack and store it in size variable.
    inf >> size;

    CStack = (int*)malloc(size * sizeof(int));

    processData(inf, CPPStack, CStack, size);

    inf.close();
    delete CStack; //deallocate memory to prevent memory leaks

    return 0;
}

//Determines what command to use and execute
void processData(ifstream& inf, vector<int>& CPPStack, int* ptr_CStack, int size) {

    int numelts = 0; //Keeps track of the current index in CStack
    string currentCommand;
    int currentNumber;

    //The while loop condition stores the command and number in separate variables
    while(inf >> currentCommand >> currentNumber) {

        //Commands to be selected depending on the currentCommand variable
        if(currentCommand == "PUSH"){

            CPPStack.push_back(currentNumber); //pushes an element in CPPStack

            push(ptr_CStack, size, numelts, currentNumber); //pushes an element in CStack
        }
        else if(currentCommand == "POP") {

            if(CPPStack.empty()) {
                cout << "NO POP - STACK IS EMPTY" << endl;
            }
            else {
                CPPStack.pop_back();//pops an element in CPPStack
            }

            pop(ptr_CStack, numelts); //pops an element in CStack

        }
        else if(currentCommand == "TOP") {

            if(CPPStack.empty()) {
                cout << "NO TOP" << endl;
            }
            else {
                cout << CPPStack.at(CPPStack.size()-1)<< endl;//Prints the top element of CPPStack
            }

            top(ptr_CStack, numelts);//Prints the top element of CStack

        }
    }

    cout << endl;

    //Prints CPPStack
    cout << "CPPStack" << endl;
    if(CPPStack.empty()) {
        cout << "STACK IS EMPTY" << endl;
    }
    else {
        for(auto rit = CPPStack.rbegin(); rit != CPPStack.rend(); ++rit) {
            cout << *rit << endl;
        }
    }

    cout << endl;

    //Prints CStack
    cout << "CSTACK" << endl;
    if(numelts == 0) {
        cout << "STACK IS EMPTY";
    }
    else{
        for(int i = numelts-1; i >= 0; i--) {
            cout << ptr_CStack[i] << endl;
        }
    }

}

//Push implementation for the CStack
void push(int* ptr_CStack, int size, int &numelts, int currentNumber) {

    if(numelts < size) {
        *(ptr_CStack+numelts) = currentNumber; //adding current size and CStack can obtain current index of CStack
        numelts++;
    }
    else {
        cout << "NO PUSH - STACK IS EMPTY" << endl;
    }

}

//Pop implementation for CStack
void pop(int* ptr_CStack, int &numelts) {

    if(numelts > 0) {
        ptr_CStack[numelts-1] = 0;
        numelts--;
    }
    else {
        cout << "NO POP - STACK IS EMPTY" << endl;
    }

}

//Top implementation for the CStack
void top(int* ptr_CStack, int numelts) {

    if(numelts > 0) {
        cout << ptr_CStack[numelts-1] << endl;
    }
    else {
        cout << "NO TOP" << endl;
    }

}