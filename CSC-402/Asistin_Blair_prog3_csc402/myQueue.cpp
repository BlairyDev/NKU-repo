//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods

#include "myQueue.h"

//Gets the vector of Employee objects
vector<Employee>&  myQueue::getElts() {
    return elts;
}

//Enqueue an object to the vector
void myQueue::Enqueue(const Employee &e) {
    elts.push_back(e);
}

//Dequeue the vector and then return the object you have dequeue
Employee myQueue::Dequeue() {

    Employee e = elts.front();

    elts.erase(elts.begin());

    return e;
}

//Check if queue is empty
bool myQueue::isempty() {
    return elts.empty();
}

//Prints vector of Employee objects
void myQueue::printQueue() {
    for (auto it = elts.begin(); it != elts.end(); ++it) {
        cout << *it << endl;
    }
}

//Operator Overloading for "+" to concatenate two Stack vector of Employee objects
myQueue myQueue::operator+(const myQueue &other) {

    myQueue temp; //Creates a temporary myQueue object to be returned after concatenating

    //Stores first Stack's vector of Employee objects to the temp
    for(auto it = this->elts.begin(); it != this->elts.end(); ++it) {
        temp.Enqueue(*it);
    }

    //Stores second Stack's vector of Employee objects to the temp
    for(auto it = other.elts.begin(); it != other.elts.end(); ++it) {
        temp.Enqueue(*it);
    }

    return temp;
}
