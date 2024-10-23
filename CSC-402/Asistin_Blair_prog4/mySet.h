//
// Created by blairasistin on 10/21/24.
//

#pragma once
#include <iostream>
#include <vector>
using namespace std;

class mySet {
protected:
    vector<int> elts;
    int size = 0;

public:

    mySet();

    bool isempty();
    bool isfound(int x);
    bool addelt(int x);
    bool deleteelt(int x);

    vector <int> & getelts();
    void setelts(const vector<int> & S);
    int getsize();

    mySet Union(mySet & S);
    mySet Intersection(mySet & S);
    mySet Difference(mySet & S);


    friend ostream & operator << (ostream& ost, mySet &S);
    bool operator == (mySet &other);


};



