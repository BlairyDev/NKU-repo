//Name: Blair Asistin
//Course: CSC 402 Advanced Programming Methods

#pragma once

#include <string>
#include <iostream>

using namespace std;


class Employee {

protected:
    string firstName;
    string lastName;
    string socsecnum;
    string deptNum;
    double wage;

public:

    Employee();//Default constructor

    //Employee Constructor
    Employee(const string& firstName, const string& lastName, const string& socsecnum, const string& deptNum, double wage);


    //Getters and Setters of firstName
    string getFirstName() const;
    void setFirstName(const string& firstName);

    //Getters and Setters of lastName
    string getLastName() const;
    void setLastName(const string& lastName);

    //Getters and Setters of socsecnum
    string getSocsecnum() const;
    void setSocsecnum(const string& socsecnum);

    //Getters and Setters of deptNum
    string getDeptNum() const;
    void setDeptNum(const string& deptNum);

    //Getters and Setters of wage
    double getWage() const;
    void setWage(double wage);

    //Operator Overloading for "<<" operator to print vector of Employee
    friend ostream &operator << (ostream& out, Employee& e);

    //Operator Overloading for "<" operator to sort vector of Employee
    bool operator<(const Employee & other) const;

};







