//Name: Blair Asistin
//CSC 402 Advanced Programming Methods

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

//Function Prototypes
void processData(ifstream& inf, vector<int>& CPPStack, int* CStack, int size);
void push(int* CStack, int size, int &numelts, int currentNumber);
void pop(int* CStack, int &numelts);
void top(int* CStack, int numelts);

int main() {
    string inputFilePath;
    int* CStack;
    vector<int> CPPStack;
    int size;

<<<<<<< HEAD:CSC-402/Asistin_Blair_prog1.cpp
    //Asks the user for the file name
    cout << "Enter file name:";
    cin >> inputFileName;

    inputFilePath += inputFileName; //Concatenates inputFilePath and inputFileName
    ifstream inf (inputFilePath);

=======
    //Asks the user for path of the file
    cout << "Enter path of the input file:"; // (e.g input): /home/blairasistin/CLionProjects/Asistin_Blair_prog1.cpp/t1.in
    cin >> inputFilePath;

    ifstream inf (inputFilePath);
>>>>>>> NKU-revise-repo:CSC-402/Asistin_Blair_prog1csc402/Asistin_Blair_prog1.cpp

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
<<<<<<< HEAD:CSC-402/Asistin_Blair_prog1.cpp
void processData(ifstream& inf, vector<int>& CPPStack, int* ptr_CStack, int size) {
=======
void processData(ifstream& inf, vector<int>& CPPStack, int* CStack, int size) {
>>>>>>> NKU-revise-repo:CSC-402/Asistin_Blair_prog1csc402/Asistin_Blair_prog1.cpp

    int numelts = 0; //Keeps track of the current index in CStack
    string currentCommand;
    int currentNumber;

    //The while loop condition stores the command and number in separate variables
    while(inf >> currentCommand >> currentNumber) {

        //Commands to be selected depending on the currentCommand variable
        if(currentCommand == "PUSH"){

            CPPStack.push_back(currentNumber); //pushes an element in CPPStack

<<<<<<< HEAD:CSC-402/Asistin_Blair_prog1.cpp
            push(ptr_CStack, size, numelts, currentNumber); //pushes an element in CStack
=======
            push(CStack, size, numelts, currentNumber); //pushes an element in CStack
>>>>>>> NKU-revise-repo:CSC-402/Asistin_Blair_prog1csc402/Asistin_Blair_prog1.cpp
        }
        else if(currentCommand == "POP") {

            if(CPPStack.empty()) {
                cout << "NO POP - STACK IS EMPTY" << endl;
            }
            else {
                CPPStack.pop_back();//pops an element in CPPStack
            }

<<<<<<< HEAD:CSC-402/Asistin_Blair_prog1.cpp
            pop(ptr_CStack, numelts); //pops an element in CStack
=======
            pop(CStack, numelts); //pops an element in CStack
>>>>>>> NKU-revise-repo:CSC-402/Asistin_Blair_prog1csc402/Asistin_Blair_prog1.cpp

        }
        else if(currentCommand == "TOP") {

            if(CPPStack.empty()) {
                cout << "NO TOP" << endl;
            }
            else {
                cout << CPPStack.at(CPPStack.size()-1)<< endl;//Prints the top element of CPPStack
            }

<<<<<<< HEAD:CSC-402/Asistin_Blair_prog1.cpp
            top(ptr_CStack, numelts);//Prints the top element of CStack
=======
            top(CStack, numelts);//Prints the top element of CStack
>>>>>>> NKU-revise-repo:CSC-402/Asistin_Blair_prog1csc402/Asistin_Blair_prog1.cpp

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
<<<<<<< HEAD:CSC-402/Asistin_Blair_prog1.cpp
            cout << ptr_CStack[i] << endl;
=======
            cout << CStack[i] << endl;
>>>>>>> NKU-revise-repo:CSC-402/Asistin_Blair_prog1csc402/Asistin_Blair_prog1.cpp
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
<<<<<<< HEAD:CSC-402/Asistin_Blair_prog1.cpp
        ptr_CStack[numelts-1] = 0;
=======
        CStack[numelts-1] = 0;
>>>>>>> NKU-revise-repo:CSC-402/Asistin_Blair_prog1csc402/Asistin_Blair_prog1.cpp
        numelts--;
    }
    else {
        cout << "NO POP - STACK IS EMPTY" << endl;
    }

}

//Top implementation for the CStack
<<<<<<< HEAD:CSC-402/Asistin_Blair_prog1.cpp
void top(int* ptr_CStack, int numelts) {

    if(numelts > 0) {
        cout << ptr_CStack[numelts-1] << endl;
=======
void top(int* CStack, int numelts) {

    if(numelts > 0) {
        cout << CStack[numelts-1] << endl;
>>>>>>> NKU-revise-repo:CSC-402/Asistin_Blair_prog1csc402/Asistin_Blair_prog1.cpp
    }
    else {
        cout << "NO TOP" << endl;
    }

}