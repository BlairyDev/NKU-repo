//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#include "myStack.h"

//Gets the vector of Employee objects
vector<Employee>&  myStack::getElts() {
    return elts;
}

//Push employee object to the vector of Employee objects
void myStack::Push(const Employee &e) {

    elts.push_back(e);//Push one object to the vector of Employee objects
}

//Pop employee object to the vector of Employee objects
Employee myStack::Pop() {

    Employee e = elts.back(); //Stores the top object of the vector of Employees objects and then return

    elts.pop_back();//Pops one object to the vector of Employee objects

    return e;
}

//Checks if Stack is empty
bool myStack::isempty() const {

    //return true if empty
    if(elts.empty()) {
        return true;
    }

    return false; //return false if not empty

}

//Prints vector of Employee objects
void myStack::printStack() {

    if(elts.empty()) {
        cout << "ERROR - STACK IS EMPTY" << endl;
    }
    else {
        for(auto it = elts.rbegin(); it != elts.rend(); ++it) {
            cout << *it << endl;
        }
    }

}

//Operator Overloading for "+" to concatenate two Stack vector of Employee objects
myStack myStack::operator+(const myStack &other) {

    myStack temp; //Creates a temporary myStack object to be returned after concatenating

    //Stores first Stack's vector of Employee objects to the temp
    for(auto it = this->elts.rbegin(); it != this->elts.rend(); ++it) {
        temp.Push(*it);
    }

    //Stores second Stack's vector of Employee objects to the temp
    for(auto it = other.elts.rbegin(); it != other.elts.rend(); ++it) {
        temp.Push(*it);
    }

    return temp;
}

