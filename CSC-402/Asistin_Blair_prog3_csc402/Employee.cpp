//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods


#include "Employee.h"
#include "myStack.h"

//Default Constructor
Employee::Employee() {
    firstName = "";
    lastName = "";
    socsecnum = "";
    deptNum = "";
    wage = 0.0;
}

//Constructor of Employee
Employee::Employee(const string& firstName, const string& lastName, const string& socsecnum, const string& deptNum, double wage) {

    //Pass to setters
    setFirstName(firstName);
    setLastName(lastName);
    setSocsecnum(socsecnum);
    setDeptNum(deptNum);
    setWage(wage);

}

//Getters and Setters for firstName
string Employee::getFirstName() const {
    return firstName;
}
void Employee::setFirstName(const string& firstName) {
    this->firstName = firstName;
}

//Getters and Setters for lastName
string Employee::getLastName() const {
    return lastName;
}
void Employee::setLastName(const string& lastName) {
    this->lastName = lastName;
}

//Getters and Setters for socsecnum
string Employee::getSocsecnum() const {
    return socsecnum;
}
void Employee::setSocsecnum(const string& socsecnum) {
    this->socsecnum = socsecnum;
}

//Getters and Setters for deptNum
string Employee::getDeptNum() const {
    return deptNum;
}
void Employee::setDeptNum(const string& deptNum) {
    this->deptNum = deptNum;
}

//Getters and Setters for wage
double Employee::getWage() const{
    return wage;
}
void Employee::setWage(double wage) {
    this->wage = wage;
}


//Operator Overloading for "<<" operator to print vector of Employee
ostream &operator << (ostream& out, Employee& e) {

    return cout << e.getLastName() << " " << e.getFirstName() << " " << e.getSocsecnum() << " " << e.getDeptNum() << " " << e.getWage() << endl;

}

//Operator Overloading for "<" operator to sort vector of Employee
bool Employee::operator<(const Employee & other) const{

    //Return true if deptNum is less than other deptNum OR deptNum and other deptNum is equal AND lastName is less than other lastName
    if(this->deptNum < other.deptNum ||(this->deptNum == other.deptNum && this->lastName < other.lastName)) {
        return true;
    }//Checks if deptNum and other deptNUm AND lastName and other lastName are equal
    else if (this->deptNum == other.deptNum && this->lastName == other.lastName) {
        return this->firstName < other.firstName; //compare firstName and other firstName and then return
    }

    return false;
}

