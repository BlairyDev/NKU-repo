//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#pragma once
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

class myStack {
public:

    //Stores the vector of Employee objects
    vector<Employee> elts;

    //Gets the vector of Employee objects
    vector<Employee> &getElts();

    void Push(const Employee &e); //Push employee object to the vector of Employee objects
    Employee Pop(); //Pop employee object to the vector of Employee objects
    bool isempty() const; //Checks if Stack is empty
    void printStack(); //Prints vector of Employee objects

    //Operator Overloading for "+" to concatenate two Stack vector of Employee objects
    myStack operator+(const myStack& other);

};




