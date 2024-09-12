#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

//Header
void processData(ifstream& inf, vector<int>& CPPStack, int* CStack, int size);
void push(int*CStack, int size, int &numelts, int currentNumber);
void pop(int*CStack, int &numelts);
void top(int*CStack, int numelts);

int main() {

    string inputFilePath = "/home/blairasistin/CLionProjects/Asistin_Blair_prog1.cpp/"; //If file cannot be found change path
    string inputFileName;
    int* CStack;
    vector<int> CPPStack;
    int size;

    //Asks the user for the file name
    cout << "Enter file name:";
    cin >> inputFileName;

    inputFilePath += inputFileName;

    ifstream inf (inputFilePath);
    inf.is_open();

    if(!inf) {
        cout << "Error opening file " << inputFilePath;
        return -1;
    }

    //Gets the very first line of file which is the inputSize of CStack
    inf >> size;

    CStack = (int*)malloc(size * sizeof(int));

    processData(inf, CPPStack, CStack, size);

    inf.close();
    delete CStack; //deallocate memory to prevent memory leaks

    return 0;
}

void processData(ifstream& inf, vector<int>& CPPStack, int* CStack, int size) {

    int numelts = 0; //Keeps track the current index in CStack
    string currentCommand;
    int currentNumber;

    //The while loop condition stores the command and number in separate variables
    while(inf >> currentCommand >> currentNumber) {

        if(currentCommand == "PUSH"){

            CPPStack.push_back(currentNumber);

            push(CStack, size, numelts, currentNumber);
        }
        else if(currentCommand == "POP") {

            if(CPPStack.empty()) {
                cout << "NO POP - STACK IS EMPTY" << endl;
            }
            else {
                CPPStack.pop_back();
            }

            pop(CStack, numelts);

        }
        else if(currentCommand == "TOP") {

            if(CPPStack.empty()) {
                cout << "NO TOP" << endl;
            }
            else {
                cout << CPPStack[CPPStack.size()-1]<< endl;
            }

            top(CStack, numelts);
        }
    }

    for(int i = 0; i < numelts; i++) {
        cout << *(CStack + i) << endl;
    }
}

//Push implementation for the CStack
void push(int* CStack, int size, int &numelts, int currentNumber) {

    if(numelts < size) {
        *(CStack+numelts) = currentNumber; //adding current size and CStack can obtain current index of CStack
        numelts++;
    }
    else {
        cout << "NO POP - STACK IS EMPTY" << endl;
    }

}

//Pop implementation for CStack
void pop(int* CStack, int &numelts) {

    if(numelts == 0) {
        cout << "NO POP - STACK IS EMPTY" << endl;
    }
    else {
        CStack--; //By decrementing the CStack resulting to removing the last element to the stack.
        numelts--;
    }

}

//Top implementation for the CStack
void top(int*CStack, int numelts) {

    if(numelts == 0) {
        cout << "NO TOP" << endl;
    }
    else {
        cout << *(CStack + numelts-1) << endl;
    }

}