//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods

#pragma once
#include <string>
#include <vector>
#include "Employee.h"
using namespace std;



class myQueue {
public:
    vector<Employee> elts; //Vector of Employee objects

    vector<Employee> &getElts(); //Gets the vector of Employee objects

    void Enqueue(Employee const &e); //Enqueue an object ot the vector
    Employee Dequeue(); //Dequeue the vector and then return the object you have dequeue
    bool isempty(); //Check if queue is empty
    void printQueue(); //Prints vector of Employee objects

    //Operator Overloading for "+" to concatenate two Stack vector of Employee objects
    myQueue operator+(const myQueue& other );

};





