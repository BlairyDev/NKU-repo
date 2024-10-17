//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods

//Description:
//This program aims to implement Stack and Queue data structures without using the Standard Template Library(STL) and utilize operator overloading.
//We have an Employee class which stores data members that consist of firstName, lastName, social security number, deptNUm, and wage. It will use
//Operator overloading to print out the object using "<<" and sort the vector of Employees using a sort method with an Operator overloading "<".
//It will also include stack and queue operations to be used for vectors of Employee objects. Implementing an Operator overloading "+" which
//concatenate/merge two stacks or two queues in one temporary object.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "Employee.h"
#include "myStack.h"
#include "myQueue.h"

int main() {

    //Stores the path of input files to retrieve the files.
    string inputPath1;
    string inputPath2;

    //This is to be used when passing arguments to the Employee Constructor
    string firstName;
    string lastName;
    string socsecnum;
    string deptNum;
    double wage;

    //Asks the first inputFile Path
    cout << "Enter the path to the input file: ";
    cin >> inputPath1;

    ifstream inf1(inputPath1);

    //Checks inputPath1 if successfully retrieved
    if(!inf1) {
        cout << "Error opening file " << inputPath1 << endl;
    }

    //Asks the second inputFile Path
    cout << "Enter the path to the input file: ";
    cin >> inputPath2;

    ifstream inf2(inputPath2);

    //Checks inputPath2 if successfully retrieved
    if(!inf2) {
        cout << "Error opening file " << inputPath2 << endl;
    }

    cout << endl;

    //These objects are to be used for inputPath1 when passing arguments to the Employee constructor
    myStack S1;
    myQueue Q1;

    //Stores values in Employee constructor until input file reaches to blank line
    while(inf1 >> lastName >> firstName >> socsecnum >> deptNum >> wage) {

        Employee employee1(firstName, lastName, socsecnum, deptNum, wage);
        S1.Push(employee1);//Pushes to the stack

        Employee employee2(firstName, lastName, socsecnum, deptNum, wage);
        Q1.Enqueue(employee2);//Enqueue to the queue
    }

    //Prints the Stack of inputPath1
    cout << "STACK #1" << endl;
    cout << endl;
    S1.printStack();

    //Prints the Queue of inputPath1
    cout << "QUEUE #1" << endl;
    cout << endl;
    Q1.printQueue();

    //These objects are to be used for inputPath2 when passing arguments to the Employee constructor
    myStack S2;
    myQueue Q2;

    //Stores values in Employee constructor until input file reaches to blank line
    while(inf2 >> lastName >> firstName >> socsecnum >> deptNum >> wage) {
        Employee employee3(firstName, lastName, socsecnum, deptNum, wage);
        S2.Push(employee3);//Pushes to the stack

        Employee employee4(firstName, lastName, socsecnum, deptNum, wage);
        Q2.Enqueue(employee4);//Enqueue to the queue
    }

    //Prints the Stack of inputPath2
    cout << "STACK #2" << endl;
    cout << endl;
    S2.printStack();//

    //Prints the Queue of inputPath2
    cout << "QUEUE #2" << endl;
    cout << endl;
    Q2.printQueue();

    cout << "AFTER SORTING ALL VECTORS" << endl;
    cout << endl;

    cout << "STACK #1" << endl;
    //Sorts the S1 vector of Employee
    sort(S1.getElts().begin(), S1.getElts().end(), less<Employee>());
    S1.printStack();

    cout << "QUEUE #1" << endl;
    //Sorts the Q1 vector of Employee
    sort(Q1.getElts().begin(), Q1.getElts().end(), less<Employee>());
    Q1.printQueue();

    cout << "STACK #2" << endl;
    //Sorts the S2 vector of Employee
    sort(S2.getElts().begin(), S2.getElts().end(), less<Employee>());
    S2.printStack();

    cout << "QUEUE #2" << endl;
    //Sorts the S2 vector of Employee
    sort(Q2.getElts().begin(), Q2.getElts().end(), less<Employee>());
    Q2.printQueue();

    //STACK #3
    myStack S3;
    S3 = S1 + S2;//Combines S1 and S2

    cout << "After overloaded operator +" << endl;

    cout << endl;

    cout << "STACK #3" << endl;

    cout << endl;

    S3.printStack(); //prints S3's vector of Employee

    //QUEUE #3
    myQueue Q3;
    Q3 = Q1 + Q2;//Combines Q1 and Q2

    cout << endl;

    cout << "QUEUE #3" << endl;

    cout << endl;

    Q3.printQueue(); //PRINTS Q3's vector of Employee

    cout << "After SORTING" << endl;

    cout << endl;

    cout << "STACK #3" << endl;

    cout << endl;

    sort(S3.getElts().begin(), S3.getElts().end(), less<Employee>());
    S3.printStack();

    cout << "QUEUE #3" << endl;

    cout << endl;

    sort(Q3.getElts().begin(), Q3.getElts().end(), less<Employee>());
    Q3.printQueue();

    cout << "REMOVING ALL ITEMS FROM S2 and Q2" << endl;

    cout << endl;

    cout << "Items POPPED from Stack S2" << endl;

    cout << endl;


    int count1 = S2.elts.size(); //Gets the size of S2's vector of Employee to use for iteration

    //Pops all the S2's vector of Employee
    for(int i = 0; i < count1; i++) {
        Employee pop = S2.Pop();
        cout << "POPPING " <<  pop << endl;
    }

    //Checks if S2's vector of Employee is empty
    if(S2.isempty()) {
        cout << "ERROR - STACK IS EMPTY" << endl;
    }
    else {
        cout << "STACK IS NOT EMPTY" << endl;
    }

    cout << endl;

    cout << "Items DEQUEUED from Queue Q2" << endl;

    cout << endl;

    int count2 = Q2.elts.size(); //Gets the size of Q2's vector of Employee to use for iteration

    //Dequeue all the Q2's vector of Employee
    for(int i = 0; i < count2; i++) {
        Employee pop = Q2.Dequeue();
        cout << "POPPING " <<  pop << endl;
    }

    //Checks if the Q2's vector of Employee is empty
    if(Q2.isempty()) {
        cout << "ERROR - QUEUE IS EMPTY" << endl;
    }
    else {
        cout << "QUEUE IS NOT EMPTY" << endl;
    }

    cout << endl;

    cout << "PROGRAM EXECUTION IS COMPLETE" << endl;

    return 0;
}


