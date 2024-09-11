#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

//Header
void processData(ifstream& inf, vector<int>& CPPStack, int* CStack, int size);
void push(int*Cstack, int size, int &numelts, int currentNumber);

int main() {
    cout<< "Hello World!"<<endl;
    string inputFilePath = "C:/Users/Rania/CLionProjects/Asistin_Blair_prog1.cpp/";
    string inputFileName;
    int* CStack;
    vector<int> CPPStack {10, 12, 13};

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

    string s;
    while(getline(inf, s)) {
        cout << s << endl;
    }

    //Gets the very first line of file which is the inputSize of CStack
    inf >> size;

    CStack = (int*)malloc(size * sizeof(int));

    processData(inf, CPPStack, CStack, size);

    inf.close();
    return 0;
}

void processData(ifstream& inf, vector<int>& CPPStack, int* CStack, int size) {

    int numelts = 0; //Keeps track the current index in CStack

    string currentCommand;
    int currentNumber;

    //The condition stores the command and number in seperate variables
    while(inf >> currentCommand >> currentNumber) {

        if(currentCommand == "PUSH"){

            CPPStack.push_back(currentNumber);

            push(CStack, size, numelts, currentNumber);

        }
        else if(currentCommand == "POP") {

        }
        else if(currentCommand == "TOP") {

        }
        else if(currentCommand == " ") {
        }
    }

}

void push(int*CStack, int size, int &numelts, int currentNumber) {

}
